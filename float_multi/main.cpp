/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/07/26 10:56:44
 * @version $Revision$ 
 * @brief 示例浮点数相乘后的精度
 *  
 **/

#include <stdio.h>
#include <iostream>

int main() {

    double a = 1.093726;
    double b = 2.827862;

    std::cout << "a * b = " << a * b << std::endl;
    printf("a * b = %.5f\n", a * b);
    printf("a * b = %.6f\n", a * b);

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
