#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/yeon/ros2/kdta_ros2_yoen/data/";

int main()
{
    FileStorage fs;
    String name;
    Mat img;
    
    fs.open(folder + "myData.json", FileStorage::READ);

    if(!fs.isOpened())
    {
        cerr << "open" << endl;
        return 1;
    }
    fs["name"] >> name;
    fs["mat1"] >> img;

    fs.release(); 

    cout << name << endl;
    imshow("img", img);
    waitKey(0);

    return 0;
}