#pragma once
#include "IACM.h"
#include "LinkedListCommon.h"

// Linked List Cycle
class LinkedListCycle : public IACM
{
public:
    LinkedListCycle(ListNode *pHead) : m_pHead(pHead) {}
    virtual bool solve() override;

private:
    bool hasCycle(ListNode *phead);

private:
    ListNode * m_pHead;
};


// Linked List Cycle II
class LinkedListCycleII : public IACM
{
public:
    LinkedListCycleII(ListNode *pHead) : m_pHead(pHead) {}
    virtual bool solve() override;

private:
    ListNode *detectCycle(ListNode *head);

private:
    ListNode * m_pHead;
};