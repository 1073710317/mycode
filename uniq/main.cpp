/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author wsy(wsy@baidu.com)
 * @date 2016/08/28 23:45:48
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

typedef std::vector<int> VEC_INT;
typedef VEC_INT::iterator VEC_INT_ITER;
typedef VEC_INT::const_iterator VEC_INT_ITER_CONST;
typedef std::list<VEC_INT> LIST_VEC_INT;
typedef LIST_VEC_INT::iterator LIST_VEC_INT_ITER;

bool need_del(const VEC_INT& vec1, const VEC_INT& vec2) {
    size_t vec1_size = vec1.size();
    size_t vec2_size = vec2.size();
    double same = 0;
    for (VEC_INT_ITER_CONST it1 = vec1.begin(); it1 != vec1.end(); ++it1) {
        if (vec2.end() != std::find(vec2.begin(), vec2.end(), *it1)) {
            same++;
        }
    }
    double sim = (same / vec1_size);
    std::cout << sim << std::endl;
    if (sim >= 0.5) {
        return true;
    }
    return false;
}

bool should_add(const LIST_VEC_INT& list, const VEC_INT& vec) {
    for elem in list:
        if need_del(elem, vec)
            return false
    return true
}

int main() {
    int arr1[] = {1, 2, 4, 6, 7, 9, 10};
    VEC_INT vec1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    
    int arr2[] = {1, 2};
    VEC_INT vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));

    LIST_VEC_INT list_vec_int;
    if should_add(list_vec_int, vec1):
        list_vec_int.push_back(vec1);
    if should_add(list_vec_int, vec2):
        list_vec_int.push_back(vec2);
    
    //std::cout << need_del(vec1, vec2) << std::endl;

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
