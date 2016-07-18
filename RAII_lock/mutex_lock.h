/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file mutex_lock.h
 * @author wsy(wsy@baidu.com)
 * @date 2016/07/18 21:38:01
 * @version $Revision$ 
 * @brief 
 *  
 **/
#ifndef MUTEX_LOCK_H
#define MUTEX_LOCK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

class Mutex {
public:
    Mutex();
    
    ~Mutex();
    
    void Lock();
    
    void Unlock();
    
    void AssertHeld() { }

private:
    pthread_mutex_t mu_;

    // No copying
    Mutex(const Mutex&);
    void operator=(const Mutex&);
};

static void PthreadCall(const char* label, int result) {
    if (result != 0) {
        fprintf(stderr, "pthread %s: %s\n", label, strerror(result));
        abort();
    }
}

Mutex::Mutex() {
    PthreadCall("init mutex", pthread_mutex_init(&mu_, NULL));
}

Mutex::~Mutex() {
    PthreadCall("destroy mutex", pthread_mutex_destroy(&mu_));
}

void Mutex::Lock() {
    PthreadCall("lock", pthread_mutex_lock(&mu_));
}

void Mutex::Unlock() {
    PthreadCall("unlock", pthread_mutex_unlock(&mu_));
}

class MutexLock {
public:
    explicit MutexLock(Mutex *mu) : mu_(mu) {
        this->mu_->Lock();
    }
    
    ~MutexLock() {
        this->mu_->Unlock();
    }

private:
    Mutex *const mu_;
 
    // No copying allowed  // boost中有noncopyable
    MutexLock(const MutexLock&);
    void operator=(const MutexLock&);
};

#endif  // MUTEX_LOCK_H

/* vim: set ts=4 sw=4 sts=4 tw=100 */
