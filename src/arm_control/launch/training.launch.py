from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # 1. ZED Camera Driver
    camera_node = Node(
        package='arm_control',
        executable='zed_driver',
        name='zed_driver',
        output='screen',
        parameters=[{'show_visualization': False,'publish_raw':True}]
    )

    # 2. Force Sensor Driver
    force_sensor_driver_node = Node(
        package='arm_control',
        executable='force_sensor_driver',
        name='force_sensor_driver'
    )

    # 3. Training UI
    camera_training_node = Node(
        package='arm_control',
        executable='training_controller',
        name='training_controller',
        output='screen'
    )

    surface_spill_detection_node = Node(
        package='arm_control',
        executable='surface_spill_detection',
        name='surface_spill_detection',
        output='screen',
        parameters=[{'mode':"plot_live","clean":False}]
    )

    return LaunchDescription([
        camera_node,
        force_sensor_driver_node,
        camera_training_node,
        surface_spill_detection_node
    ])
