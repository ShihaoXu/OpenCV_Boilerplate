//
//  example_2_1.cpp
//  OpenCV_Boilerplate
//
//  Created by Shihao Xu on 29.10.17.
//  Copyright © 2017 Shihao Xu. All rights reserved.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>


int example_2_1(std::string filename) {
    cv::Mat img = cv::imread(filename, -1);
    if( img.empty() ) return -1;
    
    cv::namedWindow("Example 2-1", cv::WINDOW_AUTOSIZE);
    cv::imshow("example 2-1", img);
    cv::waitKey(0);
    cv::destroyWindow("Example 2-1");
    return 0;
}
