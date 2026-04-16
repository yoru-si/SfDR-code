from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='image_tools',
            executable='cam2image',
            name='cam2image'
        ),
        Node(
            package='relbot_adapter',
            executable='relbot_adapter',
            name='relbot_adapter',
            parameters=[{'robotmode':'real',
			            'use_twist_cmd':True}]
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
        ),
        Node(
            package='relbot_sequence_controller',
            executable='relbot_sequence_controller',
            name='relbot_sequence_controller',
        ),      
    ])
