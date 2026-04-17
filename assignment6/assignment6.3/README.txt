Build Instructions:
Packages which the tester must provide to build this workspace:
relbot_simulator, relbot_msgs, relbot2turtlesim

# on the same terminal:
cd ~/ros2_ws  #to your ros workspace
source /opt/ros/humble/setup.bash

colcon build --packages-select relbot_msgs
source install/setup.bash

colcon build
source install/setup.bash


Run Instructions: 

# for subassignment 6.3:
ros2 launch relbot_launch relbot_turtlesim_launch.py


