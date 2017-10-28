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





int main(int argc, char** argv) {
    
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;
 
    std::cout << "CV_VERSION = " << CV_VERSION << std::endl;
    
    std::for_each(
                  in(std::cin), in(), std::cout << (_1 * 3) << " " );


    return 0;
}

