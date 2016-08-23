/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun)
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
    double c;

    c = a * b;

    std::cout << "a * b = " << c << std::endl;
    printf("a * b = %f\n", c);
    printf("a * b = %.5f\n", c);
    printf("a * b = %.6f\n", c);

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
