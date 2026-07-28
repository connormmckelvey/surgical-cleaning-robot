from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    urobot_driver_node = Node(
        package='arm_control',
        executable='urobot_driver',
        name='urobot_driver',
        output='screen'
    )

    # 2. Camera Driver
    camera_node = Node(
        package='arm_control',
        executable='zed_driver',
        name='zed_driver',
        output='screen',
        parameters=[{'show_visualization': False, 'track_arm': False, 'track_tag': True,'publish_raw':True}]
    )
    # 4. Calibration Node
    calibration_node = Node(
        package='arm_control',
        executable='calibrate_controller',
        name='calibrate_controller',
        output='screen'
    )

    return LaunchDescription([
        urobot_driver_node,
        camera_node,
        calibration_node
    ])
