/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@xxoo)
 * @date 2016/09/01 11:05:57
 * @version $Revision$ 
 * @brief simhash的用法示例
 *  
 **/
#include <iostream>
#include <string>

// 通过Hamming distance判断是否相似
bool is_sim(const unsigned long long& u1, const unsigned long long& u2, int distance = 3) {
    return true;
}

// 将文本转换为一个hash值，此处约定为64位整数
class SimHasher {
public:
    SimHasher(){

    }

    SimHasher(const std::string& text) : _text(text) {

    }

    void set_text(const std::string& text) {
        _text = text;
    }

    // 计算hash值
    unsigned long long hash() {
        return 0;
    }

private:
    std::string _text;
};

int main() {
    std::string text1 = "hello";
    std::string text2 = "hello";

    SimHasher sim_hasher;
    
    sim_hasher.set_text(text1);
    unsigned long long sign1 = sim_hasher.hash();
    
    sim_hasher.set_text(text2);
    unsigned long long sign2 = sim_hasher.hash();

    std::cout << "text1 = " << text1 << ", text2 = " << text2 << ", is_sim = " << is_sim(sign1, sign2) << std::endl;

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
