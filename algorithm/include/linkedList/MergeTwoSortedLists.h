#pragma once
#include "IACM.h"
#include "linkedList/LinkedListCommon.h"

// 合并两个有序链表
class Merge2SortedLists : public IACM
{
public:
    Merge2SortedLists(ListNode* l1, ListNode* l2) : m_pList1(l1), m_pList2(l2) {}
    virtual bool solve() override;

private:
    ListNode *m_pList1, *m_pList2, *m_pRes = nullptr;
};
