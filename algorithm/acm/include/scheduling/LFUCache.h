#pragma once
#include "IACM.h"
#include <list>
#include <unordered_map>
using namespace std;

// LFU缓存机制(Least frequently used 最不经常使用,淘汰一定时期内被访问次数最少的页,关键是看一定时间段内页面被使用的频率)
class LFUCache : public IACM
{
public:
    LFUCache(int capacity) : m_nCapacity(capacity) {}
    int get(int key);
    void put(int key, int value);

    virtual bool solve() override;

private:
    int m_nCapacity, m_nMinCnt = 0;
    unordered_map<int, list<int>> m_CntKeys;    // <cnt, list<key>> cnt为访问次数，用于维护与体现LFU，list的begin是最近被使用的，back是未被使用的
    unordered_map<int, pair<int, int>> m_KeyValueCnt; // <key, pair<value, cnt>>，用于通过key查找value及访问次数
    unordered_map<int, list<int>::iterator> m_KeyIter;  // <key, iter> 该key对应的m_CntKeys的迭代器，用于通过key快速找到元素在m_CntKeys链表中的位置，方便删除，从O(n)-->O(1)
};