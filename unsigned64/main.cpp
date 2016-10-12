/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/09/28 19:48:00
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <limits>

int main() {
    std::cout << std::numeric_limits<signed long long>::max() << std::endl;
    std::cout << sizeof(unsigned long) << std::endl;
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
