#include "steering.hpp"
#include "relbot_msgs/msg/relbot_motors.hpp"  


#define Linear_velocity 0.5
#define radius 0.5
#define wheel2wheel_distance 0.15

SteerRelbot::SteerRelbot() : Node("steer_relbot") {
    RCLCPP_INFO(this->get_logger(), "Init");
    create_topics();
    RCLCPP_INFO(this->get_logger(), "Created Topics");

    //Initialize time
    start_time_ = this->get_clock()->now();

    timer_ = this->create_wall_timer(std::chrono::duration<double>(1/DEFAULT_SETPOINT_STREAM),
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
                left_velocity = Linear_velocity;
                right_velocity = Linear_velocity;
                break;

            case CIRCLE:
                left_velocity = Linear_velocity * (radius - wheel2wheel_distance/2)/radius;
                right_velocity = Linear_velocity * (radius + wheel2wheel_distance/2)/radius;
                break;

            case STRAIGHT_TURN:
                if (t < 5.0) {  // go straight for 5 seconds
                    left_velocity = Linear_velocity;
                    right_velocity = Linear_velocity;
                } else {  // turn left 90 degrees
                    left_velocity = -0.1;
                    right_velocity = 0.1;
                }
                break;

            case SQUARE: {
                double elapsed_time = (this->get_clock()->now() - start_time_).seconds();

                double straight_time = 3.0;  // seconds per straight segment
                double turn_time = 1.0; // seconds per 90° turn
                double side_time = straight_time + turn_time;

                
                double total_time = side_time * 4; // Total square duration

                if (elapsed_time>= total_time) {
                    // Square complete
                    left_velocity = 0.0;
                    right_velocity = 0.0;
                    return;
                } 
                else {
                    // Determine which side we are on
                    int side = elapsed_time / side_time;  // integer division
                    double time_in_side = elapsed_time - side * side_time;

                    if (time_in_side < straight_time) {
                        // Straight part
                        left_velocity = Linear_velocity;
                        right_velocity = Linear_velocity;
                    } else {
                        // Turn part
                        left_velocity = Linear_velocity * (radius - wheel2wheel_distance/2)/radius;
                        right_velocity = Linear_velocity * (radius + wheel2wheel_distance/2)/radius;
                    }
            }
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



























