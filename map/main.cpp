/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@xxoo)
 * @date 2016/09/20 15:28:04
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> map;
    map["key1"] = 1;
    map["key2"] = 2;

    std::cout << "map.size: " << map.size() << std::endl;

    std::cout << map["key1"] << std::endl;
    std::cout << map["key2"] << std::endl;
    std::cout << map["key3"] << std::endl;  // 将会插入一个kv对，key为key3，值为0
    
    std::cout << "map.size: " << map.size() << std::endl;

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
