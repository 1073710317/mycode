/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun)
 * @date 2016/07/16 15:17:19
 * @version $Revision$ 
 * @brief 一个没有实现异常安全的实例
 *  
 **/

#include <iostream>
#include <exception>
#include <stdexcept>
#include <pthread.h>

class CSubClass {
public:
    CSubClass() {
        // terminate called after throwing an instance of 'std::runtime_error'
        // what():  runtime error from CSubClass()
        //   Aborted
        throw std::runtime_error("runtime error from CSubClass()"); // 事实上此处抛出异常后，由于没有找到对应的catch，程序将会终止，如上面所示
    }
};

class CMutex {

};

void lock(CMutex mutex) {
    std::cout << "lock." << std::endl;
}

void unlock(CMutex mutex) {
    std::cout << "unlock." << std::endl;
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

CClass::CClass() {

}

CClass::~CClass() {

}

void CClass::do_something() {
    lock(_p_mutex);
    
    // do something

    delete _p_data;
    _p_data = new CSubClass();      // 假如此处抛出异常，会导致两个问题：1：m_mutex将永远不会被unlock 2：_p_data将成为野指针

    unlock(_p_mutex);
}

int main() {
    CClass cclass;
    cclass.do_something();
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
