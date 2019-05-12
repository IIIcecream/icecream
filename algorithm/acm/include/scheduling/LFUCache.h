#pragma once
#include "IACM.h"
#include <list>
#include <unordered_map>
using namespace std;

// LFU�������(Least frequently used �����ʹ��,��̭һ��ʱ���ڱ����ʴ������ٵ�ҳ,�ؼ��ǿ�һ��ʱ�����ҳ�汻ʹ�õ�Ƶ��)
class LFUCache : public IACM
{
public:
    LFUCache(int capacity) : m_nCapacity(capacity) {}
    int get(int key);
    void put(int key, int value);

    virtual bool solve() override;

private:
    int m_nCapacity, m_nMinCnt = 0;
    unordered_map<int, list<int>> m_CntKeys;    // <cnt, list<key>> cntΪ���ʴ���������ά��������LFU��list��begin�������ʹ�õģ�back��δ��ʹ�õ�
    unordered_map<int, pair<int, int>> m_KeyValueCnt; // <key, pair<value, cnt>>������ͨ��key����value�����ʴ���
    unordered_map<int, list<int>::iterator> m_KeyIter;  // <key, iter> ��key��Ӧ��m_CntKeys�ĵ�����������ͨ��key�����ҵ�Ԫ����m_CntKeys�����е�λ�ã�����ɾ������O(n)-->O(1)
};