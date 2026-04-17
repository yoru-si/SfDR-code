from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='image_tools',
            executable='cam2image',
            name='cam2image',
            parameters=[{
                'frequency': 30.0,
            }]
        ),
        Node(
            package='relbot_sequence_controller',
            executable='colour_detector',
            name='colour_detector'
        ),
        Node(
            package='relbot_simulator',
            executable='relbot_simulator',
            name='relbot_simulator',
            ros_arguments=['--log-level', 'WARN'], 
        ),
        Node(
            package='image_tools',
            executable='showimage',
            name='showimage',
            ),
    ])
