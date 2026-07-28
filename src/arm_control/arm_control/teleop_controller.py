"""
Teleop Controller for the Surgical Cleaning Robot Project.
written by Connor McKelvey Summer 2026 | connormckelvey@utexas.edu

Controls the robot using the wrist position relative to the shoulder.
lowk doesnt work at all
PoseArray order:
    shoulder, elbow, wrist, hand
"""

import math

import cv2 as cv
import numpy as np
import rclpy
from geometry_msgs.msg import Pose, PoseArray, Quaternion
from rclpy.node import Node
from sensor_msgs.msg import Image


class TeleopControllerNode(Node):
    def __init__(self):
        super().__init__('teleop_controller')

        self.declare_parameter('control_rate_hz', 50.0)
        self.declare_parameter('robot_arm_length', 0.30)

        self.control_rate_hz = self.get_parameter('control_rate_hz').value
        self.robot_arm_length = self.get_parameter('robot_arm_length').value

        self.latest_image = None
        self.latest_arm_pose = None
        self.teleop_enabled = False

        self.target_pose_pub = self.create_publisher(
            Pose,
            'arm/target_cartesian_pose',
            1
        )

        self.arm_pose_sub = self.create_subscription(
            PoseArray,
            'camera/human_arm_pose',
            self.arm_pose_callback,
            1
        )

        self.image_sub = self.create_subscription(
            Image,
            'camera/image_raw',
            self.image_callback,
            10
        )

        self.teleop_timer = self.create_timer(
            1.0 / self.control_rate_hz,
            self.teleop_callback
        )

        cv.namedWindow('Teleop Controller')

        self.get_logger().info(
            "Press 's' to enable teleop, 'r' to disable it, or 'q' to quit."
        )

    def arm_pose_callback(self, msg):
        # PoseArray order: shoulder, elbow, wrist, hand.
        if len(msg.poses) < 4:
            return

        self.latest_arm_pose = msg

    def image_callback(self, msg):
        try:
            self.latest_image = self.image_msg_to_bgr(msg)
        except Exception as error:
            self.get_logger().error(f'Failed to decode image: {error}')

    def image_msg_to_bgr(self, msg):
        encoding = msg.encoding.lower()

        channel_counts = {
            'mono8': 1,
            '8uc1': 1,
            'rgb8': 3,
            'bgr8': 3,
            'rgba8': 4,
            'bgra8': 4
        }

        if encoding not in channel_counts:
            raise ValueError(f'Unsupported image encoding: {msg.encoding}')

        channels = channel_counts[encoding]

        raw = np.frombuffer(msg.data, dtype=np.uint8)
        rows = raw.reshape(msg.height, msg.step)
        image_data = rows[:, :msg.width * channels]

        if channels == 1:
            image = image_data.reshape(msg.height, msg.width)
        else:
            image = image_data.reshape(msg.height, msg.width, channels)

        if encoding in ('mono8', '8uc1'):
            return cv.cvtColor(image, cv.COLOR_GRAY2BGR)

        if encoding == 'rgb8':
            return cv.cvtColor(image, cv.COLOR_RGB2BGR)

        if encoding == 'rgba8':
            return cv.cvtColor(image, cv.COLOR_RGBA2BGR)

        if encoding == 'bgra8':
            return cv.cvtColor(image, cv.COLOR_BGRA2BGR)

        return image.copy()

    def teleop_callback(self):
        self.display_camera_image()

        if not self.teleop_enabled or self.latest_arm_pose is None:
            return

        shoulder = self.latest_arm_pose.poses[0].position
        elbow = self.latest_arm_pose.poses[1].position
        wrist = self.latest_arm_pose.poses[2].position

        upper_arm_length = self.point_distance(shoulder, elbow)
        forearm_length = self.point_distance(elbow, wrist)
        full_arm_length = upper_arm_length + forearm_length

        if full_arm_length <= 0.0:
            return

        normalized_wrist_x = (wrist.x - shoulder.x) / full_arm_length
        normalized_wrist_y = (wrist.y - shoulder.y) / full_arm_length
        normalized_wrist_z = (wrist.z - shoulder.z) / full_arm_length

        target_pose = Pose()

        # Scale the normalized human arm vector to the robot arm length.
        target_pose.position.x = -normalized_wrist_y * self.robot_arm_length
        target_pose.position.y = normalized_wrist_x * self.robot_arm_length
        target_pose.position.z = normalized_wrist_z * self.robot_arm_length

        if target_pose.position.z <= 0:
            target_pose.position.z = 0.10

        # Always point the end effector downward.
        target_pose.orientation = Quaternion(
            x=1.0,
            y=0.0,
            z=0.0,
            w=0.0
        )

        self.target_pose_pub.publish(target_pose)

    def display_camera_image(self):
        if self.latest_image is None:
            return

        display_image = self.latest_image.copy()

        if self.teleop_enabled:
            status = 'Teleop Active | R: Stop | Q: Quit'
        else:
            status = 'S: Start Teleop | Q: Quit'

        cv.putText(
            display_image,
            status,
            (20, 40),
            cv.FONT_HERSHEY_SIMPLEX,
            0.8,
            (0, 255, 0),
            2
        )

        cv.imshow('Teleop Controller', display_image)

        key = cv.waitKey(1) & 0xFF

        if key == ord('s'):
            self.teleop_enabled = True
            self.get_logger().info('Teleop enabled.')

        elif key == ord('r'):
            self.teleop_enabled = False
            self.get_logger().info('Teleop disabled.')

        elif key == ord('q'):
            self.get_logger().info('Closing teleop controller.')
            rclpy.shutdown()

    @staticmethod
    def point_distance(point_a, point_b):
        return math.sqrt(
            (point_a.x - point_b.x) ** 2
            + (point_a.y - point_b.y) ** 2
            + (point_a.z - point_b.z) ** 2
        )

    def destroy_node(self):
        cv.destroyAllWindows()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = TeleopControllerNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()

        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()