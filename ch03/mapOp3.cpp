#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

String folder = "/home/yeon/ros2/kdta_ros2_yoen/data/";

int main() {

    // ex matrix
    Mat img1 = imread(folder + "lena.bmp");
    Rect rc(220, 120, 200, 200);

    Mat img2 = img1(rc);
    Mat img3 = img1(rc).clone();

    img2 = ~img2;
    //img1.setTo(Scalar(0, 255, 255));

    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);

    waitKey(0);
    
    return 0;
}