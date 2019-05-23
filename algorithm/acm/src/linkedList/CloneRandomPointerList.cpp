#include "linkedList\CloneRandomPointerList.h"

bool CloneRandomPointerList::solve()
{
    return copyRandomList(m_pHead);
}

// LeetCode 138 Copy List with Random Pointer
// 也叫有丝分裂
RandomListNode * CloneRandomPointerList::copyRandomList(RandomListNode *head)
{
    if (!head) return nullptr;

    RandomListNode *pSrc = head;

    // 复制正常的链表（A->B->C->D）,复制完后，让它呈现出（A->A'->B->B'->C->C'->D->D')
    while (pSrc)
    {
        RandomListNode *pCloneNode = new RandomListNode(pSrc->val, pSrc->next, nullptr);
        pSrc->next = pCloneNode;
        pSrc = pCloneNode->next;
    }

    // 连接random指针（复制）
    pSrc = head;
    while (pSrc)
    {
        if (pSrc->random) pSrc->next->random = pSrc->random->next;
        pSrc = pSrc->next->next;
    }

    // 还原src及连接cloneList（分离）
    pSrc = head;
    RandomListNode *pRes = pSrc->next, *pTemp;
    while (pSrc->next)
    {
        pTemp = pSrc->next;
        pSrc->next = pSrc->next->next;
        pSrc = pTemp;
    }

    return pRes;
}

