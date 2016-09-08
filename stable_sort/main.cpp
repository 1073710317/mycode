/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/08/31 13:42:38
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <algorithm>
#include <vector>

bool compare(int i, int j) {
    return (i > j);
}

int main() {
    int arrs[] = {5, 3, 2, 8, 1};
    std::vector<int> vec;
    vec.assign(arrs, arrs + 5);
    std::stable_sort(vec.begin(), vec.end(), compare);
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << ' ' << *it;
    }
    std::cout << '\n';
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
