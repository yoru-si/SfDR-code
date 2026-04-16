/*
file: steering.hpp
Author: Raghavendran Srinivasan(s3656721), Srikrishnan Srinivasan(s3603288)
Group number: SDfR-PPD 16

Description: Header file with variable declarations and function prototypes of the sequence controller
and colour detection codes.
*/

#ifndef STEER_RELBOT_HPP_
#define STEER_RELBOT_HPP_

// CPP library headers

// ROS Client Library CPP
#include "rclcpp/rclcpp.hpp"

// message type for velocity
#include "example_interfaces/msg/float64.hpp"

#include "relbot_msgs/msg/relbot_motors.hpp"

class SteerRelbot : public rclcpp::Node
{
public:
    /**
     * @brief Construct a new steering object
     */
    SteerRelbot();

    const double DEFAULT_SETPOINT_STREAM = 30;  // How often the velocities are published per second

private:
    // Topics
    rclcpp::Publisher<relbot_msgs::msg::RelbotMotors>::SharedPtr motor_cmd_topic_;

    // Timer
    rclcpp::TimerBase::SharedPtr timer_;

    // attributes
    double left_velocity;
    double right_velocity;
    double x_pos;
    double y_pos;

    rclcpp::Time start_time_;

    rclcpp::Subscription<example_interfaces::msg::Float64>::SharedPtr x_subscription;
    rclcpp::Subscription<example_interfaces::msg::Float64>::SharedPtr y_subscription;
    
    void x_callback(const example_interfaces::msg::Float64::SharedPtr msg);
    void y_callback(const example_interfaces::msg::Float64::SharedPtr msg);
    
    // methods
    void create_topics();
    void timer_callback();
    void calculate_velocity();
};

#endif /*STEER_RELBOT_HPP_*/
