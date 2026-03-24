/*
file: relbot_sequence_controller.cpp
Author: Raghavendran Srinivasan(s3656721), Srikrishnan Srinivasan(s3603288)
Group number: SDfR-PPD 16

Description: Code which performs the sequence of patterns and has the logic behind it. 
*/

#include "steering.hpp"
#include "relbot_msgs/msg/relbot_motors.hpp"  


#define Linear_velocity 2.0
#define radius 1
#define wheel2wheel_distance 0.15

SteerRelbot::SteerRelbot() : Node("steer_relbot") {
    RCLCPP_INFO(this->get_logger(), "Init");
    create_topics();
    RCLCPP_INFO(this->get_logger(), "Created Topics");

    //Initialize time
    start_time_ = this->get_clock()->now();

    timer_ = this->create_wall_timer(std::chrono::duration<double>(1.0/DEFAULT_SETPOINT_STREAM),
                                     std::bind(&SteerRelbot::timer_callback, this));
}

void SteerRelbot::create_topics() {
    motor_cmd_topic_ = this->create_publisher<relbot_msgs::msg::RelbotMotors>(
        "/input/motor_cmd", 1);
}

void SteerRelbot::calculate_velocity() {
    
    double t = (this->get_clock()->now() - start_time_).seconds();
    switch(current_path) {
            case STRAIGHT:
                left_velocity = -Linear_velocity;
                right_velocity = Linear_velocity;
                break;

            case CIRCLE:
                left_velocity = -Linear_velocity * (radius - wheel2wheel_distance/2)/radius;
                right_velocity = Linear_velocity * (radius + wheel2wheel_distance/2)/radius;
                break;

            case STRAIGHT_TURN:
                if (t < 5.0) {  // go straight for 5 seconds
                    left_velocity = -Linear_velocity;
                    right_velocity = Linear_velocity;
                } else if (t < 5.0 + 3.24) {  // turn left 90 degrees
                    left_velocity = 1.0;
                    right_velocity = 1.0;
                } else {
                    left_velocity = 0;
                    right_velocity = 0;
                }
                break;

          case SQUARE: {
            double elapsed_time = (this->get_clock()->now() - start_time_).seconds();
            double straight_time = 15.0;
            double turn_radius = 0.1;  // fillet radisu of square
            double v_right = Linear_velocity * (turn_radius + wheel2wheel_distance/2) / turn_radius;
            double v_left  = -Linear_velocity * (turn_radius - wheel2wheel_distance/2) / turn_radius;

            // calculate turn time from math
            double omega = (v_right - v_left) / wheel2wheel_distance;
            double turn_time = (M_PI/2) / (omega / 27.5)*1.3; //fine tuning

            double side_time = straight_time + turn_time;
            double total_time = side_time * 4;

            if (elapsed_time >= total_time) {
                start_time_ = this->get_clock()->now();
                left_velocity = 0.0;
                right_velocity = 0.0;
                return;
            }

            double time_in_side = fmod(elapsed_time, side_time);

            if (time_in_side < straight_time) {
                left_velocity = -Linear_velocity;
                right_velocity = Linear_velocity;
            } else {
                left_velocity = v_left;
                right_velocity = v_right;
            }
        break;
        }

            case SEQUENCE: {
            double elapsed_time = (this->get_clock()->now() - start_time_).seconds();

            switch(sequence_step) {
            case 0:  // STRAIGHT for 5 seconds
                left_velocity = -Linear_velocity;
                right_velocity = Linear_velocity;
                if (elapsed_time > 15.0) {
                    sequence_step = 1;
                    start_time_ = this->get_clock()->now();
                }
                break;

            case 1:  // CIRCLE
                left_velocity = -Linear_velocity * (radius - wheel2wheel_distance/2)/radius;
                right_velocity = Linear_velocity * (radius + wheel2wheel_distance/2)/radius;
                if (elapsed_time > 90) {
                    sequence_step = 2;
                    start_time_ = this->get_clock()->now();
                }
                break;

            case 2:  // STRAIGHT then LEFT TURN
                if (elapsed_time < 15.0) {
                    left_velocity = -Linear_velocity;
                    right_velocity = Linear_velocity;
                } else if (elapsed_time < 15.0 + 3.24) {
                    left_velocity = 1.0;
                    right_velocity = 1.0;
                } else {
                    left_velocity = 0.0;
                    right_velocity = 0.0;
                    sequence_step = 3;
                    start_time_ = this->get_clock()->now();
                }
                break;

            case 3: {  // SQUARE
                double turn_radius = 0.1;
                double v_right = Linear_velocity * (turn_radius + wheel2wheel_distance/2) / turn_radius;
                double v_left  = -Linear_velocity * (turn_radius - wheel2wheel_distance/2) / turn_radius;
                double omega = (v_right - v_left) / wheel2wheel_distance;
                double turn_time = (M_PI/2) / (omega / 27.5) * 1.3;
                double straight_time = 5.0;
                double side_time = straight_time + turn_time;
                double total_time = side_time * 4;

                if (elapsed_time >= total_time) {
                    left_velocity = 0.0;
                    right_velocity = 0.0;
                    sequence_step = 0;  // loop back to start
                    start_time_ = this->get_clock()->now();
                    return;
                }

                double time_in_side = fmod(elapsed_time, side_time);
                if (time_in_side < straight_time) {
                    left_velocity = -Linear_velocity;
                    right_velocity = Linear_velocity;
                } else {
                    left_velocity = v_left;
                    right_velocity = v_right;
                }
                break;
            }   
        }
    break;
}

    }
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



























