/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file queue_use_template.cpp
 * @author bjwushaoyun(bjwushaoyun@corp.netease.com)
 * @date 2016/07/17 14:37:41
 * @version $Revision$ 
 * @brief 使用template实现自己的queue，参考c++ primer中的讲解
 *  
 **/

#include <iostream>
#include <vector>
#include <string>

template <class Type>
class Queue {
public:
    /**
     * @brief 
     *
     * @see 
     * @author bjwushaoyun
     * @date 2016/07/17 14:43:49
    **/
    Queue() {

    }

    /**
     * @brief 
     *
     * @return  Type& 
     * @retval   
     * @see 
     * @author bjwushaoyun
     * @date 2016/07/17 14:43:54
    **/
    Type& front();

    /**
     * @brief 
     *
     * @return  const Type& 
     * @retval   
     * @see 
     * @author bjwushaoyun
     * @date 2016/07/17 14:43:57
    **/
    const Type& front() const;

    /**
     * @brief 
     *
     * @return  void 
     * @retval   
     * @see 
     * @author bjwushaoyun
     * @date 2016/07/17 14:44:02
    **/
    void push(const Type&);

    /**
     * @brief 
     *
     * @return  void 
     * @retval   
     * @see 
     * @author bjwushaoyun
     * @date 2016/07/17 14:44:07
    **/
    void pop();

    /**
     * @brief 
     *
     * @return  bool 
     * @retval   
     * @see 
     * @author bjwushaoyun
     * @date 2016/07/17 14:44:11
    **/
    bool empty() const;

private:

};

int main() {
    // 如下代码中，编译器使用实参来实例化Queue的特定类型版本，实际上，编译器用提供的特定类型代替Type，重新编写Queue类

    Queue<int> qi;
    Queue< std::vector<double> > qc;
    Queue<std::string> qs;

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
