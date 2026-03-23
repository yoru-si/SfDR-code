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

    rclcpp::Time start_time_;

    enum PathType { STRAIGHT, CIRCLE, STRAIGHT_TURN, SQUARE };
    PathType current_path = SQUARE;

    // methods
    void create_topics();
    void timer_callback();
    void calculate_velocity();
};

#endif /*STEER_RELBOT_HPP_*/
