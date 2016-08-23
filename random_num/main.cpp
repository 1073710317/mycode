/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/08/22 20:34:13
 * @version $Revision$ 
 * @brief c/c++中生成随机数
 *  
 **/
#include <iostream>
#include <stdlib.h> 
#include <time.h>

int main() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < 1000000; i++) {
        std::cout << rand() % 98 << std::endl; 
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
