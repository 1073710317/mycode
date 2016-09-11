/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/09/10 10:41:28
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>

int main() {
    double weight = -1;
    if (weight < 0) {
        std::cout << "weight < 0: " << weight << std::endl;
        goto OUT;
    }

    std::cout << "positive" << std::endl;

OUT:
    std::cout << "out" << std::endl;

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
