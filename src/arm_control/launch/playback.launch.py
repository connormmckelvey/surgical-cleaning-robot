from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    driver_node = Node(
        package='arm_control',
        executable='urobot_driver',
        name='urobot_driver',
        output='screen',
    )
    playback_controller_node = Node(
        package='arm_control',
        executable='playback_controller',
        name='playback_controller',
        output='screen'
    )
    playback_visualization_node = Node(
        package='arm_control',
        executable='training_visualization',
        name='training_visualization',
        output='screen'
    )
    return LaunchDescription([
        driver_node,
        playback_controller_node,
        playback_visualization_node,
    ])
