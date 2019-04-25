#include "scheduling\LRUCache.h"

// LeetCode 146 LRU Cache
int LRUCache::get(int key)
{
    if (!m_map.count(key)) return -1;

    // ���ýڵ����������λ
    m_list.splice(m_list.begin(), m_list, m_map[key]);
    return m_map[key]->second;
}

void LRUCache::put(int key, int value)
{
    // �Ѿ�����key
    if (m_map.count(key))
    {
        m_map[key]->second = value;
        m_list.splice(m_list.begin(), m_list, m_map[key]);
        return;
    }
    // �жϵ�ǰ���ȣ��Ƿ���Ҫɾ��������ĩβԪ�أ��Լ�map��Ҳ��ɾ���ýڵ�
    if (m_list.size() == m_nCapacity)
    {
        m_map.erase(m_list.back().first);
        m_list.pop_back();
    }

    // ���ýڵ����������λ
    m_list.push_front(make_pair(key, value));
    m_map[key] = m_list.begin();
}

bool LRUCache::solve()
{
    return true;
}

