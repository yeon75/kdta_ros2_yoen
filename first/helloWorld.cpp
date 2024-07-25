#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"

std::string folder = "/home/yeon/ros2/kdta_ros2_yoen/lena.bmp";

int main()
{
    std::cout << "hello, world" << std::endl;
    cv::Mat img;
    img = cv::imread(folder + "lena.bmp");
    cv::imshow("image", img);
    cv::waitKey(0);

    return 0;
}