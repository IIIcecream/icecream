#pragma once

#include "IACM.h"
#include "LinkedListCommon.h"

// 相交链表,求两个链表的相交起始节点
class IntersectionLinkedLists : public IACM
{
public:
    IntersectionLinkedLists(ListNode *headA, ListNode *headB) : m_pHeadA(headA), m_pHeadB(headB) {}
    virtual bool solve() override;

private:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB);
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB);
private:
    ListNode *m_pHeadA, *m_pHeadB;
};