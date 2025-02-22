#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/yeon/ros2/kdta_ros2_yoen/data/";

int main()
{
    Mat src =imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);
    Mat noise(src.size(), CV_32FC1);
    int stddev = 10;
    randn(noise, 0, stddev);

    add(src, noise, src, Mat(), CV_8U);
    //Mat src = src + noise;

    Mat dst1, dst2;
    GaussianBlur(src, dst1, Size(), 5);
   
    bilateralFilter(src, dst2, -1, 10, 5);

   imshow("src", src);
   imshow("dst1", dst1);
   imshow("dst2", dst2);

   waitKey(0);

    return 0;
}