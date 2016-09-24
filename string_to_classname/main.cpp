/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun@xxoo)
 * @date 2016/09/18 17:29:44
 * @version $Revision$ 
 * @brief 演示如何在c++中，将字符串转为类名
 *  
 **/

#include <iostream>
#include <string>
#include <map>

// 方式1，通过一个工厂类，根据传递的类名来分别创建对应实例，不足之处是需要知道所有的类，且不能动态增加
class Base {
public:
    virtual void whoami() {
        std::cout << "I am Base" << std::endl;
    }
};

class DerivedA : public Base {
public:
    void whoami() {
        std::cout << "I am DerivedA" << std::endl;
    }
};

class DerivedB : public Base {
public:
    void whoami() {
        std::cout << "I am DerivedB" << std::endl;
    }
};

class BaseFactory {
public:
    BaseFactory(const std::string& class_name) {
        _class_name = class_name;
    }
    
    Base* create() {
        if (_class_name == "DerivedA") {
            return new DerivedA();
        } else if (_class_name == "DerivedB") {
            return new DerivedB();
        } else {
            std::cout << "unknown class name: " << _class_name << std::endl;
            return NULL;
        }
    };

private:
    std::string _class_name;
};

void test1(const std::string& class_name) {
    BaseFactory bf(class_name);
    Base* b = bf.create();
    if (NULL == b) {
        std::cout << "create failed: " << class_name << std::endl;
        return;
    }
    b->whoami();
    delete b;
}

// 方式2，通过一个map来管理类名和实例的映射关系，也是需要提前知道所有的类
template<typename T>
Base* createInstance() {
    return new T;
}

void test2(const std::string& class_name) {
    std::map<std::string, Base*(*)()> map;
    
    map["DerivedA"] = &createInstance<DerivedA>;
    map["DerivedB"] = &createInstance<DerivedB>;

    if (map.find(class_name) == map.end()) {
        std::cout << "create failed: " << class_name << std::endl;
    } else {
        Base* b = map[class_name]();
        b->whoami();
        delete b;
    }
}

// 方式3，可以实现让各个类自己注册，比较灵活
template<typename T>
Base* createT() {
    return new T;
}

struct BaseClassFactory {
    typedef std::map<std::string, Base*(*)()> map_type;

    static Base* createInstance(std::string const& s) {
        map_type::iterator it = getMap()->find(s);
        if (it == getMap()->end()) {
            return 0;
        }
        return it->second();
    }

protected:
    static map_type* getMap() {
        //return NULL;
        // never delete'ed. (exist until program termination)
        // because we can't guarantee correct destruction order 
        if (!map) {
            map = new map_type;
            //BaseClassFactory::map_type* map = new map_type();
        }
        return map; 
    }

private:
    static map_type* map;
};
BaseClassFactory::map_type* BaseClassFactory::map;  // 不加这个会报link error，为什么？

template<typename T>
struct DerivedRegister : BaseClassFactory { 
    DerivedRegister(std::string const& s) { 
        getMap()->insert(std::make_pair(s, &createT<T>));
    }
};

// in derivedb.hpp
class DerivedBClass : public Base {
public:
    void whoami() {
        std::cout << "I am DerivedBClass" << std::endl;
    }

private:
    static DerivedRegister<DerivedBClass> reg;
};

class DerivedAClass : public Base {
public:
    void whoami() {
        std::cout << "I am DerivedAClass" << std::endl;
    }

private:
    static DerivedRegister<DerivedAClass> reg;
};

// in derivedb.cpp:
DerivedRegister<DerivedAClass> DerivedAClass::reg("DerivedA");
DerivedRegister<DerivedBClass> DerivedBClass::reg("DerivedB");

void test3(const std::string& class_name) {
    Base* b = BaseClassFactory::createInstance(class_name);
    if (NULL == b) {
        std::cout << "create failed: " << class_name << std::endl;
        return;
    }
    b->whoami();
}

int main() {
    std::cout << "test1..." << std::endl;
    // 方式1的测试例子
    test1("DerivedA");
    test1("DerivedB");
    test1("DerivedC");

    std::cout << "test2..." << std::endl;
    // 方式2的测试例子
    test2("DerivedA");
    test2("DerivedB");
    test2("DerivedC");

    std::cout << "test3..." << std::endl;
    // 方式3的测试例子
    test3("DerivedA");
    test3("DerivedB");
    test3("DerivedC");

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
