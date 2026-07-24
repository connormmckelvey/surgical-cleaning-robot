"""
Static transform from the ChArUco-board pose on the hand puck
to the cleaning-puck base pose.

Input:
    tag_pose represents camera_T_board

Output:
    returned Pose represents camera_T_base
"""

import numpy as np
from scipy.spatial.transform import Rotation as R
from geometry_msgs.msg import Point, Pose, Quaternion


# Fixed transform from the detected board frame to the puck base frame.
#
# Translation is the base origin expressed in board coordinates.
BOARD_TO_BASE_POSITION = np.array([
    -0.00769116,
     0.04882843,
     0.11506964
])

# Base orientation relative to the board.
# Quaternion order used by scipy: [x, y, z, w]
BOARD_TO_BASE_QUATERNION = np.array([
    -0.30070580,
     0.0,
     0.95371695,
     0.0
])


def pose_to_matrix(pose):
    transform = np.eye(4)

    transform[:3, :3] = R.from_quat([
        pose.orientation.x,
        pose.orientation.y,
        pose.orientation.z,
        pose.orientation.w
    ]).as_matrix()

    transform[:3, 3] = [
        pose.position.x,
        pose.position.y,
        pose.position.z
    ]

    return transform


def matrix_to_pose(transform):
    quaternion = R.from_matrix(transform[:3, :3]).as_quat()

    return Pose(
        position=Point(
            x=float(transform[0, 3]),
            y=float(transform[1, 3]),
            z=float(transform[2, 3])
        ),
        orientation=Quaternion(
            x=float(quaternion[0]),
            y=float(quaternion[1]),
            z=float(quaternion[2]),
            w=float(quaternion[3])
        )
    )


def get_board_to_base_transform():
    transform = np.eye(4)

    transform[:3, :3] = R.from_quat(
        BOARD_TO_BASE_QUATERNION
    ).as_matrix()

    transform[:3, 3] = BOARD_TO_BASE_POSITION

    return transform


def handtag_to_puck(tag_pose):
    """
    Convert the detected board pose into the cleaning-puck base pose.

    Args:
        tag_pose: geometry_msgs/Pose representing camera_T_board.

    Returns:
        geometry_msgs/Pose representing camera_T_base.
    """
    camera_T_board = pose_to_matrix(tag_pose)
    board_T_base = get_board_to_base_transform()

    camera_T_base = camera_T_board @ board_T_base

    return matrix_to_pose(camera_T_base)