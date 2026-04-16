/*
file: relbot_sequence_controller.cpp
Author: Raghavendran Srinivasan(s3656721), Srikrishnan Srinivasan(s3603288)
Group number: SDfR-PPD 16

Description: Code which handles velocity control of the motors based on the object detection
*/

#include "steering.hpp"
#include "relbot_msgs/msg/relbot_motors.hpp"  

#define Linear_velocity 0.5
#define radius 0.05
#define wheel2wheel_distance 0.20

using std::placeholders::_1;

SteerRelbot::SteerRelbot() : Node("steer_relbot") {
    RCLCPP_INFO(this->get_logger(), "Init");
    create_topics();
    RCLCPP_INFO(this->get_logger(), "Created Topics");

    //Initialize time
    start_time_ = this->get_clock()->now();


    x_subscription = this->create_subscription<example_interfaces::msg::Float64>("/colour_detector/x", 10, std::bind(&SteerRelbot::x_callback, this, _1));
    y_subscription = this->create_subscription<example_interfaces::msg::Float64>("/colour_detector/y", 10, std::bind(&SteerRelbot::y_callback, this, _1));

    timer_ = this->create_wall_timer(std::chrono::duration<double>(1.0/DEFAULT_SETPOINT_STREAM),
                                     std::bind(&SteerRelbot::timer_callback, this));
}

void SteerRelbot::create_topics() {
    motor_cmd_topic_ = this->create_publisher<relbot_msgs::msg::RelbotMotors>(
        "/input/motor_cmd", 1);
}

void SteerRelbot::x_callback(const example_interfaces::msg::Float64::SharedPtr msg) {
    x_pos = msg->data;
}

void SteerRelbot::y_callback(const example_interfaces::msg::Float64::SharedPtr msg) {
    y_pos = msg->data;
}

void SteerRelbot::calculate_velocity() {
    double center_x = 60;
    double center_y = 60;

    // error = object position - image center
    double error_x = x_pos - center_x;  //  rotation
    double error_y = y_pos - center_y;  //   forward backward

    double tau = 1.0;  // time constant

    // first order controller
    double x_dot = error_y / tau;      // forward velocity 
    double theta_dot = error_x / tau;  // angular velocity

    // scale down 
    double scale = 0.05;
    double v_linear  = x_dot * scale;
    double v_angular = theta_dot * scale;

    // differential drive conversion
    left_velocity  = -(v_linear - v_angular * wheel2wheel_distance / 2.0)/radius;
    right_velocity =  (v_linear + v_angular * wheel2wheel_distance / 2.0)/radius; 
    }

void SteerRelbot::timer_callback() {
    calculate_velocity();
    
    relbot_msgs::msg::RelbotMotors cmd;
    cmd.left_wheel_vel = left_velocity;
    cmd.right_wheel_vel = right_velocity;
    motor_cmd_topic_->publish(cmd);
    }


int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SteerRelbot>());
    rclcpp::shutdown();
    return 0;
}



























