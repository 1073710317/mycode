/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file index_template.cpp
 * @author wsy(wsy@baidu.com)
 * @date 2016/07/18 23:04:28
 * @version $Revision$ 
 * @brief 使用模板实现的index引擎，支持自定义key和value的类型
 *  
 **/

#include <iostream>
#include <map>
#include <string>
#include <iostream>

typedef struct _val1 {
    std::string name;
} val1;

std::ostream& operator<<(std::ostream &out, val1 value) {
    out << value.name;
    return out;
}

template <class key_type, class value_type>
class IndexEngine {
public:
    int add(const key_type& key, const value_type& value);

    int to_string() {
        // 这里需要加个typename
        for (typename std::map<key_type, value_type>::iterator it = index.begin(); it != index.end(); ++it) {
            std::cout << it->second << std::endl;   // second需要支持/重载<<操作符，如上所示
        }
    }

private:
    std::map<key_type, value_type> index;
};

template <class key_type, class value_type>
int IndexEngine<key_type, value_type>::add(const key_type& key, const value_type& value) {
    index[key] = value;
}

template <class key_type, class value_type>
using engine_type = std::map<std::string, IndexEngine<key_type, value_type>* >; // 如何存储？

int main() {
    IndexEngine<std::string, val1> index1;

    val1 v;
    
    v.name = "wuwushaoyun";
    index1.add("name1", v);

    v.name = "wuyiwen";
    index1.add("name2", v);

    index1.to_string();

    IndexEngine<std::string, float> index2;
    index2.add("age1", 27);
    index2.add("age2", 1.5);
    index2.to_string();

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
