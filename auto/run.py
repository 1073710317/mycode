#! /bin/env python
# encoding=utf-8
# bjwushaoyun@corp.netease.com
########################################################################
# 
# Copyright (c) 2016 163.com, Inc. All Rights Reserved
# 
########################################################################
 
'''
File: run.py
Author: bjwushaoyun(bjwushaoyun@corp.netease.com)
Date: 2016/08/23 10:39:33
'''

class Dealer:
    def __init__(self, title, url, phone):
        self._title = title
        self._url = url
        self._phone = phone

    def to_string(self):
        return "名称: " + self._title + ", 电话: " +  self._phone + ", 链接: " + self._url

if __name__ == "__main__":
    print "dealer info start..."
    dealer1 = Dealer("北京中进万国福特", "http://dealer.autohome.com.cn/102558", "400-872-6639")
    print dealer1.to_string()
