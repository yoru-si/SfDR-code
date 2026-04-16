/*
file: colour_detector.cpp
Author: Raghavendran Srinivasan(s3656721), Srikrishnan Srinivasan(s3603288)
Group number: SDfR-PPD 16

Description: Code to handle green object detection based on thresholding and find centroid of it.
*/

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "example_interfaces/msg/float64.hpp"
#include "image_functions_sdfr/image_functions.hpp"

using std::placeholders::_1;

class ColourDetector : public rclcpp::Node
{
public:
    ColourDetector() : Node("colour_detector")
    {
        image_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
            "/output/moving_camera", 10,
            std::bind(&ColourDetector::image_callback, this, _1));

        x_pub_ = this->create_publisher<example_interfaces::msg::Float64>("/colour_detector/x", 10);
        y_pub_ = this->create_publisher<example_interfaces::msg::Float64>("/colour_detector/y", 10);

        RCLCPP_INFO(this->get_logger(), "Colour Detector Node started");
    }

private:
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;
    rclcpp::Publisher<example_interfaces::msg::Float64>::SharedPtr x_pub_;
    rclcpp::Publisher<example_interfaces::msg::Float64>::SharedPtr y_pub_;

    void image_callback(const sensor_msgs::msg::Image::ConstSharedPtr msg)
    {
        int width = image_functions::getImageWidth(msg);
        int height = image_functions::getImageHeight(msg);

        long sum_x = 0, sum_y = 0, count = 0;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                auto [r, g, b] = image_functions::getPixelChannels(msg, x, y);

                // check if pixel is green
                if (g > 100 && g > r*1.2  && g > b*1.2) {
                    sum_x += x;
                    sum_y += y;
                    count++;
                }
            }
        }

        if (count > 0) {
            double cx = (double)sum_x / count;
            double cy = (double)sum_y / count;

            example_interfaces::msg::Float64 x_msg, y_msg;
            x_msg.data = cx;
            y_msg.data = cy;
            x_pub_->publish(x_msg);
            y_pub_->publish(y_msg);

            RCLCPP_INFO(this->get_logger(), "Green object at x=%.1f, y=%.1f", cx, cy);
        } else {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000, "No green object detected");
        }
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ColourDetector>());
    rclcpp::shutdown();
    return 0;
}
