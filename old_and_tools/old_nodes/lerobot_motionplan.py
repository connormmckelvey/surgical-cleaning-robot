"""
Lerobot Motion Planning Node for Ros2, made for the OR cleaning robot project in the HERO Lab
Written by Connor McKelvey, 2026
This node is responsible for converting target cartesian poses in the ZED camera fram to joint angle
commands for the LeRobot SO101 arm. It uses a Jacobian Transpose IK solver to compute the joint angles
I choose to seperate this node from the hardware driver to allow for modularity during the testing of different IK solvers
and motion planning algos
in theory it supports orientation but it kinda sucks at it
Inputs: Target cartesian pose in ZED camera frame (geometry_msgs/Pose)
Outputs: Target joint angles in degrees (std_msgs/Float32MultiArray), Current joint angles in degrees (std_msgs/Float32MultiArray), Current cartesian pose in ZED camera frame (geometry_msgs/Pose)
"""

import numpy as np
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import Pose
from scipy.spatial.transform import Rotation as ScipyRot

from arm_control.utilities.fk import *
from arm_control.utilities.se3 import *
from arm_control.utilities.jacobian import *
from arm_control.utilities.so3 import *
from arm_control.utilities.jacobian_transpose import jacobian_transpose_position, jacobian_transpose_pose

class LerobotMotionPlannerNode(Node):
    def __init__(self):
        super().__init__('lerobot_motionplan')
        # 1. Define Robot Kinematic Configuration (SO-101 Arm)
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
        
        # Convert to body frame
        self.B_list = [adjoint(np.linalg.inv(self.M)) @ S for S in self.S_list]

        # Joint Limits (Converted to Radians)
        self.theta_max = np.array([105, 105, 95, 90, 180, 90]) * np.pi / 180.0
        self.theta_min = np.array([-105, -95, -90, -90, -180, -90]) * np.pi / 180.0

        # Gain matrix for full pose Jacobian Transpose IK solver
        self.K_gain = np.diag([
            0.08, 0.08, 0.08,
            0.8,  0.8,  0.8,
        ])

        # Track the latest known state of the arm (in degrees)
        self.current_joint_angles = np.array([0.0, -105.0, 95.0, -90.0, 0.0, 0.0], dtype=float)

        # No calibration matrix loading in motion planner node.
        # It operates directly in the robot base frame (lerobot_frame).
        pass

        # 2. ROS2 Publishers and Subscribers
        self.target_joint_pub = self.create_publisher(
            Float32MultiArray,
            '/arm/target_joint_angles',
            10
        )

        self.feedback_sub = self.create_subscription(
            Float32MultiArray,
            '/arm/current_joint_angles',
            self.feedback_callback,
            10
        )

        # Target Cartesian Pose Subscriber (assumed to be in ZED camera frame)
        self.cartesian_sub = self.create_subscription(
            Pose,
            '/arm/target_cartesian_pose',
            self.cartesian_callback,
            10
        )

        # Current Cartesian Pose Publisher (published in ZED camera frame)
        self.current_cartesian_pub = self.create_publisher(
            Pose,
            '/arm/current_cartesian_pose',
            10
        )

        self.get_logger().info("Motion Planner Node initialized. Listening on /arm/target_cartesian_pose")

    def feedback_callback(self, msg):
        """ Keeps internal joint state synchronized and streams real-time Cartesian feedback. """
        self.current_joint_angles = np.array(msg.data, dtype=float)

        # Recalculate end-effector pose in robot base frame
        try:
            T_base_to_ee = self.compute_forward_kinematics()
            
            # Create and publish the geometry pose message
            cartesian_msg = Pose()
            cartesian_msg.position.x = float(T_base_to_ee[0, 3])
            cartesian_msg.position.y = float(T_base_to_ee[1, 3])
            cartesian_msg.position.z = float(T_base_to_ee[2, 3])
            
            # Compute orientation quaternion from robot base frame pose matrix
            R_mat = T_base_to_ee[:3, :3]
            q = ScipyRot.from_matrix(R_mat).as_quat() # [x, y, z, w]
            cartesian_msg.orientation.x = float(q[0])
            cartesian_msg.orientation.y = float(q[1])
            cartesian_msg.orientation.z = float(q[2])
            cartesian_msg.orientation.w = float(q[3])
            
            self.current_cartesian_pub.publish(cartesian_msg)
        except Exception as e:
            self.get_logger().error(f"Failed to compute or publish forward kinematics feedback: {e}")

    def cartesian_callback(self, msg):
        # Extract target position in robot base frame
        p_base = np.array([msg.position.x, msg.position.y, msg.position.z], dtype=float)
        q_base = [msg.orientation.x, msg.orientation.y, msg.orientation.z, msg.orientation.w]
        
        # Build homogeneous transform of target in robot base frame
        try:
            R_base = ScipyRot.from_quat(q_base).as_matrix()
            T_sd = np.eye(4)
            T_sd[:3, :3] = R_base
            T_sd[:3, 3] = p_base
            
            # Apply Cartesian safety bounding box clipping in the robot base frame
            T_sd[0, 3] = np.clip(T_sd[0, 3], 0.05, 0.42)   # X bounds
            T_sd[1, 3] = np.clip(T_sd[1, 3], -0.25, 0.25)  # Y bounds
            T_sd[2, 3] = np.clip(T_sd[2, 3], 0.02, 0.35)   # Z bounds
            
            self.get_logger().info(
                f"Received robot base-frame target (clipped): X={T_sd[0, 3]:.3f}, Y={T_sd[1, 3]:.3f}, Z={T_sd[2, 3]:.3f}",
                throttle_duration_sec=2.0
            )
            
            self.command_cartesian_pose(T_sd)
        except Exception as e:
            self.get_logger().error(f"Failed to process target pose: {e}")

    def compute_forward_kinematics(self):
        #joint angles in degrees, convert to radians for FK calculation
        theta_deg = np.copy(self.current_joint_angles)
        theta_rad = np.radians(theta_deg)

        T_base_to_ee = space_product_of_exponentials(self.M, self.S_list, theta_rad)
        return T_base_to_ee

    def command_cartesian_pose(self, T_sd):
        init_angles = np.copy(self.current_joint_angles)
        theta_init_rad = np.radians(init_angles)

        # compute full pose IK
        theta_sol_rad, theta_sol_rad_hist, norm_w_hist, norm_v_hist = jacobian_transpose_pose(
                    M_ee=self.M,
                    B_list=self.B_list,
                    theta_init=theta_init_rad,
                    T_sd=T_sd,
                    max_iters=100,
                    tol_w=1e-3,
                    tol_v=1e-3,
                    q_min=self.theta_min,
                    q_max=self.theta_max,
                    K=self.K_gain,
                    print_iterations=True
        )

        # Verify if the solution is structurally valid (not NaN or infinite)
        if theta_sol_rad is None or np.isnan(theta_sol_rad).any() or np.isinf(theta_sol_rad).any():
            self.get_logger().error("IK engine failed to reach target pose! Command dropped.")
            return

        # Convert back to degrees for the LeRobot driver
        theta_deg = np.degrees(np.asarray(theta_sol_rad, dtype=float))
        
        # Build and publish joint command array
        msg = Float32MultiArray()
        msg.data = theta_deg.tolist()
        self.target_joint_pub.publish(msg)
        self.get_logger().info(f"Successfully sent IK-resolved joint angles to driver node.")

def main(args=None):
    rclpy.init(args=args)
    node = LerobotMotionPlannerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()