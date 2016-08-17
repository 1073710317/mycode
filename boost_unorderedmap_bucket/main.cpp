/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/08/10 10:17:05
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
//#include <unordered_map> c++11标准
#include <boost/unordered_map.hpp>

int main() {
    typedef boost::unordered_map<std::string, std::string> Map;
    //typedef std::unordered_map<int,int> Map;

    Map map;

    map.reserve(25537);

    std::cout << map.bucket_count() << std::endl;
    std::cout << map.max_bucket_count() << std::endl;

    return 0;
}


/* vim: set ts=4 sw=4 sts=4 tw=100 */
