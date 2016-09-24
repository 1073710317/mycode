/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@xxoo)
 * @date 2016/09/19 10:41:35
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <pthread.h>

struct msg {
    int data;
    struct msg* next;
};

struct msg* work_q;

pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void process_msg() {
    struct msg* mp;
    for (;;) {
        pthread_mutex_lock(&qlock);
        while (work_q == NULL) {
            pthread_cond_wait(&qready, &qlock);
        }
        mp = work_q;
        work_q = mp->next;
        pthread_mutex_unlock(&qlock);

        // process the message mp
    }
}

void enqueue_msg(struct msg* mp) {
    pthread_mutex_lock(&qlock);
    mp->next = work_q;
    work_q = mp;
    pthread_mutex_unlock(&qlock);
    pthread_cond_signal(&qready);
}

int main() {
    // 创建一个主线程，负责写入队列，一次性写入10000个？
    // 创建N个工作线程，负责从队列中读取数据
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
