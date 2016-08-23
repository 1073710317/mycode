/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun)
 * @date 2016/08/10 20:12:53
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <signal.h>
#include <stdlib.h>

static void sig_usr(int signo) {
    if (signo == SIGUSR1) {
        std::cout << "receive SIGUSR1" << std::endl;
        exit(0);
    }
}

static void sig_abrt(int signo) {
    if (signo == SIGABRT) {
        std::cout << "receive SIGABRT" << std::endl;
        exit(0);
    }
}

int main() {
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        std::cout << "can't catch SIGUSR1" << std::endl;
        return -1;
    }
    
    if (signal(SIGABRT, sig_abrt) == SIG_ERR) {
        std::cout << "can't catch SIGABRT" << std::endl;
        return -1;
    }
    
    while (1) {

    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
