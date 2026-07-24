#!/usr/bin/env python3

import numpy as np
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from visualization_msgs.msg import Marker

class PlaybackRobotTransformerNode(Node):
    def __init__(self):
        super().__init__('playback_robot_transformer')

        # Declare parameters for robot-frame simulated centroid
        self.declare_parameter('centroid_x', 0.3)
        self.declare_parameter('centroid_y', 0.0)
        self.declare_parameter('centroid_z', 0.0)

        # Subscribers
        self.norm_hand_sub = self.create_subscription(
            Point, 'camera/normalized_hand_position', self.normalized_hand_callback, 10)

        # Marker Publisher (Visualizations only)
        self.marker_pub = self.create_publisher(
            Marker, '/arm/target_pose_marker', 10)

        self.get_logger().info("Playback Robot-Frame Visualizer Node online (Markers Only).")

    def normalized_hand_callback(self, msg):
        # 1. Dynamically read robot-frame simulated centroid parameters
        centroid_x = self.get_parameter('centroid_x').value
        centroid_y = self.get_parameter('centroid_y').value
        centroid_z = self.get_parameter('centroid_z').value
        centroid_robot = np.array([centroid_x, centroid_y, centroid_z])

        # 2. Directly add hand offsets to the robot centroid (pure robot base frame operation)
        offset = np.array([msg.x, msg.y, msg.z])
        p_robot = centroid_robot + offset

        # 3. Publish RViz marker for hand position (bright orange/yellow sphere)
        target_marker = Marker()
        target_marker.header.frame_id = "lerobot_frame"
        target_marker.header.stamp = self.get_clock().now().to_msg()
        target_marker.ns = "playback_target"
        target_marker.id = 0
        target_marker.type = Marker.SPHERE
        target_marker.action = Marker.ADD
        target_marker.pose.position.x = float(p_robot[0])
        target_marker.pose.position.y = float(p_robot[1])
        target_marker.pose.position.z = float(p_robot[2])
        target_marker.pose.orientation.w = 1.0
        target_marker.scale.x = 0.08
        target_marker.scale.y = 0.08
        target_marker.scale.z = 0.08
        target_marker.color.r = 1.0
        target_marker.color.g = 0.6
        target_marker.color.b = 0.0
        target_marker.color.a = 0.8
        self.marker_pub.publish(target_marker)

        # 4. Publish RViz marker for simulated centroid (solid bright cyan sphere)
        centroid_marker = Marker()
        centroid_marker.header.frame_id = "lerobot_frame"
        centroid_marker.header.stamp = target_marker.header.stamp
        centroid_marker.ns = "robot_centroid"
        centroid_marker.id = 1
        centroid_marker.type = Marker.SPHERE
        centroid_marker.action = Marker.ADD
        centroid_marker.pose.position.x = float(centroid_robot[0])
        centroid_marker.pose.position.y = float(centroid_robot[1])
        centroid_marker.pose.position.z = float(centroid_robot[2])
        centroid_marker.pose.orientation.w = 1.0
        centroid_marker.scale.x = 0.05
        centroid_marker.scale.y = 0.05
        centroid_marker.scale.z = 0.05
        centroid_marker.color.r = 0.0
        centroid_marker.color.g = 0.8
        centroid_marker.color.b = 1.0
        centroid_marker.color.a = 1.0
        self.marker_pub.publish(centroid_marker)

def main(args=None):
    rclpy.init(args=args)
    node = PlaybackRobotTransformerNode()
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
