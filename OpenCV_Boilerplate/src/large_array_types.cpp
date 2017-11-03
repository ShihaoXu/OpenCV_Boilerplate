//
//  large_array_types.cpp
//  OpenCV_Boilerplate
//
//  Created by Shihao Xu on 03.11.17.
//  Copyright © 2017 Shihao Xu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "helper.hpp"
#include <opencv2/core/core.hpp>

void large_array_types() {
    
    // Construct a matrix with C-style array.
    {
        std::cout << "Construct a matrix with C-style array. " << std::endl;
        
        
        int32_t data[2][2] = { 1, 2, 3, 4 };
        cv::Mat m(2, 2, CV_32SC1, data);

        // display the result
//        showMatrix("data", m);

    }
    
    // N-ary Matrix Iterator: cv::NAryMatIterator

    //   Example 4-2: Summation of two arrays using the N-ary operator
    {
        std::cout << "Summation of two arrays using the N-ary operator. " << std::endl;
        
        
        const int n_mat_size = 5;
        const int n_mat_sz[] = {n_mat_size, n_mat_size, n_mat_size };
        cv::Mat n_mat0( 3, n_mat_sz, CV_32FC1 );
        cv::Mat n_mat1( 3, n_mat_sz, CV_32FC1 );
        
        cv::RNG rng;
        rng.fill( n_mat0, cv::RNG::UNIFORM, 0.f, 1.f );
        rng.fill( n_mat1, cv::RNG::UNIFORM, 0.f, 1.f );
        
        const cv::Mat* arrays[] = { &n_mat0, &n_mat1, NULL };
        cv::Mat my_planes[2];
        cv::NAryMatIterator it( arrays, my_planes );
        
        float s = 0.f;  // total sum over all planes in both arrays
        int n = 0;      // total number of planes
        for( int p = 0; p < it.nplanes; p++, ++it ) {
            s += cv::sum(it.planes[0])[0];
            s += cv::sum(it.planes[1])[0];
            n++;
        }
    }
    
    //   Example: Compute element-wise power
    {
        // 0. The matrix size is 4x4 of type CV_8UC1
        const int n_size = 4;

        // 1. Generate the src1, src2, and dst matrices
        cv::Mat src1(cv::Size( n_size, n_size ), CV_8UC1 );
        cv::Mat src2(cv::Size( n_size, n_size ), CV_8UC1 );
        cv::Mat dst(cv::Size( n_size, n_size ), CV_8UC1);
        
        // 2. Fill src1 and src2 with random numbers from {1, 2, 3, 4} uniformly
        cv::RNG rng;
        for(int i = 0; i < n_size; i++) {
            for(int j = 0; j < n_size; j++) {
                src1.at<uchar>(i, j) = rng.uniform(1, 5);
                src2.at<uchar>(i, j) = rng.uniform(1, 5);
            }
        }
        
        // 3. Prepare for the creation of NAryMatIterator
        const cv::Mat* arrays[] = { &src1, &src2, &dst, NULL };
        uchar* ptrs[3];

        // 4. Create the NAryMatIterator, calculate the element-wise power and put the
        //    result in ptrs[2]
        cv::NAryMatIterator it( arrays, (uchar**) ptrs );
        for(int p = 0; p < it.nplanes; p++, ++it)
        {
            for(int i = 0; i < it.size; i++)
            {
                ptrs[2][i] = (uint8_t) cv::pow( ptrs[0][i], ptrs[1][i] );
                
            }

            for(int i = 0; i < it.size; i++) {
                std::cout << (int)ptrs[2][i] << ", ";
            }
        }
        // TODO: store the result in dst.

    }
    
    
    
    
}
