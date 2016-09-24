/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@xxoo)
 * @date 2016/09/01 11:36:57
 * @version $Revision$ 
 * @brief set相关算法使用示例程序
 *  
 **/

#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>

template <class T>
struct display {
    void operator()(const T& x) {
        std::cout << x << ' ';
    }
};

int main() {
    int ia1[6] = {1, 3, 5, 7, 9, 11};
    int ia2[7] = {1, 1, 2, 3, 5, 8, 13};

    std::multiset<int> s1(ia1, ia1 + 6);
    std::multiset<int> s2(ia2, ia2 + 7);

    std::cout << "s1: ";
    for_each(s1.begin(), s1.end(), display<int>());
    std::cout << std::endl;

    std::cout << "s2: ";
    for_each(s2.begin(), s2.end(), display<int>());
    std::cout << std::endl;

    std::multiset<int>::iterator first1 = s1.begin();
    std::multiset<int>::iterator end1 = s1.end();
    std::multiset<int>::iterator first2 = s2.begin();
    std::multiset<int>::iterator end2 = s2.end();

    std::cout << "union of s1 and s2: ";
    set_union(first1, end1, first2, end2, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    first1 = s1.begin();
    first2 = s2.begin();
    std::cout << "intersection of s1 and s2: ";
    set_intersection(first1, end1, first2, end2, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    first1 = s1.begin();
    first2 = s2.begin();
    std::cout << "difference of s1 and s2(s1 - s2): ";
    set_difference(first1, end1, first2, end2, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    first1 = s1.begin();
    first2 = s2.begin();
    std::cout << "symmetric difference of s1 and s2: ";
    set_symmetric_difference(first1, end1, first2, end2, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    first1 = s2.begin();
    first2 = s1.begin();
    end1 = s2.end();
    end2 = s1.end();
    std::cout << "difference of s2 and s1(s2 - s1): ";
    set_difference(first1, end1, first2, end2, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
