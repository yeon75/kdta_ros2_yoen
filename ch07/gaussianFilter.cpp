#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/yeon/ros2/kdta_ros2_yoen/data/";

int main()
{
    Mat src =imread(folder + "rose.bmp", IMREAD_GRAYSCALE);
    vector<Mat> dsts;

    for (int sigma = 3; sigma <= 19; sigma += 1)
    {
        Mat dst;
        GaussianBlur(src, dst, Size(0, 0), sigma);
        dsts.push_back(dst);
    }

    imshow("src", src);
    int i = 1;
    for(auto dst : dsts)
    {
        imshow("dst" + to_string(i), dsts);
        i++;
    }
    waitKey(0);

    return 0;
}