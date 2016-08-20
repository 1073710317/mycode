/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/08/18 18:39:03
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

typedef std::map<int, int> IntMap;
typedef std::map<int, std::vector<int>* > IntVecMap;

void test_erase_vec() {
    IntVecMap vec_map;

    std::vector<int>* vec = new std::vector<int>;
    vec->push_back(1);
    vec->push_back(2);
    vec->push_back(3);

    vec_map[1] = vec;

    std::cout << vec_map[1]->size() << std::endl;

    std::vector<int>* tmp_vec = vec_map[1];
    std::vector<int>::iterator vec_it = std::find(tmp_vec->begin(), tmp_vec->end(), 1); // TODO:改成const iterator
    if (vec_it != tmp_vec->end()) {
        tmp_vec->erase(vec_it);
    }

    std::cout << vec_map[1]->size() << std::endl;
}

void test_erase_map() {
    IntMap map;
    for (int i = 0; i < 100; ++i) {
        map[i] = i + 10000;
    }

    std::cout << "map_size: " << map.size() << std::endl;

    for (IntMap::iterator it = map.begin(); it != map.end(); ++it) {
        std::cout << it->first << ": "  << it->second << std::endl;

        if (it->first % 2 == 0) {
            map.erase(it->first);
        }
    }

    std::cout << "clean finish" << std::endl;
    std::cout << map.size() << std::endl;

    for (IntMap::iterator it = map.begin(); it != map.end(); ++it) {
        std::cout << it->first << ": "  << it->second << std::endl;
    }

    std::cout << map.size() << std::endl;
}

int main() {
    test_erase_map();

    //test_erase_vec();
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
