#include "linkedList/RemoveElements.h"

bool RemoveElements::solve()
{
    return removeElements(m_pList, m_nVal);
}

// LeetCode 203. Remove Linked List Elements
ListNode* RemoveElements::removeElements(ListNode* head, int val)
{
    ListNode *pPrev = nullptr, *pCur = head, *pDelete;

    while (pCur)
    {
        if (pCur->val == val)
        {
            pDelete = pCur;
            if (pPrev) pPrev->next = pCur->next;
            else head = pCur->next;

            pCur = pCur->next;

            delete pDelete;
        }
        else
        {
            pPrev = pCur;
            pCur = pCur->next;
        }
    }
    return head;
}

ListNode* removeElements1(ListNode* head, int val) {
    if (head == nullptr) return head;
    head->next = removeElements1(head->next, val);
    return head->val == val ? head->next : head;
}