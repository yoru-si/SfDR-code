# SDfR-PPD 16: Real-Time Differential Drive Controller
# provided from the template code and further modified to execute PWM actuation safely.
  
**Project:** SDfR-PPD Group 16  

## Overview
This package contains the hard real-time hardware controller (`sdfr_ppd`) for a differential drive robot, built on the Xenomai `XenoFrt20Sim` framework. It acts as the bridge between ROS 2 velocity commands and physical motor actuation.

## Core Functionality
The system operates a high-frequency Read-Calculate-Write loop inside the Xenomai real-time task:
1. Inputs: Reads raw encoder ticks via FPGA, handles wrap-around, and calculates wheel odometry (radians).
2. Control: Takes target wheel velocities from the ROS 2 bridge (`ros_msg`) and calculates the necessary control effort.
3. Outputs: Clamps the output to safe 12-bit PWM limits `[-2047, 2047]`, corrects for physical motor inversions, and actuates the hardware.

## System States
* Initialising: Wakes the controller via ROS-Xeno bridge and starts the data logger.
* Run: Executes the active control loop and PWM actuation.
* Stopping/Error: Safely halts actuation and shuts down the logger to prevent hardware damage.

## Logging
High-frequency system data is recorded natively via `XenoFileHandler` to `./xrf2_logging/sdfr_ppd.bin` for offline tuning.
