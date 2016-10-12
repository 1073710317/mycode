/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/10/08 16:05:02
 * @version $Revision$ 
 * @brief 摘自muduo中的fileutil
 *  
 **/

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <iostream>
#include <string>

class AppendFile {
public:
    explicit AppendFile(std::string filename) : _fp(::fopen(filename.c_str(), "ae")), _written_bytes(0) {
        assert(_fp);
    }
    
    ~AppendFile() {
        ::fclose(_fp);
    }
    
    int append(const char* logline, const size_t len) {
        _written_bytes = 0;
        size_t n = write(logline, len);
        size_t remain = len - n;
        while (remain > 0) {
            size_t x = write(logline + n, remain);
            if (x == 0) {
                int err = ferror(_fp);
                if (err) {
                    //fprintf(stderr, "AppendFile::append() failed %s\n", strerror_tl(err));
                    fprintf(stderr, "AppendFile::append() failed %s\n", strerror(err));
                }
                break;
            }
            n += x;
            remain = len - n; // remain -= x
        }
        _written_bytes += len;
        return _written_bytes;
    }
    
    void flush() {
        ::fflush(_fp);
    }
    
    size_t written_bytes() const {
        return _written_bytes;
    }

private:
    size_t write(const char* logline, size_t len) {
        return ::fwrite_unlocked(logline, 1, len, _fp);
    }
    
    FILE* _fp;
    char _buffer[64 * 1024];
    size_t _written_bytes;
   
    // non-copyable
    AppendFile(const AppendFile&);
    void operator=(const AppendFile&);
};

void* thr_fun(void* arg) {
    AppendFile* append = static_cast<AppendFile*>(arg);
    const char* str = "wushaoyun\n";
    int i = 0;
    while (i < 10000) {
        append->append(str, strlen(str));
        ++i;
    }
    return NULL;
}

int main() {
    AppendFile* append = new AppendFile("file.txt");

    pthread_t tid;
    for (int i = 0; i < 100; ++i) {
        pthread_create(&tid, NULL, thr_fun, append);
    }

    delete append;

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
