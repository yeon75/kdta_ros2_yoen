#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/yeon/ros2/kdta_ros2_yoen/data/";

int main()
{
    Mat src =imread(folder + "rose.bmp", IMREAD_GRAYSCALE);
    vector<Mat> dsts;
    int ksize = 5;

    for (int ksize = 3; ksize <= 19; ksize += 2)
    {
        Mat dst;
        blur(src, dst, Size(ksize, ksize));
        dsts.push_back(dst);
    }
    imshow("src", src);
    int i = 3;
    for (auto dst : dsts)
    {
        imshow("dst" + to_string(i), dst);
        i += 2;
    }
    waitKey(0);

    return 0;
}