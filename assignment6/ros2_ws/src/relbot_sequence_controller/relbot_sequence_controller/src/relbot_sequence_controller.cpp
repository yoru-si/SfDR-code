#include "steering.hpp"
#include "relbot_msgs/msg/relbot_motors.hpp"  

#define Linear_velocity 2.0
#define radius 0.1
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



























