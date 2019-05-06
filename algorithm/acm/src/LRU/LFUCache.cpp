#include "scheduling\LFUCache.h"

// LeetCode460 LFU����
int LFUCache::get(int key)
{
    // û�ҵ�������-1
    if (m_KeyIter.count(key) == 0) return -1;

    // �ҵ��ˣ���Ҫ�������ô���
    int nCnt = m_KeyValueCnt[key].second++;
    // ԭ���ô�������ɾ����Ԫ�أ���������push_back
    m_CntKeys[nCnt].erase(m_KeyIter[key]);
    m_CntKeys[++nCnt].push_front(key);
    m_KeyIter[key] = m_CntKeys[nCnt].begin();

    m_nMinCnt += (m_CntKeys[m_nMinCnt].size() == 0 ? 1 : 0);
    return m_KeyValueCnt[key].first;
}

void LFUCache::put(int key, int value)
{
    if (m_nCapacity <= 0) return;

    // ��key�Ѵ��ڣ�����get����˳�򣬲�����value
    if (get(key) != -1)
    {
        m_KeyValueCnt[key].first = value;
        return;
    }

    // ��Ҫ�Ƴ�Ԫ��(m_nMinCnt��listβ��Ԫ��)
    if (m_KeyValueCnt.size() == m_nCapacity)
    {
        m_KeyValueCnt.erase(m_CntKeys[m_nMinCnt].back());
        m_KeyIter.erase(m_CntKeys[m_nMinCnt].back());
        m_CntKeys[m_nMinCnt].pop_back();
    }

    //����Ԫ��
    m_nMinCnt = 1;

    m_CntKeys[1].push_front(key);
    m_KeyIter[key] = m_CntKeys[1].begin();
    m_KeyValueCnt[key] = make_pair(value, 1);
}

bool LFUCache::solve()
{
    return true;
}

