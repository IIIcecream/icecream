#pragma once
#include "IACM.h"
#include <list>
#include <unordered_map>
using namespace std;

// LRU»º´æ»úÖÆ
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