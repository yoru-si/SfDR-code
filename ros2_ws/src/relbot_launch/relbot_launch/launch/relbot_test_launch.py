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
            package='relbot_simulator',
            executable='relbot_simulator',
            name='relbot_simulator',
        ),     
    ])
