#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/yeon/ros2/kdta_ros2_yoen/data/";

int main() {

    Mat frame, doubleFrame, reshapeFrame;
    VideoCapture cap(folder + "vtest.avi");
    //VideoCapture cap(0, CAP_V4L2);  
    double fps = cap.get(CAP_PROP_FPS); 
    int delay = cvRound(1000 / fps);
    Size sz1(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT));
    std::vector<int> shape = {sz1.height * 2, sz1.width / 2};

    if (!cap.isOpened())  
    {  
        return -1; 
    }
    cout << "vedio open" << endl; 

    int fourcc = VideoWriter::fourcc('Q', 'I', 'V', 'V');
    VideoWriter outputVedio(folder + "output10.avi", fourcc, fps, sz1);

    while(true)
    {
        cap >> frame;  
        if(frame.empty())
            break;
        resize(frame, doubleFrame, sz1 * 2);
        reshapeFrame = frame.reshape(3, shape);

        imshow("frame", frame);
        imshow("doubleFrame", doubleFrame);
        imshow("reshape", reshapeFrame);

        outputVedio << frame;

        if (waitKey(delay) == 27)
        {
            break;
        }
    } 
    cap.release();
    outputVedio.release();

    return 0;
}