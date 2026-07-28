from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    arm_driver_node = Node(
        package='arm_control',
        executable='urobot_driver',
        name='urobot_driver',
        output='screen',
        parameters=[{
            'mode': 'cartesian_realtime',
            'validate_ik': True
        }]
    )

    camera_node = Node(
        package='arm_control',
        executable='zed_driver',
        name='zed_driver',
        output='screen',
        parameters=[{
            'show_visualization': False,
            'track_arm': True,
            'publish_raw': True
        }]
    )

    teleop_controller_node = Node(
        package='arm_control',
        executable='teleop_controller',
        name='teleop_controller',
        output='screen'
    )

    return LaunchDescription([
        arm_driver_node,
        camera_node,
        teleop_controller_node
    ])