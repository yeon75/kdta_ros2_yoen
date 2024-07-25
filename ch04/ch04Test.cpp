#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void *data);
struct Mydata
{
    Mat img;

    bool flag = false;
};

String folder = "/home/yeon/ros2/kdta_ros2_yoen/data/";

int main()
{
    Mydata mydata;
    mydata.img = imread(folder + "lenna.bmp");

    namedWindow("img");
    setMouseCallback("img", flwMouse, (void *)&mydata);

    imshow("img", mydata.img);
    waitKey(0);

    return 0;
}

void flwMouse(int event, int x, int y, int flags, void *data)
{
    Mydata *ptr = (Mydata *)data;

    Scalar red = Scalar(0, 0, 255);
    Mat img(400, 600, CV_8UC3, Scalar(255, 255, 255));

    switch (event)
    {
    case EVENT_MOUSEMOVE:
        rectangle(img, Rect(50, 50, 100, 70), red, 2);
    }
}
