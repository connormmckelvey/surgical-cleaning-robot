"""
urobot_driver node for the surgical arm ROS2 project, made for the OR cleaning robot project in the HERO Lab
written by Connor McKelvey
This node is responsible for interfacing with the URobot Lite6 robotic arm. listens to both cartesian pose (meters) and joint angle commands (degrees) and sends them to the robot.
you can't send both joint angles and cordinates as the robot must be in a different mode for each.
publishes to the current cartesian pose (meters) and joint angles (degrees) of the robot

Inputs: Target cartesian pose in meters (geometry_msgs/Pose), Target joint angles in degrees (std_msgs/Float32MultiArray)
Outputs: Current cartesian pose in meters (geometry_msgs/Pose), Current joint angles in degrees (std_msgs/Float32MultiArray)
Services: OpenGripper, CloseGripper

to call the services use the following commands:
ros2 service call /arm/OpenGripper std_srvs/srv/Trigger
ros2 service call /arm/CloseGripper std_srvs/srv/Trigger
"""

import numpy as np
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import Pose
from std_srvs.srv import Trigger

from xarm.wrapper import XArmAPI
from scipy.spatial.transform import Rotation as R

class URobotDriverNode(Node):
    def __init__(self):
        super().__init__('urobot_driver')                
        #params
        self.declare_parameter('ip','192.168.1.184')
        self.declare_parameter('control_loop_period', 0.05) #20Hz loop
        self.declare_parameter('mode',0)
        self.declare_parameter('wait', False) 

        self.ip = self.get_parameter('ip').value
        self.control_loop_period = self.get_parameter('control_loop_period').value
        self.mode = self.get_parameter('mode').value
        self.wait = self.get_parameter('wait').value
        #physical connection
        self.robot = XArmAPI(self.ip)
        self.robot.motion_enable(enable=True)
        self.robot.set_mode(self.mode)  # Position control mode
        self.robot.set_state(state=0)  # Set the robot to ready state
        self.robot.set_position(x=300, y=0, z=200, roll=180, pitch=0, yaw=0, speed=100, wait=True)
        self.get_logger().info("URobot CONNECTED")

        # 4. ROS2 Subscribers and Publishers and Services values are in degrees and mm
        self.subscription = self.create_subscription(
            Pose,
            '/arm/target_cartesian_pose',
            self.target_cartesian_pose_callback,
            10
        )   
        self.subscription = self.create_subscription(
            Float32MultiArray,
            '/arm/target_joint_angles',
            self.target_joint_angle_callback,
            10
        )
        self.current_pose_pub = self.create_publisher(
            Pose, 
            '/arm/current_cartesian_pose', 
            10
        )
        self.current_state_pub = self.create_publisher(
            Float32MultiArray, 
            '/arm/current_joint_angles', 
            10
        )
        self.close_gripper_srv = self.create_service(
            Trigger,
            'arm/CloseGripper',
            self.close_gripper_callback,
        )
        self.open_gripper_srv = self.create_service(
            Trigger,
            'arm/OpenGripper',
            self.open_gripper_callback
        )

        # 5. Start Runtime Control Loop
        self.control_timer = self.create_timer(self.control_loop_period, self.control_loop_callback)

    def target_cartesian_pose_callback(self, msg):
        # Send the target pose to the robot
        roll,pitch,yaw = R.from_quat([msg.orientation.x, msg.orientation.y, msg.orientation.z, msg.orientation.w]).as_euler('xyz', degrees=True)
        self.robot.set_position(x=msg.position.x * 1000.0, y=msg.position.y * 1000.0, z=msg.position.z * 1000.0, roll=roll, pitch=pitch, yaw=yaw,is_radian=False,wait=self.wait)

    def target_joint_angle_callback(self, msg):
        # Send the target joint angles to the robot
        self.robot.set_servo_angle(angle=[msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4], msg.data[5]], is_radian=False)

    def close_gripper_callback(self,request,response):
        self.robot.open_lite6_gripper()
        response.success = True
        response.message = "Gripper Closing"
        return response

    def open_gripper_callback(self,request,response):
        self.robot.close_lite6_gripper()
        response.success = True
        response.message = "Gripper Opening"
        return response

    def control_loop_callback(self):
        # Continually publish state back to your planner node
        current_pose_msg = Pose()
        current_joint_msg = Float32MultiArray()
        code, current_pose = self.robot.get_position(is_radian=False)
        if code != 0 or current_pose is None:
            self.get_logger().error(f'Failed to get robot position, code: {code}')
            return
        current_pose_msg.position.x = float(current_pose[0])/1000.0  # Convert mm to meters
        current_pose_msg.position.y = float(current_pose[1])/1000.0
        current_pose_msg.position.z = float(current_pose[2])/1000.0

        quat = R.from_euler('xyz',[current_pose[3], current_pose[4], current_pose[5]], degrees=True).as_quat()

        current_pose_msg.orientation.x = float(quat[0])
        current_pose_msg.orientation.y = float(quat[1])
        current_pose_msg.orientation.z = float(quat[2])
        current_pose_msg.orientation.w = float(quat[3])

        # Get current joint angles
        code, joint_angles = self.robot.get_servo_angle(is_radian=False)

        if code != 0 or joint_angles is None:
            self.get_logger().error(f'Failed to get joint angles, code: {code}')
            return

        current_joint_msg.data = [float(angle) for angle in joint_angles]

        self.current_pose_pub.publish(current_pose_msg)
        self.current_state_pub.publish(current_joint_msg)

    def destroy_node(self):
        self.get_logger().info("Disconnecting from robot...")
        try:
            self.robot.set_state(4)
            self.robot.disconnect()
        except Exception:
            pass
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = URobotDriverNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
if __name__ == '__main__':
    main()