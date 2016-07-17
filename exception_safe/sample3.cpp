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
 * @brief 使用对象来管理锁，实现异常安全
 *  
 **/

#include <iostream>
#include <exception>
#include <stdexcept>
#include <pthread.h>

class CSubClass {
public:
    CSubClass() {

    }
};

class CMutex {
public:
    void lock() {
        std::cout << "lock." << std::endl;
    }

    void unlock() {
        std::cout << "unlock." << std::endl;
    }
};

class CLock {
public:
    explicit CLock(CMutex& lock1) : m_lock(lock1) {
        m_lock.lock();
    }

    ~CLock() {
        m_lock.unlock();
    }

private:
    CMutex& m_lock;
};

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
    CLock clock(_p_mutex);  // 函数执行结束后，会自动调用CLock的析构函数，进行释放锁的操作
    // do something

    delete _p_data;
    _p_data = new CSubClass();      // 假如此处抛出异常，会导致两个问题：1：m_mutex将永远不会被unlock 2：_p_data将成为野指针
}

int main() {
    CClass cclass;
    cclass.do_something();
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
