#!/usr/bin/env python3

import numpy as np
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray, ColorRGBA
from geometry_msgs.msg import Point
from visualization_msgs.msg import Marker, MarkerArray

# Importing your custom robotics utilities for full arm forward kinematics
from arm_control.utilities.fk import space_product_of_exponentials
from arm_control.utilities.se3 import screw_axis_from_w_q

class LeRobotSimulatedDriverNode(Node):
    def __init__(self):
        super().__init__('lerobot_driver') # Kept same name so your ROS network matches
        
        # Exact motion parameters from your physical hardware driver
        self.max_step_deg = 2.0
        self.control_loop_period = 0.05  # 20Hz loop

        # 1. Define Robot Kinematic Configuration (SO-101 Arm) for RViz rendering
        self.w1 = np.array([0, 0, 1])
        self.q1 = np.array([0.038, 0, 0.064])
        self.w2 = np.array([0, 1, 0])
        self.q2 = np.array([0.06874, 0, 0.117050])
        self.w3 = np.array([0, 1, 0])
        self.q3 = np.array([0.097, 0, 0.228])
        self.w4 = np.array([0, 1, 0])
        self.q4 = np.array([0.225, 0, 0.228])
        self.w5 = np.array([1, 0, 0])
        self.q5 = np.array([0.289, 0, 0.228])
        self.w6 = np.array([0, 1, 0])
        self.q6 = np.array([0.326, 0, 0.228])

        self.M = np.array([
            [1, 0, 0, 0.430],
            [0, 1, 0, 0.000],
            [0, 0, 1, 0.228],
            [0, 0, 0, 1.000]
        ])

        self.S_list = [
            screw_axis_from_w_q(self.w1, self.q1),
            screw_axis_from_w_q(self.w2, self.q2),
            screw_axis_from_w_q(self.w3, self.q3),
            screw_axis_from_w_q(self.w4, self.q4),
            screw_axis_from_w_q(self.w5, self.q5),
            screw_axis_from_w_q(self.w6, self.q6),
        ]
        
        # 2. Match your hardware startup behavior (Zero out all joints to Home)
        self.get_logger().info("Simulating Hardware Initialization: Zeroing virtual joints...")
        self.current_positions = np.array([0.0, 0.0, 0.0, 0.0, 0.0, 0.0], dtype=float)
        self.target_positions = np.copy(self.current_positions)

        # 3. ROS2 Subscribers and Publishers
        self.subscription = self.create_subscription(
            Float32MultiArray,
            '/arm/target_joint_angles',
            self.joint_angle_callback,
            10
        )

        self.current_state_pub = self.create_publisher(
            Float32MultiArray, 
            '/arm/current_joint_angles', 
            10
        )

        self.rviz_arm_pub = self.create_publisher(
            MarkerArray,
            '/arm/simulated_hardware_mesh',
            10
        )

        # 4. Start Runtime Control Loop (Runs your exact 20Hz clock)
        self.control_timer = self.create_timer(self.control_loop_period, self.control_loop_callback)
        self.get_logger().info("Mock LeRobot Driver Online. Connected to virtual visualization pipeline.")

    def joint_angle_callback(self, msg):
        input_angles = np.array(msg.data, dtype=float)
        if len(input_angles) != 6:
            self.get_logger().error(f"Expected 6 joint angles, received: {len(input_angles)}")
            return
        self.target_positions = input_angles

    def control_loop_callback(self):
        # Your exact physical step-limiting logic intact
        diff = self.target_positions - self.current_positions
        max_diff = np.max(np.abs(diff))
        
        if max_diff > 1e-5:
            step_scale = min(1.0, self.max_step_deg / max_diff)
            self.current_positions += diff * step_scale

        # Continually publish state back to your planner node to satisfy the loop
        state_msg = Float32MultiArray()
        state_msg.data = self.current_positions.tolist()
        self.current_state_pub.publish(state_msg)

        # Draw the full physical arm shape in RViz based on current interpolated states
        self.publish_rviz_arm_skeleton()

    def publish_rviz_arm_skeleton(self):
        """ Computes the live 3D location of every joint link and renders them in RViz """
        positions_actual = np.copy(self.current_positions)
        theta_rad = np.radians(positions_actual)
        
        # Build coordinate points for every segment connection point
        joints = [np.array([0.0, 0.0, 0.0])] # Shoulder base origin
        joints.append(self.q1)
        
        # Joint 2 location
        T = space_product_of_exponentials(np.eye(4), self.S_list[:1], theta_rad[:1])
        joints.append((T @ np.append(self.q2, 1.0))[:3])
        
        # Joint 3 location
        T = space_product_of_exponentials(np.eye(4), self.S_list[:2], theta_rad[:2])
        joints.append((T @ np.append(self.q3, 1.0))[:3])

        # Joint 4 location
        T = space_product_of_exponentials(np.eye(4), self.S_list[:3], theta_rad[:3])
        joints.append((T @ np.append(self.q4, 1.0))[:3])

        # Joint 5 location
        T = space_product_of_exponentials(np.eye(4), self.S_list[:4], theta_rad[:4])
        joints.append((T @ np.append(self.q5, 1.0))[:3])

        # Joint 6 location
        T = space_product_of_exponentials(np.eye(4), self.S_list[:5], theta_rad[:5])
        joints.append((T @ np.append(self.q6, 1.0))[:3])

        # Gripper / End-Effector Tip (Full Transform Matrix applied to home matrix M)
        T_ee = space_product_of_exponentials(self.M, self.S_list, theta_rad)
        joints.append(T_ee[:3, 3])

        # 1. Packaging links into a structural LINE_LIST marker with alternating colors
        links_marker = Marker()
        links_marker.header.frame_id = "lerobot_frame"
        links_marker.header.stamp = self.get_clock().now().to_msg()
        links_marker.ns = "so101_arm_body"
        links_marker.id = 101
        links_marker.type = Marker.LINE_LIST
        links_marker.action = Marker.ADD
        
        # Visual thickness of the arm links in meters (3.5 cm thick links)
        links_marker.scale.x = 0.035 
        
        # Modern color palette: alternating Sleek Grey and Cyber Blue
        c_grey = ColorRGBA(r=0.25, g=0.25, b=0.28, a=0.9)
        c_blue = ColorRGBA(r=0.0, g=0.6, b=1.0, a=0.9)
        
        # Stream points sequentially in pairs to form segments
        for i in range(len(joints) - 1):
            p1 = Point(x=float(joints[i][0]), y=float(joints[i][1]), z=float(joints[i][2]))
            p2 = Point(x=float(joints[i+1][0]), y=float(joints[i+1][1]), z=float(joints[i+1][2]))
            links_marker.points.extend([p1, p2])
            
            # Alternate color for each arm section
            color = c_blue if i % 2 == 1 else c_grey
            links_marker.colors.extend([color, color])

        # 2. Publish end-effector orientation axes in RViz (LINE_LIST format)
        axes_marker = Marker()
        axes_marker.header.frame_id = "lerobot_frame"
        axes_marker.header.stamp = links_marker.header.stamp
        axes_marker.ns = "so101_arm_ee_axes"
        axes_marker.id = 102
        axes_marker.type = Marker.LINE_LIST
        axes_marker.action = Marker.ADD
        
        # Thickness of the axes lines (3 mm)
        axes_marker.scale.x = 0.003
        
        ee_pos = T_ee[:3, 3]
        ee_rot = T_ee[:3, :3]
        
        axis_length = 0.06  # 6 cm axis length
        
        # Define the start and end points for X (Red), Y (Green), Z (Blue) axes
        p_start = Point(x=float(ee_pos[0]), y=float(ee_pos[1]), z=float(ee_pos[2]))
        
        p_x_end = Point(
            x=float(ee_pos[0] + axis_length * ee_rot[0, 0]),
            y=float(ee_pos[1] + axis_length * ee_rot[1, 0]),
            z=float(ee_pos[2] + axis_length * ee_rot[2, 0])
        )
        
        p_y_end = Point(
            x=float(ee_pos[0] + axis_length * ee_rot[0, 1]),
            y=float(ee_pos[1] + axis_length * ee_rot[1, 1]),
            z=float(ee_pos[2] + axis_length * ee_rot[2, 1])
        )
        
        p_z_end = Point(
            x=float(ee_pos[0] + axis_length * ee_rot[0, 2]),
            y=float(ee_pos[1] + axis_length * ee_rot[1, 2]),
            z=float(ee_pos[2] + axis_length * ee_rot[2, 2])
        )
        
        axes_marker.points.extend([p_start, p_x_end, p_start, p_y_end, p_start, p_z_end])
        
        c_red = ColorRGBA(r=1.0, g=0.0, b=0.0, a=1.0)
        c_green = ColorRGBA(r=0.0, g=1.0, b=0.0, a=1.0)
        c_blue = ColorRGBA(r=0.0, g=0.0, b=1.0, a=1.0)
        
        axes_marker.colors.extend([c_red, c_red, c_green, c_green, c_blue, c_blue])

        # 3. Publish joint centers as orange spheres (SPHERE_LIST format)
        joints_marker = Marker()
        joints_marker.header.frame_id = "lerobot_frame"
        joints_marker.header.stamp = links_marker.header.stamp
        joints_marker.ns = "so101_arm_joints"
        joints_marker.id = 103
        joints_marker.type = Marker.SPHERE_LIST
        joints_marker.action = Marker.ADD
        
        
        joints_marker.scale.x = 0.042
        joints_marker.scale.y = 0.042
        joints_marker.scale.z = 0.042
        
        joints_marker.color.r = 1.0
        joints_marker.color.g = 0.55
        joints_marker.color.b = 0.0
        joints_marker.color.a = 1.0
        
        # Add positions for joint centers (from joint 1 to joint 6, excluding base and EE tip)
        for i in range(1, len(joints) - 1):
            pt = Point(x=float(joints[i][0]), y=float(joints[i][1]), z=float(joints[i][2]))
            joints_marker.points.append(pt)
            
        # Packaging all markers together into a MarkerArray for atomic publication
        # 4. Publish static origin axes at (0, 0, 0)
        origin_axes_marker = Marker()
        origin_axes_marker.header.frame_id = "lerobot_frame"
        origin_axes_marker.header.stamp = links_marker.header.stamp
        origin_axes_marker.ns = "lerobot_origin_axes"
        origin_axes_marker.id = 104
        origin_axes_marker.type = Marker.LINE_LIST
        origin_axes_marker.action = Marker.ADD
        
        origin_axes_marker.scale.x = 0.005 # 5 mm thickness
        
        p_origin = Point(x=0.0, y=0.0, z=0.0)
        p_x = Point(x=0.20, y=0.0, z=0.0)
        p_y = Point(x=0.0, y=0.20, z=0.0)
        p_z = Point(x=0.0, y=0.0, z=0.20)
        
        origin_axes_marker.points.extend([p_origin, p_x, p_origin, p_y, p_origin, p_z])
        origin_axes_marker.colors.extend([c_red, c_red, c_green, c_green, c_blue, c_blue])

        # Packaging all markers together into a MarkerArray for atomic publication
        marker_array = MarkerArray()
        marker_array.markers.extend([links_marker, axes_marker, joints_marker, origin_axes_marker])
        self.rviz_arm_pub.publish(marker_array)


def main(args=None):
    rclpy.init(args=args)
    node = LeRobotSimulatedDriverNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()