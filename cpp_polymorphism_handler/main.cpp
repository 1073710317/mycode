/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author wsy(wsy@baidu.com)
 * @date 2016/07/24 20:40:43
 * @version $Revision$ 
 * @brief 关于c++中多态的一个例子
 *  
 **/

#include <iostream>
#include <map>

class IEngine {
public:
    IEngine() {
        std::cout << "In IEngine::IEngine()" << std::endl;
    }

    ~IEngine() {
        std::cout << "In IEngine::~IEngine()" << std::endl;
    }

    virtual void handle() = 0;
};

class JianEngine : public IEngine {
public:
    JianEngine() {
        std::cout << "In JianEngine::JianEngine()" << std::endl;
    }

    ~JianEngine() {
        std::cout << "In JianEngine::~JianEngine()" << std::endl;
    }

    void handle() {
        std::cout << "in JianEngine::handle()" << std::endl;
    }
};

class RelEngine : public IEngine {
public:
    RelEngine() {
        std::cout << "In RelEngine::RelEngine()" << std::endl;
    }

    ~RelEngine() {
        std::cout << "In RelEngine::~RelEngine()" << std::endl;
    }

    void handle() {
        std::cout << "in RelEngine::handle()" << std::endl;
    }
};


int main() {
    std::map<std::string, IEngine*> engine_map;

    JianEngine* jian_engine = new JianEngine();
    if (NULL == jian_engine) {
        std::cout << "new JianEngine() failed" << std::endl;
        return -1;
    }

    RelEngine* rel_engine = new RelEngine();
    if (NULL == rel_engine) {
        std::cout << "new RelEngine() failed" << std::endl;

        if (NULL != jian_engine) {
            delete jian_engine;
            jian_engine = NULL;
        }

        return -1;
    }

    engine_map["jian"] = jian_engine;
    engine_map["rel"] = rel_engine;

    IEngine* cur_engine = engine_map["jian"];
    cur_engine->handle();   // call JianEngine.handle()

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
