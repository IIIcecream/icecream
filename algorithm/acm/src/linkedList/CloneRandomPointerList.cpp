#include "linkedList\CloneRandomPointerList.h"

bool CloneRandomPointerList::solve()
{
    return copyRandomList(m_pHead);
}

// LeetCode 138 Copy List with Random Pointer
// Ҳ����˿����
RandomListNode * CloneRandomPointerList::copyRandomList(RandomListNode *head)
{
    if (!head) return nullptr;

    RandomListNode *pSrc = head;

    // ��������������A->B->C->D��,��������������ֳ���A->A'->B->B'->C->C'->D->D')
    while (pSrc)
    {
        RandomListNode *pCloneNode = new RandomListNode(pSrc->val, pSrc->next, nullptr);
        pSrc->next = pCloneNode;
        pSrc = pCloneNode->next;
    }

    // ����randomָ�루���ƣ�
    pSrc = head;
    while (pSrc)
    {
        if (pSrc->random) pSrc->next->random = pSrc->random->next;
        pSrc = pSrc->next->next;
    }

    // ��ԭsrc������cloneList�����룩
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

