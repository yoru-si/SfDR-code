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
            package='image_tools',
            executable='showimage',
            name='showimage'
        ),
    ])
