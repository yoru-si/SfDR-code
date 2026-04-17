Package relbot_sequence_controller
-----------------------------------------------
#### Description: 
This package contains a skeleton node that you will have to supplement with an algorithm.

#### 1. Node: `colour_detector`
This node processes raw camera feeds to identify specific colors (e.g., green) and calculates the pixel coordinates of the detected object.

#### Subscribed Topics
* `/image` (`sensor_msgs/msg/Image`): The raw image feed from the `cam2image` node.

#### Published Topics
* `/colour_detector/x` (`example_interfaces/msg/Float64`): The X-coordinate of the detected color center.
* `/colour_detector/y` (`example_interfaces/msg/Float64`): The Y-coordinate of the detected color center.

#### Run:
* `ros2 run relbot_sequence_controller colour_detector`

#### Parameters
-NA

---

#### 2. Node: `relbot_sequence_controller`
Calculates twist and publishes the left and motor velocities.

#### Output:
`/input/motor_cmd`
- Type: example_interfaces/msg/Float64


#### Run:
To start the node run the following command:

`ros2 run relbot_sequence_controller steer_robot`

#### Parameters:
-

#### Core components:
- calculate_velocity(): The function that you will have to alter.
- timer_callback(): publishes the velocity to both wheel 30 times per second.
