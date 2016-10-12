#! /bin/env python
# encoding=utf-8
# bjwushaoyun@corp.netease.com
# -*- coding: gb18030 -*-
#!/usr/bin/env python
########################################################################
# 
# Copyright (c) 2016 163.com, Inc. All Rights Reserved
# 
########################################################################
 
'''
File: sample1.py
Author: bjwushaoyun(bjwushaoyun@corp.netease.com)
Date: 2016/09/26 11:06:18
'''
# 

  
class people:  
    #定义基本属性  
    name = ''  
    age = 0  
    #定义私有属性,私有属性在类外部无法直接进行访问  
    __weight = 0  
    #定义构造方法  
    def __init__(self,n,a,w):  
        self.name = n  
        self.age = a  
        self.__weight = w  
    def speak(self):  
        print("%s is speaking: I am %d years old" %(self.name,self.age))  
  
class student(people):  
    grade = ''  
    def __init__(self,n,a,w,g):  
        #调用父类的构函  
        people.__init__(self,n,a,w)  
        self.grade = g  
    #覆写父类的方法  
    def speak(self):  
        print("%s is speaking: I am %d years old,and I am in grade %d"%(self.name,self.age,self.grade))  
 
p = people('tom',10,30)  
p.speak() 
  
s = student('ken',20,60,3)  
s.speak()
