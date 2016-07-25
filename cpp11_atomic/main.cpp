/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/07/25 18:33:05
 * @version $Revision$ 
 * @brief c++11中原子操作实例
 *  
 **/

#include <iostream>
#include <atomic>
#include <thread>

atomic_llong total{0};

void func(int) {
    for (long long i = 0; i < 10000000; ++i) {
        total += i;
    }
}

int main() {
    std::thread t1(func);
    std::thread t2(func);
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
