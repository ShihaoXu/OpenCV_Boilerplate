//
//  drawing_examples.cpp
//  OpenCV_Boilerplate
//
//  Created by Shihao Xu on 31.10.17.
//  Copyright © 2017 Shihao Xu. All rights reserved.
//

#include <stdio.h>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

void drawing_examples() {
    cv::Mat frame;
    cv::namedWindow("drawing");
    frame = cv::imread("canvas.png");
    
    if( frame.empty() ) {
        std::cout << "canvas can't be created. " << std::endl;
        return;
    }
    
    
    /* cv::circle() */
    cv::circle(frame, cv::Point2i(20, 20), 10, CV_RGB(255, 0, 0));
    
    cv::Point start(40, 20), end(80, 60);
    cv::Rect rect(50, 30, 20, 20);
    
    /* cv::line()  */
    cv::line(frame, start, end, CV_RGB(255, 0, 0));
    
    /* cv::rectangle()  */
    cv::rectangle(frame, rect, CV_RGB(0, 0, 255));

    
    /* cv::clipLine()   */
    if( cv::clipLine(rect, start, end) ) {
        cv::line(frame, start, end, CV_RGB(0, 255, 0));
    }
    
    /* cv::ellipse()    */
    cv::ellipse(frame, cv::Point(100, 50), cv::Size(20, 10), -45, 90, 360, CV_RGB(255, 0, 0));

    
    /* cv::ellipse2Poly(), cv::polylines()  */
    std::vector<cv::Point> point_vec;
    cv::Point * pts;
    cv::ellipse2Poly(cv::Point(200, 150), cv::Size(100,80), 0, 0, 270, 20, point_vec);
    int ncontours = point_vec.size();
    pts = point_vec.data();
    cv::polylines(frame, &pts, &ncontours, 1, false, CV_RGB(0, 0, 255));

    cv::putText(frame, "some Text", cv::Point(20, 20), cv::FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 0, 255));
    
    
    
    
    cv::imshow("drawing", frame);
    cvWaitKey();
    cv::destroyWindow("drawing");
}
