//
//  main.cpp
//  OpenCV_Boilerplate
//
//  Created by Shihao Xu on 29.10.17.
//  Copyright © 2017 Shihao Xu. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <algorithm>

#include <boost/lambda/lambda.hpp>

#include <opencv2/opencv.hpp>

#include "book_header.h"





int main(int argc, char** argv) {
    
//    using namespace boost::lambda;
//    typedef std::istream_iterator<int> in;
//
//    std::cout << "CV_VERSION = " << CV_VERSION << std::endl;
//
//    std::for_each(
//                  in(std::cin), in(), std::cout << (_1 * 3) << " " );

    std::cout << "CWD is: " << getcwd(NULL, 255) << std::endl << std::endl;
    std::cout << "Using OpenCV version " << CV_VERSION << std::endl;
    

// std::cout << cv::getBuildInformation();

//    return example_2_1(filename);
//    return example_2_3(filename);
//    return example_2_4(filename);
//    drawing_examples();
//    functors();
    large_array_types();
    return 0;
}

