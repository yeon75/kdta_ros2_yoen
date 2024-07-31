#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/yeon/ros2/kdta_ros2_yoen/data/";

int main()
{
    Mat src = imread(folder + "tekapo.bmp");
    Point2f srcPts[3], dstPts[3];
    
    //srcPts[0] = Point2f(0, 0);
    //srcPts[1] = Point2f(1, 0);
    //srcPts[2] = Point2f(1, 1);
    //srcPts[0] = Point2f(0, 0);
    //srcPts[1] = Point2f(2, 0);
    //srcPts[2] = Point2f(2, 2);
    
    srcPts[0] = Point2f(0, 0);
    srcPts[1] = Point2f(src.cols -1, 0);
    srcPts[2] = Point2f(src.cols -1, src.rows -1);
    srcPts[0] = Point2f(50, 50);
    srcPts[1] = Point2f(src.cols -1 + 50, 50);
    srcPts[2] = Point2f(src.cols -1 + 50, src.rows -1 + 50);

    Mat M = getAffineTransform(srcPts, dstPts);
    cout << M << endl;
    Mat dst;

    Size sz1 = src.size();
    warpAffine(src, dst, M, sz1);

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);
    return 0;
}