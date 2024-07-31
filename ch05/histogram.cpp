#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/yeon/ros2/kdta_ros2_yoen/data/";

int main()
{
    Mat src =imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);
    Mat histo;
    int channels[] = {0};
    int dims = 1;
    const int histSize[] = {256};
    float graylevel[] = {0, 255};
    const float *ranges[] = {graylevel};

    calcHist(&src, 1, channels, noArray(), histo, dims, histSize, ranges);
    imshow("src", src);

    Mat graph(100, 255, CV_8U, Scalar(255));
    normalize(histo, histo, 0, 100, NORM_MINMAX);
    for(int i = 0; i < 256; ++i)
    {
        line(graph, Point(i, 100), Point(i, 100 - cvRound(histo.at<float>(i))), Scalar(0, 0, 255));
    }
    imshow("graph", graph);
    waitKey(0);

    return 0;
}