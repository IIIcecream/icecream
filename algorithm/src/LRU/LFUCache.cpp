#include "scheduling\LFUCache.h"

// LeetCode460 LFU缓存
int LFUCache::get(int key)
{
    // 没找到，返回-1
    if (m_KeyIter.count(key) == 0) return -1;

    // 找到了，需要调整引用次数
    int nCnt = m_KeyValueCnt[key].second++;
    // 原引用次数分组删除该元素，在新组中push_back
    m_CntKeys[nCnt].erase(m_KeyIter[key]);
    m_CntKeys[++nCnt].push_front(key);
    m_KeyIter[key] = m_CntKeys[nCnt].begin();

    m_nMinCnt += (m_CntKeys[m_nMinCnt].size() == 0 ? 1 : 0);
    return m_KeyValueCnt[key].first;
}

void LFUCache::put(int key, int value)
{
    if (m_nCapacity <= 0) return;

    // 该key已存在，调用get更新顺序，并更新value
    if (get(key) != -1)
    {
        m_KeyValueCnt[key].first = value;
        return;
    }

    // 需要移除元素(m_nMinCnt的list尾部元素)
    if (m_KeyValueCnt.size() == m_nCapacity)
    {
        m_KeyValueCnt.erase(m_CntKeys[m_nMinCnt].back());
        m_KeyIter.erase(m_CntKeys[m_nMinCnt].back());
        m_CntKeys[m_nMinCnt].pop_back();
    }

    //新增元素
    m_nMinCnt = 1;

    m_CntKeys[1].push_front(key);
    m_KeyIter[key] = m_CntKeys[1].begin();
    m_KeyValueCnt[key] = make_pair(value, 1);
}

bool LFUCache::solve()
{
    return true;
}

