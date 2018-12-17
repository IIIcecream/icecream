#include "linkedList\MergeTwoSortedLists.h"

// Merge Two Sorted Lists LeetCode T21
bool Merge2SortedLists::solve()
{
    ListNode *pTemp = new ListNode(0), *cur = pTemp;
    while (m_pList1 && m_pList2)
    {
        if (m_pList1->val < m_pList2->val) cur->next = m_pList1, cur = m_pList1, m_pList1 = m_pList1->next;
        else cur->next = m_pList2, cur = m_pList2, m_pList2 = m_pList2->next;
    }
    if (m_pList1) cur->next = m_pList1;
    else cur->next = m_pList2;

    m_pRes = pTemp->next;
    delete pTemp;

    return true;
}

