#include "scheduling\LRUCache.h"

// LeetCode 146 LRU Cache
int LRUCache::get(int key)
{
    if (!m_map.count(key)) return -1;

    // 将该节点放在链表首位
    m_list.splice(m_list.begin(), m_list, m_map[key]);
    return m_map[key]->second;
}

void LRUCache::put(int key, int value)
{
    // 已经存在key
    if (m_map.count(key))
    {
        m_map[key]->second = value;
        m_list.splice(m_list.begin(), m_list, m_map[key]);
        return;
    }
    // 判断当前长度，是否需要删除链表最末尾元素，以及map中也得删除该节点
    if (m_list.size() == m_nCapacity)
    {
        m_map.erase(m_list.back().first);
        m_list.pop_back();
    }

    // 将该节点放在链表首位
    m_list.push_front(make_pair(key, value));
    m_map[key] = m_list.begin();
}

bool LRUCache::solve()
{
    return true;
}

