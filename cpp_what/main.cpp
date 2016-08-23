/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun)
 * @date 2016/07/29 20:17:45
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>

template <class T, const char* str>
class TestClass {
    TestClass(const T& t) {
        std::cout << str << std::endl;
    }
};

int main() {
    const char* str = "hello";
    TestClass<int, "hello"> t_c;
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
