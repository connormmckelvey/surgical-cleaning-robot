#!/usr/bin/env python3
"""
Training data visualization node for the Surgical Arm ROS 2 project.
Written by Connor McKelvey, 2026.

all this does is take the topics and convert them into markers for pretty visualizations in rviz2
to see them run `ros2 run rviz2 rviz2` and add the topic `training/visualization_markers` as a MarkerArray display and ensure your frame is
set to the zed_camera_frame. rviz2 is an awesome tool, use it! This script was made quickly with AI and might have bugs more mistakes.
I BELIEVE THE TARGET MARKERS ORIENTATION IS HARDCODED SOMEWHERE AND IS INCORRECT

Visualizes:
- Surface centroid and normal
- Spill centroid and normal
- Camera tag pose
- Force sensor reading
- Cartesian arm target transformed back into the camera frame

Expected topics:
    training/surface_spill_info    arm_control_interfaces/msg/GetSurfaceInfo
    camera/tag_pose                geometry_msgs/msg/PoseStamped
    force_sensor/data              diagnostic_msgs/msg/DiagnosticStatus
    arm/target_cartesian_pose      geometry_msgs/msg/Pose

Published topic:
    training/visualization_markers visualization_msgs/msg/MarkerArray
"""

import math

import numpy as np
import rclpy
import yaml

from arm_control_interfaces.msg import GetSurfaceInfo
from diagnostic_msgs.msg import DiagnosticStatus
from geometry_msgs.msg import Point, Pose, PoseStamped, Quaternion
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, HistoryPolicy, QoSProfile, ReliabilityPolicy
from std_msgs.msg import ColorRGBA
from visualization_msgs.msg import Marker, MarkerArray


CALIBRATION_YAML = 'cam2base_calibration.yaml'


class TrainingVisualizationNode(Node):

    def __init__(self):
        super().__init__('training_visualization')

        self.declare_parameter('surface_info_topic', 'training/surface_spill_info')
        self.declare_parameter('tag_pose_topic', 'camera/tag_pose')
        self.declare_parameter('force_topic', 'force_sensor/data')
        self.declare_parameter('target_pose_topic', 'arm/target_cartesian_pose')
        self.declare_parameter('marker_topic', 'training/visualization_markers')
        self.declare_parameter('fallback_frame', 'zed_camera_frame')

        self.declare_parameter('normal_length', 0.15)
        self.declare_parameter('tag_axis_length', 0.10)
        self.declare_parameter('centroid_scale', 0.035)
        self.declare_parameter('normal_shaft_width', 0.01)
        self.declare_parameter('tag_axis_width', 0.008)
        self.declare_parameter('force_text_height', 0.04)
        self.declare_parameter('force_text_offset', 0.10)
        self.declare_parameter('publish_rate', 10.0)

        self.surface_info_topic = self.get_parameter('surface_info_topic').value
        self.tag_pose_topic = self.get_parameter('tag_pose_topic').value
        self.force_topic = self.get_parameter('force_topic').value
        self.target_pose_topic = self.get_parameter('target_pose_topic').value
        self.marker_topic = self.get_parameter('marker_topic').value
        self.fallback_frame = self.get_parameter('fallback_frame').value

        self.normal_length = float(self.get_parameter('normal_length').value)
        self.tag_axis_length = float(self.get_parameter('tag_axis_length').value)
        self.centroid_scale = float(self.get_parameter('centroid_scale').value)
        self.normal_shaft_width = float(self.get_parameter('normal_shaft_width').value)
        self.tag_axis_width = float(self.get_parameter('tag_axis_width').value)
        self.force_text_height = float(self.get_parameter('force_text_height').value)
        self.force_text_offset = float(self.get_parameter('force_text_offset').value)
        self.publish_rate = float(self.get_parameter('publish_rate').value)

        self.rotation_cam_to_base, self.translation_cam_to_base = self.load_calibration()

        playback_qos = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
        )

        marker_qos = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=1,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
        )

        self.marker_pub = self.create_publisher(
            MarkerArray,
            self.marker_topic,
            marker_qos,
        )

        self.surface_info_sub = self.create_subscription(
            GetSurfaceInfo,
            self.surface_info_topic,
            self.surface_info_callback,
            10,
        )

        self.tag_pose_sub = self.create_subscription(
            PoseStamped,
            self.tag_pose_topic,
            self.tag_pose_callback,
            playback_qos,
        )

        self.force_sub = self.create_subscription(
            DiagnosticStatus,
            self.force_topic,
            self.force_callback,
            playback_qos,
        )

        self.target_pose_sub = self.create_subscription(
            Pose,
            self.target_pose_topic,
            self.target_pose_callback,
            playback_qos,
        )

        self.latest_surface_info = None
        self.latest_tag_pose = None
        self.latest_force_newtons = None
        self.latest_target_pose = None

        timer_period = 1.0 / max(self.publish_rate, 0.1)
        self.publish_timer = self.create_timer(timer_period, self.publish_markers)

        self.get_logger().info(
            f'Listening for surface information on "{self.surface_info_topic}"'
        )
        self.get_logger().info(
            f'Listening for tag poses on "{self.tag_pose_topic}"'
        )
        self.get_logger().info(
            f'Listening for force sensor data on "{self.force_topic}"'
        )
        self.get_logger().info(
            f'Listening for arm targets on "{self.target_pose_topic}"'
        )
        self.get_logger().info(
            f'Publishing RViz markers on "{self.marker_topic}"'
        )

    def load_calibration(self):
        with open(CALIBRATION_YAML, 'r') as file:
            calibration = yaml.safe_load(file)['cam2base']

        rotation = np.array(
            calibration['rotation_matrix'],
            dtype=np.float64,
        )

        translation = np.array(
            calibration['translation_m'],
            dtype=np.float64,
        ).reshape(3)

        return rotation, translation

    def surface_info_callback(self, msg):
        if not msg.success:
            self.get_logger().warning(
                'Received unsuccessful surface/spill detection result.'
            )

        self.latest_surface_info = msg
        self.publish_markers()

    def tag_pose_callback(self, msg):
        self.latest_tag_pose = msg
        self.publish_markers()

    def target_pose_callback(self, msg):
        self.latest_target_pose = msg
        self.publish_markers()

    def force_callback(self, msg):
        force_value = self.get_diagnostic_value(msg, 'newtons')

        if force_value is None:
            self.get_logger().warning(
                'Received force sensor data without a valid "newtons" value.'
            )
            return

        try:
            self.latest_force_newtons = float(force_value)
        except ValueError:
            self.get_logger().warning(
                f'Could not convert force value "{force_value}" to a float.'
            )
            return

        self.publish_markers()

    def publish_markers(self):
        marker_array = MarkerArray()

        if self.latest_surface_info is not None:
            marker_array.markers.extend(
                self.create_surface_spill_markers(self.latest_surface_info)
            )

        if self.latest_tag_pose is not None:
            marker_array.markers.extend(
                self.create_tag_markers(self.latest_tag_pose)
            )

        if self.latest_target_pose is not None:
            marker_array.markers.extend(
                self.create_target_markers(self.latest_target_pose)
            )

        if self.latest_force_newtons is not None:
            marker_array.markers.append(
                self.create_force_marker()
            )

        if marker_array.markers:
            self.marker_pub.publish(marker_array)

    def create_surface_spill_markers(self, msg):
        frame_id = msg.point_cloud.header.frame_id or self.fallback_frame

        return [
            self.create_sphere_marker(
                0,
                'surface_centroid',
                frame_id,
                msg.surface_centroid,
                self.centroid_scale,
                self.make_color(0.0, 1.0, 0.0, 1.0),
            ),
            self.create_normal_marker(
                1,
                'surface_normal',
                frame_id,
                msg.surface_centroid,
                msg.surface_normal,
                self.normal_length,
                self.make_color(0.0, 1.0, 0.0, 1.0),
            ),
            self.create_text_marker(
                2,
                'surface_label',
                frame_id,
                msg.surface_centroid,
                'Surface',
                self.make_color(0.0, 1.0, 0.0, 1.0),
                self.centroid_scale,
                self.centroid_scale * 1.5,
            ),
            self.create_sphere_marker(
                3,
                'spill_centroid',
                frame_id,
                msg.spill_centroid,
                self.centroid_scale,
                self.make_color(1.0, 0.0, 0.0, 1.0),
            ),
            self.create_normal_marker(
                4,
                'spill_normal',
                frame_id,
                msg.spill_centroid,
                msg.spill_normal,
                self.normal_length,
                self.make_color(1.0, 0.0, 0.0, 1.0),
            ),
            self.create_text_marker(
                5,
                'spill_label',
                frame_id,
                msg.spill_centroid,
                'Spill',
                self.make_color(1.0, 0.0, 0.0, 1.0),
                self.centroid_scale,
                self.centroid_scale * 1.5,
            ),
        ]

    def create_tag_markers(self, msg):
        frame_id = msg.header.frame_id or self.fallback_frame
        tag_position = msg.pose.position

        rotation_matrix = np.array(
            self.quaternion_to_rotation_matrix(
                msg.pose.orientation.x,
                msg.pose.orientation.y,
                msg.pose.orientation.z,
                msg.pose.orientation.w,
            )
        )

        return [
            self.create_cube_marker(
                10,
                'tag_origin',
                frame_id,
                msg.pose,
                self.centroid_scale,
                self.make_color(1.0, 1.0, 0.0, 1.0),
            ),
            self.create_axis_marker(
                11,
                'tag_x_axis',
                frame_id,
                tag_position,
                rotation_matrix[:, 0],
                self.tag_axis_length,
                self.make_color(1.0, 0.0, 0.0, 1.0),
            ),
            self.create_axis_marker(
                12,
                'tag_y_axis',
                frame_id,
                tag_position,
                rotation_matrix[:, 1],
                self.tag_axis_length,
                self.make_color(0.0, 1.0, 0.0, 1.0),
            ),
            self.create_axis_marker(
                13,
                'tag_z_axis',
                frame_id,
                tag_position,
                rotation_matrix[:, 2],
                self.tag_axis_length,
                self.make_color(0.0, 0.0, 1.0, 1.0),
            ),
            self.create_text_marker(
                14,
                'tag_label',
                frame_id,
                tag_position,
                'Tag',
                self.make_color(1.0, 1.0, 0.0, 1.0),
                self.centroid_scale,
                self.centroid_scale * 1.5,
            ),
        ]

    def create_target_markers(self, msg):
        position_base = np.array([
            msg.position.x,
            msg.position.y,
            msg.position.z,
        ], dtype=np.float64) / 1000.0

        position_camera = self.rotation_cam_to_base.T @ (
            position_base - self.translation_cam_to_base
        )

        rotation_target_base = np.array(
            self.quaternion_to_rotation_matrix(
                msg.orientation.x,
                msg.orientation.y,
                msg.orientation.z,
                msg.orientation.w,
            )
        )

        rotation_target_camera = (
            self.rotation_cam_to_base.T @ rotation_target_base
        )

        pose_camera = Pose()
        pose_camera.position.x = float(position_camera[0])
        pose_camera.position.y = float(position_camera[1])
        pose_camera.position.z = float(position_camera[2])
        pose_camera.orientation = self.rotation_matrix_to_quaternion(
            rotation_target_camera
        )

        return [
            self.create_cube_marker(
                30,
                'target_pose',
                self.fallback_frame,
                pose_camera,
                self.centroid_scale * 1.5,
                self.make_color(1.0, 0.0, 1.0, 1.0),
            ),
            self.create_axis_marker(
                31,
                'target_x_axis',
                self.fallback_frame,
                pose_camera.position,
                rotation_target_camera[:, 0],
                self.tag_axis_length,
                self.make_color(1.0, 0.0, 0.0, 1.0),
            ),
            self.create_axis_marker(
                32,
                'target_y_axis',
                self.fallback_frame,
                pose_camera.position,
                rotation_target_camera[:, 1],
                self.tag_axis_length,
                self.make_color(0.0, 1.0, 0.0, 1.0),
            ),
            self.create_axis_marker(
                33,
                'target_z_axis',
                self.fallback_frame,
                pose_camera.position,
                rotation_target_camera[:, 2],
                self.tag_axis_length,
                self.make_color(0.0, 0.0, 1.0, 1.0),
            ),
            self.create_text_marker(
                34,
                'target_label',
                self.fallback_frame,
                pose_camera.position,
                'Arm Target',
                self.make_color(1.0, 0.0, 1.0, 1.0),
                self.centroid_scale,
                self.centroid_scale * 2.0,
            ),
        ]

    def create_force_marker(self):
        if self.latest_tag_pose is not None:
            frame_id = self.latest_tag_pose.header.frame_id or self.fallback_frame
            force_position = self.copy_point(
                self.latest_tag_pose.pose.position
            )

        elif self.latest_surface_info is not None:
            frame_id = (
                self.latest_surface_info.point_cloud.header.frame_id
                or self.fallback_frame
            )
            force_position = self.copy_point(
                self.latest_surface_info.surface_centroid
            )

        else:
            frame_id = self.fallback_frame
            force_position = Point()

        force_text = f'Force: {self.latest_force_newtons:.3f} N'

        return self.create_text_marker(
            20,
            'force_sensor',
            frame_id,
            force_position,
            force_text,
            self.get_force_color(self.latest_force_newtons),
            self.force_text_height,
            self.force_text_offset,
        )

    def create_sphere_marker(self, marker_id, namespace, frame_id, position, scale, color):
        marker = self.create_base_marker(
            marker_id,
            namespace,
            frame_id,
            Marker.SPHERE,
        )

        marker.pose.position = position
        marker.pose.orientation.w = 1.0
        marker.scale.x = scale
        marker.scale.y = scale
        marker.scale.z = scale
        marker.color = color

        return marker

    def create_cube_marker(self, marker_id, namespace, frame_id, pose, scale, color):
        marker = self.create_base_marker(
            marker_id,
            namespace,
            frame_id,
            Marker.CUBE,
        )

        marker.pose = pose
        marker.scale.x = scale
        marker.scale.y = scale
        marker.scale.z = scale
        marker.color = color

        return marker

    def create_normal_marker(self, marker_id, namespace, frame_id, centroid, normal, length, color):
        normal_vector = self.normalize_vector(
            normal.x,
            normal.y,
            normal.z,
        )

        end_point = Point()
        end_point.x = centroid.x + normal_vector[0] * length
        end_point.y = centroid.y + normal_vector[1] * length
        end_point.z = centroid.z + normal_vector[2] * length

        return self.create_arrow_marker(
            marker_id,
            namespace,
            frame_id,
            centroid,
            end_point,
            self.normal_shaft_width,
            color,
        )

    def create_axis_marker(self, marker_id, namespace, frame_id, origin, direction, length, color):
        end_point = Point()
        end_point.x = origin.x + float(direction[0]) * length
        end_point.y = origin.y + float(direction[1]) * length
        end_point.z = origin.z + float(direction[2]) * length

        return self.create_arrow_marker(
            marker_id,
            namespace,
            frame_id,
            origin,
            end_point,
            self.tag_axis_width,
            color,
        )

    def create_arrow_marker(self, marker_id, namespace, frame_id, start, end, width, color):
        marker = self.create_base_marker(
            marker_id,
            namespace,
            frame_id,
            Marker.ARROW,
        )

        marker.points = [
            self.copy_point(start),
            self.copy_point(end),
        ]

        marker.scale.x = width
        marker.scale.y = width * 2.0
        marker.scale.z = width * 2.5
        marker.color = color

        return marker

    def create_text_marker(self, marker_id, namespace, frame_id, position, text, color, text_height, vertical_offset):
        marker = self.create_base_marker(
            marker_id,
            namespace,
            frame_id,
            Marker.TEXT_VIEW_FACING,
        )

        marker.pose.position.x = position.x
        marker.pose.position.y = position.y
        marker.pose.position.z = position.z + vertical_offset
        marker.pose.orientation.w = 1.0
        marker.scale.z = text_height
        marker.color = color
        marker.text = text

        return marker

    def create_base_marker(self, marker_id, namespace, frame_id, marker_type):
        marker = Marker()

        marker.header.frame_id = frame_id
        marker.header.stamp = self.get_clock().now().to_msg()

        marker.ns = namespace
        marker.id = marker_id
        marker.type = marker_type
        marker.action = Marker.ADD

        marker.lifetime.sec = 0
        marker.lifetime.nanosec = 0

        return marker

    def quaternion_to_rotation_matrix(self, x, y, z, w):
        magnitude = math.sqrt(x * x + y * y + z * z + w * w)

        if magnitude < 1e-12:
            return [
                [1.0, 0.0, 0.0],
                [0.0, 1.0, 0.0],
                [0.0, 0.0, 1.0],
            ]

        x /= magnitude
        y /= magnitude
        z /= magnitude
        w /= magnitude

        return [
            [
                1.0 - 2.0 * (y * y + z * z),
                2.0 * (x * y - z * w),
                2.0 * (x * z + y * w),
            ],
            [
                2.0 * (x * y + z * w),
                1.0 - 2.0 * (x * x + z * z),
                2.0 * (y * z - x * w),
            ],
            [
                2.0 * (x * z - y * w),
                2.0 * (y * z + x * w),
                1.0 - 2.0 * (x * x + y * y),
            ],
        ]

    def rotation_matrix_to_quaternion(self, rotation):
        trace = np.trace(rotation)

        if trace > 0.0:
            s = math.sqrt(trace + 1.0) * 2.0
            w = 0.25 * s
            x = (rotation[2, 1] - rotation[1, 2]) / s
            y = (rotation[0, 2] - rotation[2, 0]) / s
            z = (rotation[1, 0] - rotation[0, 1]) / s

        elif rotation[0, 0] > rotation[1, 1] and rotation[0, 0] > rotation[2, 2]:
            s = math.sqrt(
                1.0
                + rotation[0, 0]
                - rotation[1, 1]
                - rotation[2, 2]
            ) * 2.0

            w = (rotation[2, 1] - rotation[1, 2]) / s
            x = 0.25 * s
            y = (rotation[0, 1] + rotation[1, 0]) / s
            z = (rotation[0, 2] + rotation[2, 0]) / s

        elif rotation[1, 1] > rotation[2, 2]:
            s = math.sqrt(
                1.0
                + rotation[1, 1]
                - rotation[0, 0]
                - rotation[2, 2]
            ) * 2.0

            w = (rotation[0, 2] - rotation[2, 0]) / s
            x = (rotation[0, 1] + rotation[1, 0]) / s
            y = 0.25 * s
            z = (rotation[1, 2] + rotation[2, 1]) / s

        else:
            s = math.sqrt(
                1.0
                + rotation[2, 2]
                - rotation[0, 0]
                - rotation[1, 1]
            ) * 2.0

            w = (rotation[1, 0] - rotation[0, 1]) / s
            x = (rotation[0, 2] + rotation[2, 0]) / s
            y = (rotation[1, 2] + rotation[2, 1]) / s
            z = 0.25 * s

        magnitude = math.sqrt(x * x + y * y + z * z + w * w)

        return Quaternion(
            x=float(x / magnitude),
            y=float(y / magnitude),
            z=float(z / magnitude),
            w=float(w / magnitude),
        )

    def normalize_vector(self, x, y, z):
        magnitude = math.sqrt(x * x + y * y + z * z)

        if magnitude < 1e-12:
            return 0.0, 0.0, 1.0

        return x / magnitude, y / magnitude, z / magnitude

    def copy_point(self, point):
        copied_point = Point()
        copied_point.x = float(point.x)
        copied_point.y = float(point.y)
        copied_point.z = float(point.z)

        return copied_point

    def get_diagnostic_value(self, msg, key):
        for key_value in msg.values:
            if key_value.key == key:
                return key_value.value

        return None

    def get_force_color(self, force_newtons):
        force_magnitude = abs(force_newtons)

        if force_magnitude < 2.0:
            return self.make_color(0.0, 1.0, 0.0, 1.0)

        if force_magnitude < 5.0:
            return self.make_color(1.0, 1.0, 0.0, 1.0)

        return self.make_color(1.0, 0.0, 0.0, 1.0)

    def make_color(self, red, green, blue, alpha):
        color = ColorRGBA()
        color.r = float(red)
        color.g = float(green)
        color.b = float(blue)
        color.a = float(alpha)

        return color


def main(args=None):
    rclpy.init(args=args)
    node = TrainingVisualizationNode()

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