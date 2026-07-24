import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection


BASE_DIAMETER = 0.076

BOARD_WIDTH = 0.100
BOARD_HEIGHT = 0.100
BOARD_ANGLE_DEG = 145.0

# Base center.
base_point = np.array([
    0.0,
    0.0,
    0.0
])

# Offset from the base center to the board bottom-left corner.
board_origin = base_point + np.array([
     0.05970100,
    -0.04882843,
     0.09867100
])


def get_base_axes():
    """
    Base frame expressed in the plotting/world frame.

    Base +X = world +X
    Base +Y = world -Y
    Base +Z = world -Z
    """
    base_x = np.array([
        1.0,
        0.0,
        0.0
    ])

    base_y = np.array([
         0.0,
        -1.0,
         0.0
    ])

    base_z = np.array([
         0.0,
         0.0,
        -1.0
    ])

    return base_x, base_y, base_z


def get_board_axes(angle_deg):
    """
    Board frame expressed in the plotting/world frame.

    Board +X = right across the board
    Board +Y = up the board
    Board +Z = into the board
    """
    angle = np.deg2rad(angle_deg)

    board_x = np.array([
        np.cos(angle),
        0.0,
        np.sin(angle)
    ])

    board_y = np.array([
        0.0,
        1.0,
        0.0
    ])

    # Positive Z points into the board.
    board_z = np.cross(board_x, board_y)

    board_x /= np.linalg.norm(board_x)
    board_y /= np.linalg.norm(board_y)
    board_z /= np.linalg.norm(board_z)

    return board_x, board_y, board_z


def get_board_corners(origin, width, height, angle_deg):
    """
    Return the four board corners.

    The origin is the bottom-left corner.
    Width follows board +X.
    Height follows board +Y.
    """
    board_x, board_y, _ = get_board_axes(angle_deg)

    bottom_left = origin
    bottom_right = origin + width * board_x
    top_left = origin + height * board_y
    top_right = bottom_right + height * board_y

    return np.array([
        bottom_left,
        bottom_right,
        top_right,
        top_left
    ])


def plot_circle_xy(ax, center, diameter, points=200):
    radius = diameter / 2.0
    angles = np.linspace(0.0, 2.0 * np.pi, points)

    x = center[0] + radius * np.cos(angles)
    y = center[1] + radius * np.sin(angles)
    z = np.full(points, center[2])

    ax.plot(
        x,
        y,
        z,
        linewidth=2,
        label='76 mm base circle'
    )


def plot_board(ax, origin, width, height, angle_deg):
    corners = get_board_corners(
        origin,
        width,
        height,
        angle_deg
    )

    closed_corners = np.vstack([
        corners,
        corners[0]
    ])

    ax.plot(
        closed_corners[:, 0],
        closed_corners[:, 1],
        closed_corners[:, 2],
        linewidth=2,
        label='100 mm board'
    )

    surface = Poly3DCollection(
        [corners],
        alpha=0.25
    )

    ax.add_collection3d(surface)

    return corners


def plot_coordinate_frame(ax, origin, x_axis, y_axis, z_axis, name, axis_length=0.04):
    ax.quiver(
        origin[0],
        origin[1],
        origin[2],
        x_axis[0] * axis_length,
        x_axis[1] * axis_length,
        x_axis[2] * axis_length,
        color='r',
        linewidth=2
    )

    ax.quiver(
        origin[0],
        origin[1],
        origin[2],
        y_axis[0] * axis_length,
        y_axis[1] * axis_length,
        y_axis[2] * axis_length,
        color='g',
        linewidth=2
    )

    ax.quiver(
        origin[0],
        origin[1],
        origin[2],
        z_axis[0] * axis_length,
        z_axis[1] * axis_length,
        z_axis[2] * axis_length,
        color='b',
        linewidth=2
    )

    x_label = origin + x_axis * axis_length
    y_label = origin + y_axis * axis_length
    z_label = origin + z_axis * axis_length

    ax.text(
        x_label[0],
        x_label[1],
        x_label[2],
        f'{name} X'
    )

    ax.text(
        y_label[0],
        y_label[1],
        y_label[2],
        f'{name} Y'
    )

    ax.text(
        z_label[0],
        z_label[1],
        z_label[2],
        f'{name} Z'
    )


def set_axes_equal(ax):
    x_limits = ax.get_xlim3d()
    y_limits = ax.get_ylim3d()
    z_limits = ax.get_zlim3d()

    ranges = np.array([
        x_limits[1] - x_limits[0],
        y_limits[1] - y_limits[0],
        z_limits[1] - z_limits[0]
    ])

    centers = np.array([
        np.mean(x_limits),
        np.mean(y_limits),
        np.mean(z_limits)
    ])

    radius = np.max(np.abs(ranges)) / 2.0

    ax.set_xlim(
        centers[0] - radius,
        centers[0] + radius
    )

    ax.set_ylim(
        centers[1] - radius,
        centers[1] + radius
    )

    ax.set_zlim(
        centers[2] - radius,
        centers[2] + radius
    )


def main():
    base_x, base_y, base_z = get_base_axes()

    board_x, board_y, board_z = get_board_axes(
        BOARD_ANGLE_DEG
    )

    base_rotation_matrix = np.column_stack([
        base_x,
        base_y,
        base_z
    ])

    board_rotation_matrix = np.column_stack([
        board_x,
        board_y,
        board_z
    ])

    corners = get_board_corners(
        board_origin,
        BOARD_WIDTH,
        BOARD_HEIGHT,
        BOARD_ANGLE_DEG
    )

    print('Base center:')
    print(base_point)

    print('\nBoard bottom-left corner:')
    print(board_origin)

    print('\nBase axes expressed in the world frame:')
    print('X:')
    print(base_x)

    print('Y:')
    print(base_y)

    print('Z:')
    print(base_z)

    print('\nBase rotation matrix:')
    print(base_rotation_matrix)

    print('\nBoard axes expressed in the world frame:')
    print('X, right:')
    print(board_x)

    print('Y, up:')
    print(board_y)

    print('Z, into board:')
    print(board_z)

    print('\nBoard rotation matrix:')
    print(board_rotation_matrix)

    print('\nBoard corners:')
    print('Bottom-left:')
    print(corners[0])

    print('Bottom-right:')
    print(corners[1])

    print('Top-right:')
    print(corners[2])

    print('Top-left:')
    print(corners[3])

    figure = plt.figure()
    ax = figure.add_subplot(111, projection='3d')

    plot_circle_xy(
        ax,
        base_point,
        BASE_DIAMETER
    )

    plot_board(
        ax,
        board_origin,
        BOARD_WIDTH,
        BOARD_HEIGHT,
        BOARD_ANGLE_DEG
    )

    plot_coordinate_frame(
        ax,
        base_point,
        base_x,
        base_y,
        base_z,
        'Base',
        axis_length=0.05
    )

    plot_coordinate_frame(
        ax,
        board_origin,
        board_x,
        board_y,
        board_z,
        'Board',
        axis_length=0.04
    )

    ax.scatter(
        base_point[0],
        base_point[1],
        base_point[2],
        s=80,
        label='Base center'
    )

    ax.scatter(
        board_origin[0],
        board_origin[1],
        board_origin[2],
        s=80,
        label='Board origin'
    )

    ax.plot(
        [base_point[0], board_origin[0]],
        [base_point[1], board_origin[1]],
        [base_point[2], board_origin[2]],
        linestyle='--',
        label='Base-to-board offset'
    )

    ax.set_xlabel('World X, meters')
    ax.set_ylabel('World Y, meters')
    ax.set_zlabel('World Z, meters')
    ax.set_title('Base and board coordinate frames')
    ax.legend()

    set_axes_equal(ax)
    plt.show()


if __name__ == '__main__':
    main()