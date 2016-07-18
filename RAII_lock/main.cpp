/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author wsy(wsy@baidu.com)
 * @date 2016/07/18 21:27:00
 * @version $Revision$ 
 * @brief 测试RAII机制的锁
 *  
 **/

#include <iostream>
#include <pthread.h>
#include "mutex_lock.h"

const int thr_num = 3;

// 锁
Mutex mutex;

int global = 0;

void* thr_fun(void* arg) {
    while (1) {
        MutexLock lock(&mutex);

        pthread_t tid = pthread_self();
        printf("tid: %d, get the lock, before global = %d\n", (unsigned int)tid, global);
        global += 1;
        printf("tid: %d, get the lock, after global = %d\n", (unsigned int)tid, global);
    }
}

int main() {
    int err = 0;
    pthread_t pids[thr_num];

    for (int i = 0; i < thr_num; ++i) {
        err = pthread_create(&(pids[i]), NULL, thr_fun, NULL);
        if (0 != err) {
            printf("create thread failed\n");
            return -1;
        }
    }

    for (int i = 0; i < thr_num; ++i) {
        pthread_join(pids[i], NULL);
    } 
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
