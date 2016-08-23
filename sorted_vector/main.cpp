/***************************************************************************
 * 
 * Copyright (c) 2016 163.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file main.cpp
 * @author bjwushaoyun(bjwushaoyun)
 * @date 2016/08/22 13:50:38
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef struct _detail_info {
    int id;
    std::string docid;
    double weight;
} DetailInfo;

typedef std::vector<std::string> DocVec;
typedef DocVec::iterator DocVecIt;
typedef std::map<int, DocVec*> IndexMap; // vector内的元素，需要保持有序，具体是按照DetailInfo中的weight进行排序
typedef IndexMap::iterator IndexIt;
typedef std::map<std::string, DetailInfo> DetailMap;

IndexMap index_map;
DetailMap detail_map;

int add(const DetailInfo& detail_info) {
    const int& id = detail_info.id;
    const std::string& docid = detail_info.docid;
    const double& weight = detail_info.weight;

    IndexIt find_it = index_map.find(id);
    if (find_it != index_map.end()) {
        std::cout << "found it" << std::endl;
        DocVec* cur_vec = index_map[id];
        // 插入到原有vector，并保证有序
        for (DocVecIt doc_it = cur_vec->begin(); doc_it != cur_vec->end(); ++doc_it) {
            double cur_weight = detail_map[*doc_it].weight;
            if (weight > cur_weight) {
                //cur_vec->push_back(docid);  // 会不会对上面的for循环有影响
                cur_vec->insert(doc_it, docid);
                break;
            }
        }
    } else {
        std::cout << "no found that" << std::endl;
        // 直接新增一个序列
        std::vector<std::string>* news_vec = new std::vector<std::string>;
        news_vec->push_back(docid);
        index_map[id] = news_vec;
    }

    detail_map[docid] = detail_info;

    return 0;
}

void traverse() {
    for (IndexIt it = index_map.begin(); it != index_map.end(); ++it) {
        std::cout << it->first << ": ";
        for (DocVecIt doc_it = (it->second)->begin(); doc_it != (it->second)->end(); ++doc_it) {
            std::cout << "(" << detail_map[*doc_it].id << ", " << 
                detail_map[*doc_it].docid << ", " << detail_map[*doc_it].weight << ") -> ";
        }
        std::cout << "NIL" << std::endl;
    }
}

DetailInfo build_detail_info(int id, std::string docid, double weight) {
    DetailInfo dti;
    dti.id = id;
    dti.docid = docid;
    dti.weight = weight;
    return dti;
}

int main() {
    IndexMap index_map;
    DetailMap detail_map;

    add(build_detail_info(1, "docid1", 1.1));
    add(build_detail_info(1, "docid2", 1.2));
    add(build_detail_info(2, "docid3", 1.3));
    add(build_detail_info(2, "docid4", 1.4));
    add(build_detail_info(1, "docid5", 1.2));
    add(build_detail_info(1, "docid6", 2.2));
    add(build_detail_info(1, "docid7", 3.2));
    add(build_detail_info(1, "docid8", 2.12));
    add(build_detail_info(1, "docid9", 1.12));
    add(build_detail_info(1, "docid10", 8.12));

    traverse();

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
