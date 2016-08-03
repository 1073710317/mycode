/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/08/03 10:02:12
 * @version $Revision$ 
 * @brief 参考readme
 *  
 **/

#include <iostream>

class A {  
public:
    virtual void fun() {
        std::cout << "A::fun" << std::endl;
    }
};

class AP : A {
public:
    void fun() {
        std::cout << "AP::fun" << std::endl;
    }
};

class APP : AP {
public:
    void fun() {
        std::cout << "APP::fun" << std::endl;
    }
};

class B {
public:
    void fun() {
        std::cout << "B::fun" << std::endl;
    }
};

class BP : B {  
public:  
    void fun() {
        std::cout << "BP::fun" << std::endl;
    }
};  
  
int main(int argc, char** argv) {
    A a; 
    a.fun();    // A::fun
    AP ap;  
    ((A*)&ap)->fun(); // AP::fun 

    APP app;  
    ((A*)&app)->fun(); // APP::fun 

    B b;
    b.fun(); // B::fun 
    BP bp;  
    ((B*)&bp)->fun();   // B::fun

    return 0;  
}  

/* vim: set ts=4 sw=4 sts=4 tw=100 */
