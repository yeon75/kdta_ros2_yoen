#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

String folder = "/home/yeon/ros2/kdta_ros2_yoen/data/";

int main() {

    // ex point 
    Point pt1;
    pt1.x = 5;
    pt1.y = 10;
    Point pt2(6, 7);

    std::cout << pt1 << std::endl;
    std::cout << pt2 << std::endl;

    // ex size
    Size sz1;
    sz1.height = 10;
    sz1.width = 20;
    Size sz2(50, 100);

    std::cout << sz1 << std::endl;
    std::cout << sz2 << std::endl;

    std::cout << sz1.area() << "size2:" << sz2.area() << std::endl;

    return 0;
}