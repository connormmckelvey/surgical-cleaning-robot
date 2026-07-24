#!/usr/bin/env python3
"""
Quick test/validation script for a saved cam2base hand-eye calibration.

Loads cam2base_calibration.yaml (as written by calibration_controller.py) and
converts a Pose given in the CAMERA frame into the equivalent Pose in the
ROBOT BASE frame:

    p_base = R_cam2base @ p_cam + t_cam2base
    R_pose_base = R_cam2base @ R_pose_cam

Edit YAML_PATH / POSITION_CAM / QUATERNION_CAM below and just run:
    python3 test_cam2base.py
"""

import os

import numpy as np
import yaml

# --- EDIT THESE -------------------------------------------------------------
YAML_PATH = 'cam2base_calibration.yaml'


# Position in the CAMERA frame, in meters.
POSITION_CAM = {
    'x': 0.71,
    'y': 0,
    'z': 0,
}

# Orientation in the CAMERA frame, as a quaternion.
QUATERNION_CAM = {
    'x': 1,
    'y': 0,
    'z': 0,
    'w': 0,
}
# -----------------------------------------------------------------------------


def quaternion_to_matrix(q):
    """q = [x, y, z, w]"""
    q = np.asarray(q, dtype=float)
    norm = np.linalg.norm(q)
    if norm == 0:
        raise ValueError("Quaternion has zero norm")
    x, y, z, w = q / norm
    return np.array([
        [1 - 2 * (y * y + z * z), 2 * (x * y - z * w),     2 * (x * z + y * w)],
        [2 * (x * y + z * w),     1 - 2 * (x * x + z * z), 2 * (y * z - x * w)],
        [2 * (x * z - y * w),     2 * (y * z + x * w),     1 - 2 * (x * x + y * y)],
    ])


def matrix_to_quaternion(R):
    """Returns [x, y, z, w]. Shepperd's method (numerically robust)."""
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
    return np.array([x, y, z, w])


def load_cam2base(yaml_path):
    if not os.path.isfile(yaml_path):
        raise FileNotFoundError(
            f"No calibration file found at '{yaml_path}'. "
            "Run the calibration_controller node first, or edit YAML_PATH."
        )

    with open(yaml_path, 'r') as f:
        data = yaml.safe_load(f)

    if not data or 'cam2base' not in data:
        raise ValueError(f"'{yaml_path}' doesn't contain a 'cam2base' entry -- is this the right file?")

    entry = data['cam2base']
    R = np.array(entry['rotation_matrix'])
    t = np.array(entry['translation_m']).reshape(3, 1)

    det = np.linalg.det(R)
    if abs(det - 1.0) > 0.01:
        print(f"WARNING: loaded rotation matrix has determinant {det:+.3f}, expected +1.0 "
              "-- this calibration may be invalid.")

    return R, t


def main():
    R_cam2base, t_cam2base = load_cam2base(YAML_PATH)

    p_cam = np.array([POSITION_CAM['x'], POSITION_CAM['y'], POSITION_CAM['z']]).reshape(3, 1)
    q_cam = [QUATERNION_CAM['x'], QUATERNION_CAM['y'], QUATERNION_CAM['z'], QUATERNION_CAM['w']]
    R_pose_cam = quaternion_to_matrix(q_cam)

    p_base = R_cam2base @ p_cam + t_cam2base
    R_pose_base = R_cam2base @ R_pose_cam
    q_base = matrix_to_quaternion(R_pose_base)

    p_base_m = p_base.flatten()
    p_base_mm = p_base_m * 1000.0

    print('--- Input (camera frame) ---')
    print(f'  position (m):  {p_cam.flatten()}')
    print(f'  quaternion:    {np.array(q_cam)}')
    print()
    print('--- Output (robot base frame) ---')
    print(f'  position (m):  {p_base_m}')
    print(f'  position (mm): {p_base_mm}   <- use this for arm/target_cartesian_pose')
    print(f'  quaternion:    {q_base}')


if __name__ == '__main__':
    main()