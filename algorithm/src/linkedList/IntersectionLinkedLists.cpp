#include "linkedList/IntersectionLinkedLists.h"
#include "ACMMathCommon.h"

bool IntersectionLinkedLists::solve()
{
    return getIntersectionNode(m_pHeadA, m_pHeadB);
}

// leetCode 160. Intersection of Two Linked Lists
ListNode * IntersectionLinkedLists::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    return getIntersectionNode2(headA, headB);
}

/*!
*@brief        方法1：获取两个链表长度差m，长的那个链表先走m步，然后两个链表同时走，看节点是不是相等即可
*@author       tangw  2019/08/01  10:17
*/
ListNode * IntersectionLinkedLists::getIntersectionNode1(ListNode *headA, ListNode *headB)
{
    int nLenA = 0, nLenB = 0;
    ListNode *pA = headA, *pB = headB;
    while (pA) nLenA++, pA = pA->next;
    while (pB) nLenB++, pB = pB->next;

    pA = headA, pB = headB;
    int nSub = abs(nLenA - nLenB);
    if (nLenA > nLenB) while (nSub--) pA = pA->next;
    else while (nSub--) pB = pB->next;

    while (pA)
    {
        if (pA == pB) return pA;
        pA = pA->next;
        pB = pB->next;
    }
    return nullptr;
}

/*!
*@brief        方法2：核心思想同1方法类似，也是消除两个链表的长度差
               本方法在pA==nullptr一次 pB==nullptr一次之后，pA和PB就消除了长度差了
*@author       tangw  2019/08/01  10:17
*/
ListNode * IntersectionLinkedLists::getIntersectionNode2(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB) return nullptr;

    ListNode *pA = headA, *pB = headB;
    while (pA != pB)
    {
        pA = (pA ? pA->next : headB);
        pB = (pB ? pB->next : headA);
    }
    return pA;
}

