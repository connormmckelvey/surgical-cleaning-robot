from setuptools import find_packages, setup

package_name = 'arm_control'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', [
            'launch/teleop.launch.py',
            'launch/playback.launch.py',
            'launch/training.launch.py',
            'launch/calibrate.launch.py'
        ]),
    ],
    install_requires=['setuptools','lerobot', 'numpy', 'opencv-python', 'pyzed', 'matplotlib'],
    zip_safe=True,
    maintainer='Connor McKelvey',
    maintainer_email='connormmckelvey@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'lerobot_driver = arm_control.lerobot_driver:main',
            'lerobot_motionplan = arm_control.lerobot_motionplan:main',
            'training_controller = arm_control.training_controller:main',
            'playback_controller = arm_control.playback_controller:main',
            'lerobot_sim = arm_control.lerobot_sim:main',
            'force_sensor_driver = arm_control.force_sensor_driver:main',
            'zed_driver = arm_control.zed_driver:main',
            'surface_spill_detection = arm_control.surface_spill_detection:main',
            'training_visualization = arm_control.training_visualization:main',
            'urobot_driver = arm_control.urobot_driver:main',
            'calibrate_controller = arm_control.calibrate_controller:main',
            'tag_follower = arm_control.tag_follower:main',
            'teleop_controller = arm_control.teleop_controller:main',
            'keyboard_controller = arm_control.keyboard_controller:main'
        ],
    },
)
