Build Instructions:
Packages which the tester must provide to build this workspace:
relbot_simulator, relbot_msgs

# on the same terminal:
cd ~/ros2_ws  #to your ros workspace
source /opt/ros/humble/setup.bash

colcon build --packages-select relbot_msgs
source install/setup.bash

colcon build
source install/setup.bash


Run Instructions: 

# for subassignment 6.2.1:
ros2 launch relbot_launch webcam_test_launch.py

# for subassignment 6.2.2:
ros2 launch relbot_launch colour_detector_launch.py
