/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file sample4.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/07/17 11:59:31
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <memory>

class CSubClass1 {

};

class CSubClass2 {

};

class CClass {
public:
    void do_something();

private:
    std::auto_ptr<CSubClass1> m_pdata1;
    std::auto_ptr<CSubClass2> m_pdata2;
};

void CClass::do_something() {
    // do something

    m_pdata1.reset(new CSubClass1);
    m_pdata2.reset(new CSubClass2);
}

int main() {
    CClass cclass;
    cclass.do_something();
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
