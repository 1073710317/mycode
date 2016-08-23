/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun)
 * @date 2016/07/20 11:36:36
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <stdlib.h>

class Test {
public:
    std::vector<int> i_vec; // 8

    // 8
    Test() {
        i_vec.reserve(400000000);
    }
    
    // v table:8

    // total size: 24
};

int main() {
    int a;

    std::vector<int> ivec;
    ivec.reserve(400000000);
    ivec.push_back(101);    // 如何获取101存储的实际地址是什么？

    std::vector<int>::iterator it = ivec.begin();

    Test test;
    test.i_vec.push_back(101);

    void* malloc_address = malloc(1);

    std::cout << "address of a: " << &a << std::endl;
    std::cout << "address of ivec: " << &ivec << std::endl;
    std::cout << "address of test: " << &test << std::endl;
    std::cout << "address of test.i_vec: " << &(test.i_vec) << std::endl;
    std::cout << "sizeof of test: " << sizeof(test) << std::endl;
    std::cout << "address of it: " << &(*it) << std::endl;
    std::cout << "address of malloc_address: " << malloc_address << std::endl;

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
