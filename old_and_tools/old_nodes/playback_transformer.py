#!/usr/bin/env python3

import os
import json
import numpy as np
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point, Pose
from visualization_msgs.msg import Marker

class PlaybackTransformerNode(Node):
    def __init__(self):
        super().__init__('playback_transformer')

        # State variables
        self.execution_centroid = None
        self.execution_normal = None

        # Load Calibration Matrix T_R_C (transforms camera Z-UP frame to robot base frame)
        self.T_R_C = np.eye(4)
        calibration_path = '/home/connor/robotics_projects/surgical-arm-ros2/calibration.json'
        if os.path.exists(calibration_path):
            try:
                with open(calibration_path, 'r') as f:
                    calib_data = json.load(f)
                    self.T_R_C = np.array(calib_data["T_R_C"])
                self.get_logger().info(f"Successfully loaded calibration matrix from {calibration_path}")
            except Exception as e:
                self.get_logger().error(f"Failed to load calibration JSON: {e}")
        else:
            self.get_logger().warn(f"Calibration file NOT found at {calibration_path}! Defaulting to identity mapping.")

        # Subscribers
        self.centroid_sub = self.create_subscription(
            Point, 'camera/execution_centroid', self.centroid_callback, 10)
        self.normal_sub = self.create_subscription(
            Point, 'camera/execution_normal', self.normal_callback, 10)
        self.norm_hand_sub = self.create_subscription(
            Point, 'camera/normalized_hand_position', self.normalized_hand_callback, 10)

        # Publishers
        self.target_pose_pub = self.create_publisher(
            Pose, '/arm/target_cartesian_pose', 10)
        self.marker_pub = self.create_publisher(
            Marker, '/arm/target_pose_marker', 10)

        self.get_logger().info("Playback Transformer Node online. Operating in Camera Frame.")

    def centroid_callback(self, msg):
        self.execution_centroid = np.array([msg.x, msg.y, msg.z])
        self.get_logger().info(f"Received execution centroid: [{msg.x:.3f}, {msg.y:.3f}, {msg.z:.3f}]")
        self.publish_transformed_centroid_marker()

    def normal_callback(self, msg):
        self.execution_normal = np.array([msg.x, msg.y, msg.z])
        self.get_logger().info(f"Received execution normal: [{msg.x:.3f}, {msg.y:.3f}, {msg.z:.3f}]")

    def normalized_hand_callback(self, msg):
        if self.execution_centroid is None:
            self.get_logger().warn("Centroid not set. Please click on the target object in camera_execution window first.", throttle_duration_sec=3.0)
            return

        # 1. Reconstruct target point in camera frame
        if self.execution_normal is not None:
            N = self.execution_normal / np.linalg.norm(self.execution_normal)
            
            # Project camera X axis [1, 0, 0] onto the plane to get tangent T1
            X_axis = np.array([1.0, 0.0, 0.0])
            T1 = X_axis - np.dot(X_axis, N) * N
            T1_norm = np.linalg.norm(T1)
            if T1_norm < 1e-4:
                Y_axis = np.array([0.0, 1.0, 0.0])
                T1 = Y_axis - np.dot(Y_axis, N) * N
                T1 = T1 / np.linalg.norm(T1)
            else:
                T1 = T1 / T1_norm
            
            # T2 is perpendicular to N and T1 (right-handed frame: T1 x T2 = N => T2 = N x T1)
            T2 = np.cross(N, T1)
            T2 = T2 / np.linalg.norm(T2)
            
            # Reconstruct relative motion on the plane surface
            p_camera = self.execution_centroid + msg.x * T1 + msg.y * T2 + msg.z * N
        else:
            # Fallback direct addition if normal is not yet received
            p_centroid = np.array([msg.x, msg.y, msg.z])
            p_camera = self.execution_centroid + p_centroid

        # 2. Transform target point from ZED camera frame to Robot Base frame using T_R_C
        p_camera_homo = np.append(p_camera, 1.0)
        p_robot = (self.T_R_C @ p_camera_homo)[:3]

        # 3. Publish target Pose for motion planner (in Robot Base Frame / lerobot_frame)
        cmd_msg = Pose()
        cmd_msg.position.x = float(p_robot[0])
        cmd_msg.position.y = float(p_robot[1])
        cmd_msg.position.z = float(p_robot[2])
        cmd_msg.orientation.x = 0.0
        cmd_msg.orientation.y = 0.0
        cmd_msg.orientation.z = 0.0
        cmd_msg.orientation.w = 1.0
        self.target_pose_pub.publish(cmd_msg)

        # 4. Publish RViz marker (in Robot Base Frame / lerobot_frame)
        marker = Marker()
        marker.header.frame_id = "lerobot_frame"
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "playback_target"
        marker.id = 0
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        
        marker.pose.position.x = cmd_msg.position.x
        marker.pose.position.y = cmd_msg.position.y
        marker.pose.position.z = cmd_msg.position.z
        marker.pose.orientation.w = 1.0
        
        marker.scale.x = 0.08
        marker.scale.y = 0.08
        marker.scale.z = 0.08
        
        # Bright translucent orange/yellow target sphere
        marker.color.r = 1.0
        marker.color.g = 0.6
        marker.color.b = 0.0
        marker.color.a = 0.8
        
        self.marker_pub.publish(marker)

        # 5. Publish Transformed Centroid marker in lerobot_frame
        self.publish_transformed_centroid_marker()

    def publish_transformed_centroid_marker(self):
        if self.execution_centroid is None:
            return

        try:
            # Transform execution centroid to Robot Base Frame (lerobot_frame)
            centroid_cam = np.append(self.execution_centroid, 1.0)
            centroid_robot = (self.T_R_C @ centroid_cam)[:3]

            marker = Marker()
            marker.header.frame_id = "lerobot_frame"
            marker.header.stamp = self.get_clock().now().to_msg()
            marker.ns = "transformed_centroid"
            marker.id = 1
            marker.type = Marker.SPHERE
            marker.action = Marker.ADD
            
            marker.pose.position.x = float(centroid_robot[0])
            marker.pose.position.y = float(centroid_robot[1])
            marker.pose.position.z = float(centroid_robot[2])
            marker.pose.orientation.w = 1.0
            
            marker.scale.x = 0.05
            marker.scale.y = 0.05
            marker.scale.z = 0.05
            
            # Solid bright cyan/blue to match UI centroid marker
            marker.color.r = 0.0
            marker.color.g = 0.8
            marker.color.b = 1.0
            marker.color.a = 1.0
            
            self.marker_pub.publish(marker)
        except Exception as e:
            self.get_logger().error(f"Failed to publish transformed centroid marker: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = PlaybackTransformerNode()
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
