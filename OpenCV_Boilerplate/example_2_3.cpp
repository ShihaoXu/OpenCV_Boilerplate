//
//  example_2_3.cpp
//  OpenCV_Boilerplate
//
//  Created by Shihao Xu on 30.10.17.
//  Copyright © 2017 Shihao Xu. All rights reserved.
//
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int example_2_3(std::string path) {
    const std::string windowName("Example3");
    cv::namedWindow( windowName, cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open(path);
    
    cv::Mat frame;
    for(;;) {
        cap >> frame;
        
        if(frame.empty())
            break;    // Ran out of file
        cv::imshow( windowName, frame);
        if(cvWaitKey(33) >= 0)
            break;

    }
    
    return 0;
}
