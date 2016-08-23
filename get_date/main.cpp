/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun)
 * @date 2016/08/20 11:00:38
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <stdio.h>
#include <iostream>
#include <ctime>

int main() {
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    std::cout << (now->tm_year + 1900) << '-'  << (now->tm_mon + 1) << '-' <<  now->tm_mday << std::endl;

    // 测试前面补0
    printf("%02d-%d\n", now->tm_mon + 1, now->tm_mday);

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
