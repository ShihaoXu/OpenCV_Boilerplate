//
//  example_2_4.cpp
//  OpenCV_Boilerplate
//
//  Created by Shihao Xu on 31.10.17.
//  Copyright © 2017 Shihao Xu. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int g_slider_position = 0;

// g_run (positive) indicates how many frames are displayed before stopping;
// a negative number means the system runs in continuous video mode.
int g_run = 1, g_dontset = 0;   //start out in single step mode
cv::VideoCapture g_cap;

void onTrackbarSlide( int pos, void *) {
    g_cap.set( cv::CAP_PROP_POS_FRAMES, pos );
    if( !g_dontset )
        g_run = 1;
    g_dontset = 0;
}


int example_2_4(std::string path) {
    cv::namedWindow( "Example2_4", cv::WINDOW_AUTOSIZE);
    g_cap.open( path );
    int frames  = (int) g_cap.get( cv::CAP_PROP_FRAME_COUNT );
    int tmpw    = (int) g_cap.get( cv::CAP_PROP_FRAME_WIDTH );
    int tmph    = (int) g_cap.get( cv::CAP_PROP_FRAME_HEIGHT );
    std::cout << "Video has " << frames << " frames of dimensions("
    << tmpw << ", " << tmph << ")." << std::endl;
    
    cv::createTrackbar("Position", "Example2_4", &g_slider_position, frames, onTrackbarSlide);
    
    cv::Mat frame;
    for(;;) {
        if( g_run != 0 ) {
            g_cap >> frame; if( frame.empty() ) break;
            int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_dontset = 1;
            
            cv::setTrackbarPos("Position", "Example2_4", current_pos);
            cv::imshow("Example2_4", frame);
            
            g_run -= 1;
        }
        
        char c = cvWaitKey(10);
        if( c == 's')
        {g_run = 1; std::cout << "Single step, run = " << g_run << std::endl;}
        
        if( c == 'r')
        {g_run = -1; std::cout << "Run mode, run = " << g_run <<std::endl;}
        
        if( c == 27 )
            break;
    }
    cv::destroyWindow("Example2_4");
    
    return 0;
  
}
