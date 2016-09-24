/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@xxoo)
 * @date 2016/08/30 22:06:09
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <list>

int main() {
    std::list<int> l;
    std::vector<int> v;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    v.insert(v.begin(), l.begin(), l.end());

    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
