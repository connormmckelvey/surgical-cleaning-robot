"""
keyboard_controller node for testing realtime cartesian control of the URobot Lite6
written by Connor McKelvey | connormckelvey@utexas.edu

Subscribes to the current robot pose and publishes incremental cartesian target poses.

Controls:
w / s - increase or decrease X
a / d - increase or decrease Y
r / f - increase or decrease Z
h - reset target to current robot pose
q - quit

Inputs: Current cartesian pose in meters (geometry_msgs/Pose)
Outputs: Target cartesian pose in meters (geometry_msgs/Pose)
"""

import select
import sys
import termios
import threading
import tty

import rclpy
from geometry_msgs.msg import Pose
from rclpy.node import Node


class KeyboardControllerNode(Node):
    def __init__(self):
        super().__init__('keyboard_controller')

        self.declare_parameter('movement_step',0.01)
        self.movement_step = self.get_parameter('movement_step').value

        self.current_pose = None
        self.target_pose = None
        self.running = True

        self.target_pose_pub = self.create_publisher(Pose, '/arm/target_cartesian_pose', 1)
        self.current_pose_sub = self.create_subscription(Pose, '/arm/current_cartesian_pose', self.current_pose_callback, 1)

        self.terminal_settings = termios.tcgetattr(sys.stdin)
        self.keyboard_thread = threading.Thread(target=self.keyboard_loop,daemon=True)
        self.keyboard_thread.start()

        self.get_logger().info(
            'Keyboard Controller Started | '
            'W/S: X | A/D: Y | R/F: Z | H: Reset | Q: Quit'
        )

    def current_pose_callback(self,msg):
        self.current_pose = self.copy_pose(msg)

        if self.target_pose is None:
            self.target_pose = self.copy_pose(msg)
            self.get_logger().info(
                f'Initial target set to current pose: '
                f'x={msg.position.x:.3f}, '
                f'y={msg.position.y:.3f}, '
                f'z={msg.position.z:.3f}'
            )

    def keyboard_loop(self):
        tty.setcbreak(sys.stdin.fileno())

        try:
            while self.running and rclpy.ok():
                if not select.select([sys.stdin],[],[],0.1)[0]:
                    continue

                key = sys.stdin.read(1).lower()

                if key == 'q':
                    self.running = False
                    rclpy.shutdown()
                    break

                self.handle_key(key)

        finally:
            termios.tcsetattr(sys.stdin,termios.TCSADRAIN,self.terminal_settings)

    def handle_key(self,key):
        if self.target_pose is None:
            self.get_logger().warning('Waiting for the current robot pose')
            return

        if key == 'w':
            self.target_pose.position.x += self.movement_step

        elif key == 's':
            self.target_pose.position.x -= self.movement_step

        elif key == 'a':
            self.target_pose.position.y += self.movement_step

        elif key == 'd':
            self.target_pose.position.y -= self.movement_step

        elif key == 'r':
            self.target_pose.position.z += self.movement_step

        elif key == 'f':
            self.target_pose.position.z -= self.movement_step

        elif key == 'h':
            if self.current_pose is None:
                return

            self.target_pose = self.copy_pose(self.current_pose)
            self.get_logger().info('Target reset to current robot pose')

        else:
            return

        self.target_pose.orientation.x = 1.0
        self.target_pose.orientation.y = 0.0
        self.target_pose.orientation.z = 0.0
        self.target_pose.orientation.w = 0.0

        self.target_pose_pub.publish(self.target_pose)

        self.get_logger().info(
            f'Target: '
            f'x={self.target_pose.position.x:.3f}, '
            f'y={self.target_pose.position.y:.3f}, '
            f'z={self.target_pose.position.z:.3f}'
        )

    @staticmethod
    def copy_pose(pose):
        copied_pose = Pose()

        copied_pose.position.x = pose.position.x
        copied_pose.position.y = pose.position.y
        copied_pose.position.z = pose.position.z

        copied_pose.orientation.x = pose.orientation.x
        copied_pose.orientation.y = pose.orientation.y
        copied_pose.orientation.z = pose.orientation.z
        copied_pose.orientation.w = pose.orientation.w

        return copied_pose

    def destroy_node(self):
        self.running = False

        try:
            termios.tcsetattr(sys.stdin,termios.TCSADRAIN,self.terminal_settings)
        except Exception:
            pass

        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = KeyboardControllerNode()

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