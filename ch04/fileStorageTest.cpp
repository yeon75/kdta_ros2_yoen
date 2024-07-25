#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/yeon/ros2/kdta_ros2_yoen/data/";

int main()
{
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    Mat img(400, 600, CV_8UC3, Scalar(255, 255, 255));
    FileStorage fs;
    
    fs.open(folder + "myData.json", FileStorage::WRITE);

    if(!fs.isOpened())
    {
        cerr << "open" << endl;
        return 1;
    }
    String name = "seungyeon";
    int age = 34;
    Point pt1(30, 40);
    vector<float> v = {1.2, 4.5, 3.14};
    Mat mat1 = imread(folder + "lenna.bmp");

    fs << "name" << name;
    fs << "age" << age;
    fs << "point" << pt1;
    fs << "vector" << v;
    fs << "mat1" << mat1;

    fs.release(); 

    return 0;
}