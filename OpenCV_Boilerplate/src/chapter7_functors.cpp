//
//  chapter7_functors.cpp
//  OpenCV_Boilerplate
//
//  Created by Shihao Xu on 01.11.17.
//  Copyright © 2017 Shihao Xu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

void functors() {
    
    // 1. Random Number Generator
    std::cout << "Random Number Generator (RNG) test: " << std::endl;
    
    cv::RNG rng1 = cv::RNG::RNG(12345);
    cv::RNG rng2 = cv::RNG::RNG(98765);
    std::cout << float(rng1) << " " << float(rng2) << std::endl << std::endl;
    

    // 2. Principle Component Analysis
    std::cout << "Principle Component Analysis (PCA) test: " << std::endl;
    
    float sigma_1 = 100;
    float sigma_2 = 10;
    
    int sample_size = 100;
    
    cv::Mat points(sample_size, 2, CV_32FC1);
    for( int i = 0; i < sample_size; i++) {
        // homogen transformation: rotate 30 deg, translate by (200, 200)
        cv::Matx33f trans_mat(0.866, 0.5, 200, -0.5, 0.866, 200, 0, 0, 1);
        cv::Point3f origin_point(rng1.gaussian(sigma_1), rng2.gaussian(sigma_2), 1);
        cv::Point3f transformed_point_3d = trans_mat * (cv::Vec3f) origin_point;
        cv::Point2f transformed_point_2d = cv::Point2f(transformed_point_3d.x, transformed_point_3d.y);
        
        for ( int j = 0; j < 2; j++) {
            points.at<float>(i, j) = j == 0 ? transformed_point_2d.x : transformed_point_2d.y;
        }
    }
    //   2.1 Visualize the original data set.
    cv::namedWindow("PCA Original Data Set");
    cv::Mat canvas = cv::imread("canvas.png");
    for( int i = 0; i < sample_size; i++) {
        cv::circle(canvas, (cv::Point2f) points.row(i), 2, CV_RGB(255, 0, 0));
    }
    cv::imshow("PCA Data Set", canvas);
    cvWaitKey();
    
    //   2.2 Generate a PCA functor
    cv::PCA pcaObj = cv::PCA::PCA(points, cv::noArray(), CV_PCA_DATA_AS_ROW, 1);
    cv::Mat proj_points(sample_size, 1, CV_32FC1);
    pcaObj.project(points, proj_points);
    
    //   2.3 Project the training data onto the original canvas. 
    for( int i = 0; i < sample_size; i++) {
        cv::circle(canvas, cv::Point2f(200 + proj_points.at<float>(i, 1), 200), 2, CV_RGB(0, 0, 255));
    }
    cv::imshow("PCA Data Set", canvas);
    cvWaitKey();
    

    //   2.4 Back projection.
    cv::Mat backMat(points);
    pcaObj.backProject(proj_points, backMat);
    for( int i = 0; i < sample_size; i++) {
        cv::circle(canvas, (cv::Point2f) backMat.row(i), 2, CV_RGB(0, 255, 0));
    }
    cv::imshow("PCA Data Set", canvas);
    cvWaitKey();
    

    cv::destroyWindow("PCA Data Set");
    
}
