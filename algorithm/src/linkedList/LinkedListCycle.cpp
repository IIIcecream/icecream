#include "linkedList/LinkedListCycle.h"


bool LinkedListCycle::solve()
{
    hasCycle(m_pHead);
    return true;
}
// 环形链表 LeetCode T141
bool LinkedListCycle::hasCycle(ListNode *pHead)
{
    ListNode *p1 = pHead, *p2 = pHead;
    while (p2 && p2->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) return true;
    }
    return false;
}


bool LinkedListCycleII::solve()
{
    detectCycle(m_pHead);
    return true;
}

// 环形链表 II LeetCode T142
ListNode * LinkedListCycleII::detectCycle(ListNode *head)
{
    ListNode *p1 = head, *p2 = head;
    bool b = false;
    while (p2 && p2->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2)
        {
            b = true;
            break;
        }
    }

    if (!b) return nullptr;
    p2 = head;
    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
