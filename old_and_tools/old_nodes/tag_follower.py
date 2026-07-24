#!/usr/bin/env python3
"""
Tag Follower ROS2 node for the Surgical Cleaning Project
written by Connor McKelvey, 2026

Loads a saved cam2base_calibration.yaml, subscribes to camera/tag_pose
(PoseStamped, camera frame), converts each detection into the robot base
frame using p_base = R_cam2base @ p_cam + t_cam2base, and publishes it to
arm/target_cartesian_pose so the arm tracks the tag.

Press 's' in the video window to start/stop following, Esc to quit.
"""

import os
import time

import cv2 as cv
import numpy as np
import rclpy
import yaml
from geometry_msgs.msg import Point, Pose, PoseStamped, Quaternion
from rclpy.node import Node
from sensor_msgs.msg import Image

# --- config ------------------------------------------------------------------
CALIBRATION_YAML = 'cam2base_calibration.yaml'

# True: gripper orientation follows the tag's detected orientation.
# False (default, safer): gripper holds FIXED_ORIENTATION and only chases
# position -- the tag's own orientation convention (from your ChArUco
# detector) has no guarantee of being a sensible/reachable gripper approach
# angle, so blindly copying it can produce awkward or unsafe poses.
USE_TAG_ORIENTATION = False
FIXED_ORIENTATION = Quaternion(x=0.0, y=1.0, z=0.0, w=0.0)  # EDIT: identity is just a placeholder

MIN_PUBLISH_INTERVAL = 0.5    # seconds between published targets (rate limit)
MIN_MOVE_THRESHOLD_MM = 5.0   # ignore re-detections that moved less than this (noise gating)
# -------------------------------------------------------------------------------

_ENCODING_TO_CVTYPE = {
    'bgr8': None,
    'rgb8': cv.COLOR_RGB2BGR,
    'bgra8': cv.COLOR_BGRA2BGR,
    'rgba8': cv.COLOR_RGBA2BGR,
    'mono8': cv.COLOR_GRAY2BGR,
}


def image_msg_to_bgr(msg):
    if msg.encoding not in _ENCODING_TO_CVTYPE:
        raise ValueError(f"Unsupported image encoding: {msg.encoding}")
    channels = 1 if msg.encoding == 'mono8' else (4 if msg.encoding in ('bgra8', 'rgba8') else 3)
    frame = np.frombuffer(msg.data, dtype=np.uint8).reshape(msg.height, msg.width, channels)
    convert = _ENCODING_TO_CVTYPE[msg.encoding]
    return cv.cvtColor(frame, convert) if convert is not None else frame.copy()


def quaternion_to_matrix(q):
    values = np.array([q.x, q.y, q.z, q.w], dtype=float)
    x, y, z, w = values / np.linalg.norm(values)
    return np.array([
        [1 - 2 * (y * y + z * z), 2 * (x * y - z * w),     2 * (x * z + y * w)],
        [2 * (x * y + z * w),     1 - 2 * (x * x + z * z), 2 * (y * z - x * w)],
        [2 * (x * z - y * w),     2 * (y * z + x * w),     1 - 2 * (x * x + y * y)],
    ])


def matrix_to_quaternion(R):
    """Shepperd's method (numerically robust)."""
    trace = np.trace(R)
    if trace > 0:
        s = 0.5 / np.sqrt(trace + 1.0)
        w = 0.25 / s
        x = (R[2, 1] - R[1, 2]) * s
        y = (R[0, 2] - R[2, 0]) * s
        z = (R[1, 0] - R[0, 1]) * s
    elif R[0, 0] > R[1, 1] and R[0, 0] > R[2, 2]:
        s = 2.0 * np.sqrt(1.0 + R[0, 0] - R[1, 1] - R[2, 2])
        w = (R[2, 1] - R[1, 2]) / s
        x = 0.25 * s
        y = (R[0, 1] + R[1, 0]) / s
        z = (R[0, 2] + R[2, 0]) / s
    elif R[1, 1] > R[2, 2]:
        s = 2.0 * np.sqrt(1.0 + R[1, 1] - R[0, 0] - R[2, 2])
        w = (R[0, 2] - R[2, 0]) / s
        x = (R[0, 1] + R[1, 0]) / s
        y = 0.25 * s
        z = (R[1, 2] + R[2, 1]) / s
    else:
        s = 2.0 * np.sqrt(1.0 + R[2, 2] - R[0, 0] - R[1, 1])
        w = (R[1, 0] - R[0, 1]) / s
        x = (R[0, 2] + R[2, 0]) / s
        y = (R[1, 2] + R[2, 1]) / s
        z = 0.25 * s
    return Quaternion(x=float(x), y=float(y), z=float(z), w=float(w))


class TagFollowerNode(Node):

    def __init__(self):
        super().__init__('tag_follower')

        self.R_cam2base, self.t_cam2base = self.load_calibration(CALIBRATION_YAML)

        self.following = False
        self.latest_tag = None
        self.last_publish_time = 0.0
        self.last_published_pos_mm = None

        self.window_name = 'Tag Follower'
        cv.namedWindow(self.window_name)

        self.image_sub = self.create_subscription(
            Image, 'camera/image_raw', self.image_callback, 10
        )
        self.tag_sub = self.create_subscription(
            PoseStamped, 'camera/tag_pose', self.tag_callback, 10
        )
        self.target_pub = self.create_publisher(
            Pose, 'arm/target_cartesian_pose', 10
        )

        self.get_logger().info("Press 's' to start/stop following the tag, Esc to quit.")

    def load_calibration(self, yaml_path):
        if not os.path.isfile(yaml_path):
            raise FileNotFoundError(
                f"No calibration file found at '{yaml_path}'. Run calibration_controller first."
            )

        with open(yaml_path, 'r') as f:
            data = yaml.safe_load(f)

        if not data or 'cam2base' not in data:
            raise ValueError(f"'{yaml_path}' doesn't contain a 'cam2base' entry.")

        entry = data['cam2base']
        R = np.array(entry['rotation_matrix'])
        t = np.array(entry['translation_m']).reshape(3, 1)

        det = np.linalg.det(R)
        if abs(det - 1.0) > 0.01:
            self.get_logger().warn(
                f"Loaded rotation matrix has determinant {det:+.3f}, expected +1.0 -- "
                "this calibration may be invalid."
            )

        return R, t

    def tag_callback(self, msg: PoseStamped):
        self.latest_tag = msg.pose
        if self.following:
            self.maybe_publish_target()

    def maybe_publish_target(self):
        if self.latest_tag is None:
            return

        now = time.monotonic()
        if now - self.last_publish_time < MIN_PUBLISH_INTERVAL:
            return

        p_cam = np.array([
            self.latest_tag.position.x,
            self.latest_tag.position.y,
            self.latest_tag.position.z,
        ]).reshape(3, 1)

        p_base_mm = (self.R_cam2base @ p_cam + self.t_cam2base).flatten() * 1000.0

        if self.last_published_pos_mm is not None:
            moved = np.linalg.norm(p_base_mm - self.last_published_pos_mm)
            if moved < MIN_MOVE_THRESHOLD_MM:
                return

        if USE_TAG_ORIENTATION:
            R_pose_cam = quaternion_to_matrix(self.latest_tag.orientation)
            orientation = matrix_to_quaternion(self.R_cam2base @ R_pose_cam)
        else:
            orientation = FIXED_ORIENTATION

        target = Pose(
            position=Point(x=float(p_base_mm[0]), y=float(p_base_mm[1]), z=float(p_base_mm[2])),
            orientation=orientation,
        )
        self.target_pub.publish(target)

        self.last_publish_time = now
        self.last_published_pos_mm = p_base_mm

        self.get_logger().info(
            f'Following tag -> target (mm): '
            f'[{p_base_mm[0]:.1f}, {p_base_mm[1]:.1f}, {p_base_mm[2]:.1f}]'
        )

    def image_callback(self, msg):
        frame = image_msg_to_bgr(msg)

        status = 'FOLLOWING' if self.following else 'PAUSED'
        color = (0, 255, 0) if self.following else (0, 0, 255)
        cv.putText(frame, status, (20, 35), cv.FONT_HERSHEY_SIMPLEX, 0.8, color, 2)

        tag_ok = self.latest_tag is not None
        cv.putText(
            frame, f'TAG: {"OK" if tag_ok else "MISSING"}', (20, 65),
            cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0) if tag_ok else (0, 0, 255), 2
        )

        cv.imshow(self.window_name, frame)
        key = cv.waitKey(1) & 0xFF

        if key == ord('s'):
            self.following = not self.following
            self.get_logger().info(f'Following {"enabled" if self.following else "disabled"}.')
            if self.following:
                # allow an immediate publish on resume, bypassing rate/move gates
                self.last_publish_time = 0.0
                self.last_published_pos_mm = None
        elif key == 27:
            rclpy.shutdown()

    def cleanup(self):
        cv.destroyAllWindows()


def main(args=None):
    rclpy.init(args=args)
    node = TagFollowerNode()

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