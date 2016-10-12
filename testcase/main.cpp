/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/10/08 16:35:18
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>

int a = 1;

int main() {
    int a = 3;
    std::cout << "global a: " << ::a << std::endl;
    std::cout << "local a: " << a << std::endl;
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
