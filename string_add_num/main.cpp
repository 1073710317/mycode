/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/08/29 18:16:29
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>

int main() {
    char buf[128];
    snprintf(buf, sizeof(buf), "i am %d", 27);
    std::string str = buf;
    std::cout << str << std::endl;
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
