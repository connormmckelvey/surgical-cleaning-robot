#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
import yaml


CALIBRATION_YAML = 'cam2base_calibration.yaml'
AXIS_LENGTH = 0.25


def plot_frame(ax, rotation, translation, name):
    colors = ['r', 'g', 'b']
    labels = ['X', 'Y', 'Z']

    for i in range(3):
        direction = rotation[:, i] * AXIS_LENGTH

        ax.quiver(
            translation[0],
            translation[1],
            translation[2],
            direction[0],
            direction[1],
            direction[2],
            color=colors[i],
            arrow_length_ratio=0.15,
        )

        end = translation + direction
        ax.text(end[0], end[1], end[2], f'{name} {labels[i]}')

    ax.scatter(translation[0], translation[1], translation[2])
    ax.text(translation[0], translation[1], translation[2], name)


def plot_translation_distances(ax, translation):
    x_point = np.array([
        translation[0],
        0.0,
        0.0,
    ])

    xy_point = np.array([
        translation[0],
        translation[1],
        0.0,
    ])

    camera_point = translation

    ax.plot(
        [0.0, x_point[0]],
        [0.0, x_point[1]],
        [0.0, x_point[2]],
        linestyle='--',
        color='r',
        label=f'X distance: {translation[0]:.3f} m',
    )

    ax.plot(
        [x_point[0], xy_point[0]],
        [x_point[1], xy_point[1]],
        [x_point[2], xy_point[2]],
        linestyle='--',
        color='g',
        label=f'Y distance: {translation[1]:.3f} m',
    )

    ax.plot(
        [xy_point[0], camera_point[0]],
        [xy_point[1], camera_point[1]],
        [xy_point[2], camera_point[2]],
        linestyle='--',
        color='b',
        label=f'Z distance: {translation[2]:.3f} m',
    )

    ax.text(
        x_point[0] / 2.0,
        0.0,
        0.0,
        f'X = {translation[0]:.3f} m',
    )

    ax.text(
        xy_point[0],
        translation[1] / 2.0,
        0.0,
        f'Y = {translation[1]:.3f} m',
    )

    ax.text(
        camera_point[0],
        camera_point[1],
        translation[2] / 2.0,
        f'Z = {translation[2]:.3f} m',
    )


def set_equal_axes(ax, points):
    center = np.mean(points, axis=0)
    max_range = np.max(np.ptp(points, axis=0))

    if max_range < AXIS_LENGTH * 2:
        max_range = AXIS_LENGTH * 2

    half_range = max_range / 2.0 + AXIS_LENGTH

    ax.set_xlim(center[0] - half_range, center[0] + half_range)
    ax.set_ylim(center[1] - half_range, center[1] + half_range)
    ax.set_zlim(center[2] - half_range, center[2] + half_range)


def main():
    with open(CALIBRATION_YAML, 'r') as file:
        calibration = yaml.safe_load(file)['cam2base']

    rotation_cam_to_base = np.array(
        calibration['rotation_matrix'],
        dtype=float,
    )

    translation_cam_in_base = np.array(
        calibration['translation_m'],
        dtype=float,
    )

    rotation_base = np.eye(3)
    translation_base = np.zeros(3)

    print('Camera position in base frame:')
    print(translation_cam_in_base)

    print('\nCamera rotation in base frame:')
    print(rotation_cam_to_base)

    print('\nRotation determinant:')
    print(np.linalg.det(rotation_cam_to_base))

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    plot_frame(
        ax,
        rotation_base,
        translation_base,
        'Base',
    )

    plot_frame(
        ax,
        rotation_cam_to_base,
        translation_cam_in_base,
        'Camera',
    )

    plot_translation_distances(
        ax,
        translation_cam_in_base,
    )

    set_equal_axes(
        ax,
        np.array([
            translation_base,
            translation_cam_in_base,
        ]),
    )

    ax.set_xlabel('Base X (m)')
    ax.set_ylabel('Base Y (m)')
    ax.set_zlabel('Base Z (m)')
    ax.set_title('Camera Frame Relative to Robot Base Frame')
    ax.legend()

    plt.show()


if __name__ == '__main__':
    main()