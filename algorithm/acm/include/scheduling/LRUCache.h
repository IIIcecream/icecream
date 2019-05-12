#pragma once
#include "IACM.h"
#include <list>
#include <unordered_map>
using namespace std;

// LRU缓存机制(Least recently used 最近最少使用,首先淘汰最长时间未被使用的页面,关键是看页面最后一次被使用到发生调度的时间长短)
class LRUCache : public IACM
{
public:
    LRUCache(int capacity) : m_nCapacity(capacity) {}
    int get(int key);
    void put(int key, int value);

    virtual bool solve() override;

private:
    int m_nCapacity;
    list<pair<int, int>> m_list;
    unordered_map<int, list<pair<int, int>>::iterator> m_map;
};