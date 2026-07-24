#!/usr/bin/env python3

"""
calibrate_controller ros2 node written for the Surgical Cleaning Project for Texas Robotics in the HERO Lab
written by Connor McKelvey, 2026
This node is used to collect hand-eye calibration data for the Surgical Arm ROS 2 project. it moves through a series of poses and collects end effector pose and tag pose for each step
right now there are 40. press 's' once the window opens to start the calibration process, then press 'a' to approve a pose and capture the data, or 'x' to skip a pose.
Once all poses are captured the node will run the calibration and save it to cam2base_calibration.yaml in the current working directory. 
The calibration is done using OpenCV's calibrateHandEye function. to run this workflow run the following command:
`ros2 launch arm_control calibrate.launch.py`
"""

import copy
import math
import time
from enum import Enum, auto

import cv2 as cv
import numpy as np
import rclpy
import yaml
from geometry_msgs.msg import Point, Pose, PoseStamped, Quaternion
from rclpy.node import Node
from sensor_msgs.msg import Image

class State(Enum):
    IDLE = auto()
    MOVE = auto()
    WAIT = auto()
    APPROVE = auto()
    CAPTURE = auto()
    SOLVE = auto()
    DONE = auto()


class CalibrationControllerNode(Node):

    def __init__(self):
        super().__init__('calibration_controller')

        self.declare_parameter('calibration_yaml', 'cam2base_calibration.yaml')
        self.declare_parameter('position_tolerance_mm', 2.0)  # mm
        self.declare_parameter('angle_tolerance_deg', 2.0)  # deg
        self.declare_parameter('settle_time', 0.5)  # seconds
        self.declare_parameter('move_timeout', 15.0)  # seconds to wait for the arm to reach a target before skipping it
        self.declare_parameter('require_approval', True)  # require user approval to capture each pose

        self.calibration_yaml = self.get_parameter('calibration_yaml').value
        self.position_tolerance_mm = self.get_parameter('position_tolerance_mm').value
        self.angle_tolerance_deg = self.get_parameter('angle_tolerance_deg').value
        self.move_timeout = self.get_parameter('move_timeout').value
        self.settle_time = self.get_parameter('settle_time').value
        self.require_approval = self.get_parameter('require_approval').value

        self.poses = self.build_poses()
        self.ee_samples = []
        self.tag_samples = []

        self.latest_ee = None
        self.latest_tag = None

        self.state = State.IDLE
        self.pose_index = 0
        self.settle_start = None
        self.move_start = None
        self.approved = False

        self.window_name = 'Calibration Capture'
        cv.namedWindow(self.window_name)

        self.image_sub = self.create_subscription(
            Image, 'camera/image_raw', self.image_callback, 10
        )

        self.tag_sub = self.create_subscription(
            PoseStamped, 'camera/tag_pose', self.tag_callback, 10
        )

        self.ee_sub = self.create_subscription(
            Pose, 'arm/current_cartesian_pose', self.ee_callback, 10
        )

        self.target_pub = self.create_publisher(
            Pose, 'arm/target_cartesian_pose', 10
        )

        self.timer = self.create_timer(0.05, self.control_loop)

        self.get_logger().info(
            "Press 's' to start, 'a' to approve, 'x' to skip current pose, Esc to stop."
        )

    def build_poses(self):
        specs = [
            # x, y, z (mm), roll, pitch, yaw (deg)

            (479.6, -56.9, 245.9, 6.5, -71.8, 166.3),
            (472.3, -77.7, 245.9, 18.6, -70.8, 154.2),
            (465.1, -98.5, 245.9, 30.7, -69.7, 142.2),
            (457.8, -119.3, 245.8, 42.8, -68.6, 130.0),
            (450.6, -140.1, 245.8, 50.8, -66.1, 122.0),

            (443.4, -160.9, 245.8, 57.5, -63.1, 115.3),
            (436.1, -181.7, 245.7, 64.2, -60.1, 108.6),
            (428.9, -202.5, 245.7, 69.2, -56.8, 103.5),
            (421.6, -223.3, 245.7, 72.6, -53.2, 100.2),
            (414.3, -244.1, 245.6, 75.9, -49.5, 96.8),

            (407.9, -258.3, 251.5, 78.5, -45.4, 94.2),
            (403.7, -252.5, 275.2, 78.9, -40.4, 94.0),
            (399.5, -246.7, 298.9, 79.2, -35.3, 93.7),
            (395.3, -240.9, 322.5, 79.6, -30.3, 93.4),
            (391.2, -235.1, 346.2, 79.9, -25.3, 93.3),

            (387.0, -229.3, 369.9, 80.2, -20.2, 93.2),
            (382.8, -223.5, 393.6, 80.4, -15.2, 93.0),
            (378.7, -217.8, 417.3, 80.7, -10.1, 93.0),
            (374.5, -212.0, 441.0, 80.9, -5.1, 93.0),
            (370.3, -206.2, 464.6, 81.1, 0.0, 92.9),

            (368.9, -185.9, 476.9, 81.9, 6.1, 92.3),
            (370.4, -151.0, 477.9, 83.3, 13.2, 91.1),
            (371.8, -116.0, 478.9, 84.7, 20.3, 89.8),
            (373.3, -81.1, 479.9, 86.1, 27.4, 88.6),
            (374.7, -46.1, 480.9, 87.3, 34.6, 87.7),

            (376.2, -11.2, 481.9, 88.4, 41.8, 86.8),
            (377.7, 23.8, 482.9, 89.6, 49.0, 85.9),
            (379.2, 58.8, 483.9, 91.0, 56.3, 85.5),
            (380.6, 93.7, 484.9, 92.4, 63.5, 85.1),
            (382.0, 128.6, 485.9, 93.8, 70.7, 84.7),

            (390.0, 131.5, 463.8, 92.0, 60.2, 85.6),
            (400.1, 123.7, 434.1, 89.3, 43.9, 86.9),
            (410.1, 116.0, 404.3, 86.5, 27.5, 88.2),
            (420.1, 108.3, 374.5, 82.9, 11.4, 90.8),
            (430.2, 100.6, 344.7, 78.6, -4.5, 94.9),

            (440.3, 92.8, 314.9, 74.3, -20.4, 99.0),
            (450.4, 85.1, 285.2, 65.5, -34.9, 107.5),
            (460.5, 77.3, 255.4, 43.5, -45.5, 129.4),
            (470.6, 69.6, 225.7, 21.4, -56.1, 151.3),
            (480.6, 61.8, 195.9, -0.7, -66.6, 173.2),
        ]
        poses = []
        for x, y, z, roll, pitch, yaw in specs:
            q = euler_to_quaternion(roll, pitch, yaw)

            poses.append(Pose(
                position=Point(x=float(x)/1000.0, y=float(y)/1000.0, z=float(z)/1000.0),
                orientation=Quaternion(x=q[0], y=q[1], z=q[2], w=q[3]),
            ))
        return poses

    def ee_callback(self, msg):
        self.latest_ee = msg

    def tag_callback(self, msg: PoseStamped):
        self.latest_tag = msg.pose

    def image_callback(self, msg):
        frame = image_msg_to_bgr(msg)

        cv.putText(
            frame,
            f'{self.state.name}  {self.pose_index}/{len(self.poses)}',
            (20, 35),
            cv.FONT_HERSHEY_SIMPLEX,
            0.8,
            (0, 255, 0),
            2,
        )

        tag_ok = self.latest_tag is not None
        ee_ok = self.latest_ee is not None
        cv.putText(
            frame,
            f'TAG: {"OK" if tag_ok else "MISSING"}   EE: {"OK" if ee_ok else "MISSING"}',
            (20, 65),
            cv.FONT_HERSHEY_SIMPLEX,
            0.7,
            (0, 255, 0) if tag_ok else (0, 0, 255),
            2,
        )

        cv.imshow(self.window_name, frame)
        key = cv.waitKey(1) & 0xFF

        if key == ord('s') and self.state in [State.IDLE, State.DONE]:
            self.ee_samples.clear()
            self.tag_samples.clear()
            self.pose_index = 0
            self.state = State.MOVE

        elif key == ord('a') and self.state == State.APPROVE:
            self.approved = True

        elif key == ord('x') and self.state in [State.WAIT, State.APPROVE]:
            self._skip_pose('skipped by user')

        elif key == 27:
            rclpy.shutdown()

    def control_loop(self):
        if self.state == State.MOVE:
            if self.pose_index >= len(self.poses):
                self.state = State.SOLVE
                return

            self.target_pub.publish(self.poses[self.pose_index])
            self.settle_start = None
            self.approved = False

            self.latest_tag = None
            self.move_start = time.monotonic()
            self.state = State.WAIT

            self.get_logger().info(
                f'Moving to pose {self.pose_index + 1}/{len(self.poses)}'
            )

        elif self.state == State.WAIT:
            if time.monotonic() - self.move_start > self.move_timeout:
                self._skip_pose('timed out reaching pose')
                return

            if self.latest_ee is None:
                return

            target = self.poses[self.pose_index]

            if poses_close(
                self.latest_ee,
                target,
                self.position_tolerance_mm,
                self.angle_tolerance_deg,
            ):
                if self.settle_start is None:
                    self.settle_start = time.monotonic()

                elif time.monotonic() - self.settle_start >= self.settle_time:
                    if self.require_approval:
                        self.state = State.APPROVE
                        self.get_logger().info("Press 'a' to capture, 'x' to skip.")
                    elif self.latest_tag is not None:
                        self.state = State.CAPTURE
            else:
                self.settle_start = None

        elif self.state == State.APPROVE:
            if self.approved and self.latest_tag is not None and self.latest_ee is not None:
                self.state = State.CAPTURE

        elif self.state == State.CAPTURE:
            self.ee_samples.append(copy.deepcopy(self.latest_ee))
            self.tag_samples.append(copy.deepcopy(self.latest_tag))

            self.get_logger().info(
                f'Captured sample {len(self.ee_samples)}'
            )

            self.pose_index += 1
            self.state = State.MOVE

        elif self.state == State.SOLVE:
            self.run_calibration()
            self.state = State.DONE

    def _skip_pose(self, reason):
        self.get_logger().warn(f'Pose {self.pose_index}: skipping ({reason}).')
        self.pose_index += 1
        self.state = State.MOVE

    def run_calibration(self):
        if len(self.ee_samples) < 3:
            self.get_logger().error(
                f'Only {len(self.ee_samples)} pose pairs captured; need at '
                f'least 3 (10-15+ recommended) to solve calibrateHandEye. Aborting solve.'
            )
            return

        R_gripper2base = []
        t_gripper2base = []
        R_target2cam = []
        t_target2cam = []

        for idx, (ee_pose, tag_pose) in enumerate(zip(self.ee_samples, self.tag_samples)):
            R_g2b, t_g2b = pose_to_rt(ee_pose, 1.0)
            R_t2c, t_t2c = pose_to_rt(tag_pose, 1.0)

            R_gripper2base.append(R_g2b)
            t_gripper2base.append(t_g2b)
            R_target2cam.append(R_t2c)
            t_target2cam.append(t_t2c)

            det_g2b = np.linalg.det(R_g2b)
            det_t2c = np.linalg.det(R_t2c)
            self.get_logger().info(
                f'--- sample {idx} ---\n'
                f'R_gripper2base (det={det_g2b:+.3f}):\n{np.array2string(R_g2b, precision=4)}\n'
                f't_gripper2base (m): {t_g2b.flatten()}\n'
                f'R_target2cam (det={det_t2c:+.3f}):\n{np.array2string(R_t2c, precision=4)}\n'
                f't_target2cam (m): {t_t2c.flatten()}'
            )
            if abs(det_g2b - 1.0) > 0.01 or abs(det_t2c - 1.0) > 0.01:
                self.get_logger().error(
                    f'Sample {idx}: rotation matrix determinant is not +1 '
                    f'(gripper2base={det_g2b:+.3f}, target2cam={det_t2c:+.3f}) -- '
                    'this is a mirror/reflection, not a rotation. Check your '
                    'quaternion source and any manual axis remapping.'
                )

        max_angle_diff = 0.0
        for i in range(len(R_gripper2base)):
            for j in range(i + 1, len(R_gripper2base)):
                R_rel = R_gripper2base[i].T @ R_gripper2base[j]
                cos_a = np.clip((np.trace(R_rel) - 1) / 2, -1.0, 1.0)
                max_angle_diff = max(max_angle_diff, np.degrees(np.arccos(cos_a)))

        self.get_logger().info(f'Max pairwise gripper rotation spread: {max_angle_diff:.2f} deg')
        if max_angle_diff < 5.0:
            self.get_logger().error(
                f'Rotation spread across captured poses is only {max_angle_diff:.2f} deg -- '
                'calibrateHandEye cannot solve for camera orientation without varied rotation. '
                'Add poses with different roll/pitch/yaw, not just different position, then '
                're-run. Aborting solve (refusing to write a degenerate transform).'
            )
            return

        R_base2gripper = [R.T for R in R_gripper2base]
        t_base2gripper = [
            -R.T @ t for R, t in zip(R_gripper2base, t_gripper2base)
        ]

        R_cam2base, t_cam2base = cv.calibrateHandEye(
            R_base2gripper,
            t_base2gripper,
            R_target2cam,
            t_target2cam,
            method=cv.CALIB_HAND_EYE_TSAI,
        )

        T_cam2base = np.eye(4)
        T_cam2base[:3, :3] = R_cam2base
        T_cam2base[:3, 3] = t_cam2base.flatten()

        data = {
            'cam2base': {
                'translation_m': t_cam2base.flatten().tolist(),
                'rotation_matrix': R_cam2base.tolist(),
                'transform_4x4': T_cam2base.tolist(),
            }
        }

        with open(self.calibration_yaml, 'w') as file:
            yaml.safe_dump(data, file, sort_keys=False)

        self.get_logger().info(
            f'Saved {self.calibration_yaml} using {len(self.ee_samples)} samples. '
            'Usage: p_base = R @ p_cam + t'
        )

    def cleanup(self):
        cv.destroyAllWindows()


def pose_to_rt(pose, position_scale):
    R = quaternion_to_matrix(pose.orientation)

    t = np.array([
        [pose.position.x * position_scale],
        [pose.position.y * position_scale],
        [pose.position.z * position_scale],
    ])

    return R, t

def quaternion_to_matrix(q):
    values = np.array([q.x, q.y, q.z, q.w], dtype=float)
    x, y, z, w = values / np.linalg.norm(values)

    return np.array([
        [1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * z + y * w)],
        [2 * (x * y + z * w), 1 - 2 * (x * x + z * z), 2 * (y * z - x * w)],
        [2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y)],
    ])

def euler_to_quaternion(roll_deg, pitch_deg, yaw_deg):
    roll = math.radians(roll_deg)
    pitch = math.radians(pitch_deg)
    yaw = math.radians(yaw_deg)

    cr = math.cos(roll / 2)
    sr = math.sin(roll / 2)
    cp = math.cos(pitch / 2)
    sp = math.sin(pitch / 2)
    cy = math.cos(yaw / 2)
    sy = math.sin(yaw / 2)

    return [
        sr * cp * cy - cr * sp * sy,
        cr * sp * cy + sr * cp * sy,
        cr * cp * sy - sr * sp  * cy,
        cr * cp * cy + sr * sp * sy,
    ]

def poses_close(current, target, position_tolerance, angle_tolerance):
    position_error = np.linalg.norm([
        current.position.x - target.position.x,
        current.position.y - target.position.y,
        current.position.z - target.position.z,
    ])

    if position_error > position_tolerance:
        return False

    R_current = quaternion_to_matrix(current.orientation)
    R_target = quaternion_to_matrix(target.orientation)
    R_error = R_current.T @ R_target

    cos_angle = np.clip((np.trace(R_error) - 1) / 2, -1.0, 1.0)
    angle_error = np.degrees(np.arccos(cos_angle))

    return angle_error <= angle_tolerance

def image_msg_to_bgr(msg):
    if msg.encoding != 'bgr8':
        return None
    frame = np.frombuffer(msg.data, dtype=np.uint8)
    return frame.reshape((msg.height, msg.width, 3)).copy()

def main(args=None):
    rclpy.init(args=args)
    node = CalibrationControllerNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.cleanup()
    node.destroy_node()

    if rclpy.ok():
        rclpy.shutdown()


if __name__ == '__main__':
    main()