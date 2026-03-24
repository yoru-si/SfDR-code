


Build Instructions:

# on the same terminal:
cd ~/ros2_ws  #to your ros workspace
source /opt/ros/humble/setup.bash

colcon build --packages-select relbot_msgs
source install/setup.bash

colcon build
source install/setup.bash


Run Instructions: (run in the below given order)
# terminal 1 : simulator
source install/setup.bash
ros2 run relbot_simulator relbot_simulator

# terminal 2 : turtlesim
source install/setup.bash
ros2 run turtlesim turtlesim_node

# terminal 3 : relbot2turtlesim
source install/setup.bash
ros2 run relbot2turtlesim relbot2turtlesim

# terminal 4 : sequence controller
source install/setup.bash
ros2 run relbot_sequence_controller relbot_sequence_controller
