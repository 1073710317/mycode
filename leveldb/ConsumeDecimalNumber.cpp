/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file ConsumeDecimalNumber.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/09/11 11:20:53
 * @version $Revision$ 
 * @brief util/logging.cc中的ConsumeDecimalNumber函数
 *  
 **/

#include <stdint.h>
#include <iostream>

bool ConsumeDecimalNumber(const char* in, uint64_t* val) {
    uint64_t v = 0;
    int digits = 0;
    const char* tmp_c = in;
    while (*tmp_c != '\0') {
        char c = *tmp_c;
        if (c >= '0' && c <= '9') {
            ++digits;
            const int delta = (c - '0');
            static const uint64_t kMaxUint64 = ~static_cast<uint64_t>(0);
            if (v > kMaxUint64/10 ||
                    (v == kMaxUint64/10 && delta > kMaxUint64%10)) {    // 溢出判断
                // Overflow
                return false;
            }
            v = (v * 10) + delta;   // v = 上次的值 * 10 + 当前解析的数字
            ++tmp_c;
        } else {
            break;
        }
  }
  *val = v;
  return (digits > 0);
}


int main() {
    const char* str = "19890920";
    uint64_t v;
    if (ConsumeDecimalNumber(str, &v)) {
        std::cout << str << ": " << v << std::endl;
    } else {
        std::cout << "error" << std::endl;
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
