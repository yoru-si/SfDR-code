from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='image_tools',
            executable='cam2image',
            name='cam2image',
            parameters=[{'width': 640,     # <--- Add or change this!
                        'height': 480     # <--- And this!
            }]
        ),
        Node(
            package='image_tools',
            executable='showimage',
            name='showimage'
        ),
    ])
