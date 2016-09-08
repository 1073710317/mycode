/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/08/24 15:50:25
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

static __attribute__((constructor)) void init() {
    //std::cout << "in init" << std::endl;  // 为什么这个会出core？
    printf("hello\n");
}

int main() {
    std::cout << "in main" << std::endl;
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
