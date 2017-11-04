//
//  helper.cpp
//  OpenCV_Boilerplate
//
//  Created by Shihao Xu on 03.11.17.
//  Copyright © 2017 Shihao Xu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"

namespace helper {
    void showTitle(std::string title) { std::cout << title << std::endl; }
    
    
    void showSeparator()
    {
        std::cout << "========================================" << std::endl;
    }
    
    
    void showMatrix(std::string matName, cv::Mat& m) {
        std::cout << "The Matrix \"" + matName + "\" owns the following data: " << std::endl;
        std::cout << m << std::endl;
    }
}

