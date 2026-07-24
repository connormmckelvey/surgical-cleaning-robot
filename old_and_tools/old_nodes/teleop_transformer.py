#!/usr/bin/env python3

import os
import json
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseArray, Pose
from visualization_msgs.msg import Marker
import numpy as np

class TeleopTransformerNode(Node):
    def __init__(self):
        super().__init__('teleop_transformer')
        
        # Pulling the movement scaling ratio parameter
        self.declare_parameter('scale_factor', 0.75)       
        self.scale_factor = self.get_parameter('scale_factor').value

        self.declare_parameter('filter_alpha', 0.75) 
        self.filter_alpha = self.get_parameter('filter_alpha').value

        self.declare_parameter('arm_loss_timeout', 0.1)
        self.arm_loss_timeout = self.get_parameter('arm_loss_timeout').value

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

        # Compute Robot Home in ZED Camera Frame: T_C_R = T_R_C^-1, Home_Cam = T_C_R @ Home_Base
        # Robot home position in base frame: X=0.430, Y=0.000, Z=0.228
        home_base_homo = np.array([0.430, 0.000, 0.228, 1.0])
        self.T_C_R = np.linalg.inv(self.T_R_C)
        self.camera_home = (self.T_C_R @ home_base_homo)[:3]

        # Subscribers and Publishers
        self.arm_pose_sub = self.create_subscription(
            PoseArray, 'camera/human_arm_pose', self.arm_pose_callback, 10)
        
        self.target_pose_pub = self.create_publisher(
            Pose, '/arm/target_cartesian_pose', 10)
            
        # Visual debug publisher for RViz (expressed in camera frame)
        self.marker_pub = self.create_publisher(
            Marker, '/arm/target_pose_marker', 10)

        self.get_logger().info(f"Teleop Transformer Online. Camera Home position: {self.camera_home}")

        # Track last message time and home publishing state
        self.last_pose_time = self.get_clock().now()
        self.last_home_publish_time = None

        # Timer to monitor arm detection timeout (e.g. at 10Hz)
        self.timeout_timer = self.create_timer(0.1, self.check_arm_timeout)

    def check_arm_timeout(self):
        now = self.get_clock().now()
        time_since_last_msg = (now - self.last_pose_time).nanoseconds / 1e9
        if time_since_last_msg > self.arm_loss_timeout:
            # Publish home pose at 1Hz when arm is not detected
            if self.last_home_publish_time is None or \
               (now - self.last_home_publish_time).nanoseconds / 1e9 >= 1.0:
                self.publish_home_pose()
                self.last_home_publish_time = now

    def publish_home_pose(self):
        self.get_logger().warn("Arm detection lost or not found. Moving to home position.")
        
        # Publish the target pose in robot base frame (lerobot_frame)
        cmd_msg = Pose()
        cmd_msg.position.x = 0.430
        cmd_msg.position.y = 0.000
        cmd_msg.position.z = 0.228
        cmd_msg.orientation.x = 0.0
        cmd_msg.orientation.y = 0.0
        cmd_msg.orientation.z = 0.0
        cmd_msg.orientation.w = 1.0
        self.target_pose_pub.publish(cmd_msg)

        # Publish RViz marker (Red sphere to indicate lost tracking/moving to home in lerobot_frame)
        marker = Marker()
        marker.header.frame_id = "lerobot_frame"
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "teleop_target"
        marker.id = 0
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        marker.pose.position.x = cmd_msg.position.x
        marker.pose.position.y = cmd_msg.position.y
        marker.pose.position.z = cmd_msg.position.z
        marker.pose.orientation.w = 1.0
        
        marker.scale.x = 0.1
        marker.scale.y = 0.1
        marker.scale.z = 0.1
        
        marker.color.r = 1.0
        marker.color.g = 0.0
        marker.color.b = 0.0
        marker.color.a = 0.8
        
        self.marker_pub.publish(marker)

    def arm_pose_callback(self, msg):
        if len(msg.poses) < 4:
            return 

        self.last_pose_time = self.get_clock().now()
        self.last_home_publish_time = None

        try:
            # Reconstruct numpy arrays from ZED (Shoulder=0, Hand=3)
            shoulder = np.array([msg.poses[0].position.x, msg.poses[0].position.y, msg.poses[0].position.z])
            hand = np.array([msg.poses[3].position.x, msg.poses[3].position.y, msg.poses[3].position.z])

            # Extract relative human displacement vector
            human_displacement = hand - shoulder

            # Coordinate transformation in ZED camera frame (RIGHT_HANDED_Z_UP_X_FWD)
            # (Invert depth/X to match user's perspective facing the camera. Y is already Left/positive)
            displacement_camera = np.array([
                -human_displacement[0],   
                human_displacement[1],   
                human_displacement[2]    
            ])

            # Calculate target point in ZED camera frame relative to camera_home
            raw_target = self.camera_home + (displacement_camera * self.scale_factor)

            # Transform raw target from ZED camera frame to Robot Base frame using T_R_C
            target_homo = np.append(raw_target, 1.0)
            target_robot = (self.T_R_C @ target_homo)[:3]

            # --- 1. Publish standard Pose for the motion planner (in Robot base frame / lerobot_frame) ---
            cmd_msg = Pose()
            cmd_msg.position.x = float(target_robot[0])
            cmd_msg.position.y = float(target_robot[1])
            cmd_msg.position.z = float(target_robot[2])
            cmd_msg.orientation.x = 0.0
            cmd_msg.orientation.y = 0.0
            cmd_msg.orientation.z = 0.0
            cmd_msg.orientation.w = 1.0
            self.target_pose_pub.publish(cmd_msg)

            # --- 2. Publish 3D Marker for visual debugging (in Robot base frame / lerobot_frame) ---
            marker = Marker()
            marker.header.frame_id = "lerobot_frame"
            marker.header.stamp = self.get_clock().now().to_msg()
            marker.ns = "teleop_target"
            marker.id = 0
            marker.type = Marker.SPHERE
            marker.action = Marker.ADD
            
            # Position the marker at the target location in robot frame
            marker.pose.position.x = cmd_msg.position.x
            marker.pose.position.y = cmd_msg.position.y
            marker.pose.position.z = cmd_msg.position.z
            marker.pose.orientation.w = 1.0
            
            marker.scale.x = 0.1
            marker.scale.y = 0.1
            marker.scale.z = 0.1
            
            # Color configuration (Bright translucent Green)
            marker.color.r = 0.0
            marker.color.g = 1.0
            marker.color.b = 0.0
            marker.color.a = 0.8
            
            self.marker_pub.publish(marker)

        except Exception as e:
            self.get_logger().error(f"Transformer logic failure: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = TeleopTransformerNode()
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