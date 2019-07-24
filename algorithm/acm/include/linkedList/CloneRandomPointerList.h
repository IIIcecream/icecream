#pragma once
#include "IACM.h"

struct RandomListNode {
    int val;
    RandomListNode* next,* random;

    RandomListNode(int x) : val(x), next(nullptr), random(nullptr) {}
    RandomListNode(int _val, RandomListNode* _next, RandomListNode* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

// 复制带随机指针的链表
class CloneRandomPointerList : public IACM
{
public:
    CloneRandomPointerList(RandomListNode *head) : m_pHead(head) {}
    virtual bool solve() override;

private:
    RandomListNode *copyRandomList(RandomListNode *head);

private:
    RandomListNode * m_pHead;
};