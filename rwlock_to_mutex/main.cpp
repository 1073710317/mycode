/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun)
 * @date 2016/08/17 21:39:48
 * @version $Revision$ 
 * @brief 用互斥锁替换读写锁的一个例子
 *  
 **/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>

class CustomerData : boost::noncopyable {   // 为简化编译，略去这个
public:
    CustomerData() : _data(new Map) {
        
    }

    int query() const {
        MapPtr data = get_data();
        // data一旦拿到，就不需要锁了，get_data内部有锁，多线程并发读的性能很好
        return 0;
    }

    void update(const std::string& cutosmer, const EntryList& entries) {
        MutexLockGuard lock(_mutex);
        if (!_data.unique()) {   // 已经有线程在读数据，为了避免不影响读，复制一份数据让它读
            MapPtr new_data(new Map(*_data));
            _data.swap(new_data);   // 此时读线程读的是new_data上的数据
        }
        assert(_data.unique()); // 继续在_data上修改
        (*_data)[customer] = entries;
    }

    MapPtr get_data() const {
        MutexLockGuard lock(_mutex);
        return _data;
    }

private:
    typedef std::pair<std::string, int> Entry;
    typedef std::vector<Entry> EntryList;
    typedef std::map<std::string, EntryList> Map;
    typedef boost::shared_ptr<Map> MapPtr;
    MapPtr _data;

    mutable MutexLock _mutex;
};

int main() {
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
