/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun)
 * @date 2016/08/06 21:39:10
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <cassert>

int main() {
    assert(0 > 1);  // receive signal 6, then abort() and core dump
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
