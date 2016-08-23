/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file function_template.cpp
 * @author bjwushaoyun(bjwushaoyun)
 * @date 2016/07/17 14:23:51
 * @version $Revision$ 
 * @brief 函数模板示例程序
 *  
 **/

#include <iostream>

/**
 * @brief 比较函数模板
 *
 * @param [in] v1   : const T&
 * @param [in] v2   : const T&
 * @return  template <typename T> int 
 * @retval   
 * @see 
 * @author bjwushaoyun
 * @date 2016/07/17 14:26:15
**/
template <typename T>
int compare(const T& v1, const T& v2) {
    if (v1 < v2) {
        return -1;
    }
    if (v1 > v2) {
        return 1;
    }
    return 0;
}

int main() {

    // 在下面代码中，编译器将实例化compare的两个不同的版本

    // 编译器实例化为compare(const int&, const int&)
    std::cout << compare(2, 1) << std::endl;

    // 编译器实例化为compare(const string&, const string&)
    std::cout << compare("abc", "abd") << std::endl;

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
