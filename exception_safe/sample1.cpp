/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/07/16 15:17:19
 * @version $Revision$ 
 * @brief 一个没有实现异常安全的实例
 *  
 **/

#include <iostream>
#include <exception>
#include <pthread.h>

class CSubClass {
    CSubClass() {
        throw runtime_error("runtime error from CSubClass()");
    }
};

class CMutex {

};

void lock(CMutex mutex) {

}

void unlock(CMutex mutex) {

}

// CClass应用在多线程环境中，即会有多个线程操作CClass的实例
class CClass {
public:
    CClass();

    ~CClass();

    void do_something();

private:
    CSubClass* _p_data;
    CMutex _p_mutex;
};

void CClass::do_something() {
    lock(_p_mutex);
    
    // do something

    delete _p_data;
    _p_data = new CSubClass();      // 假如此处抛出异常，会导致两个问题：1：m_mutex将永远不会被unlock 2：_p_data将成为野指针

    unlock(_p_mutex);
}

int main() {
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
