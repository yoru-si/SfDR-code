SSH into the Relbot with the -X flag and follow the instructions

Build Instructions:
Packages which the tester must provide to build this workspace:
relbot_simulator, relbot_msgs, relbot2turtlesim, XRF2

# on the same terminal:
cd ~/ros2_ws  #to your ros workspace
source /opt/ros/humble/setup.bash


Run Instructions: 

### for subassignment 6.5.1(this assumes that /opt/ros/humble/setup.bash is sourced by your terminal on a new bash session):

colcon build --packages-select xrf2_msgs
source install/setup.bash
colcon build --packages-select relbot_msgs
source install/setup.bash
colcon build

# different terminal
source install/setup.bash
sudo ./build/sdfr_ppd/sdfr_ppd 

# different terminal
source install/setup.bash
ros2 run ros_xeno_bridge RosXenoBridge 

# original ros2_ws terminal
cd launch
ros2 launch relbot_launch.py

# different terminal
ros2 topic pub --once /XenoCmd std_msgs/msg/Int32 "{data: 1}"
# once hello from initialised is visible on terminal, run this: 
ros2 topic pub --once /XenoCmd std_msgs/msg/Int32 "{data: 2}"



