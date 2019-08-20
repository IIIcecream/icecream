#pragma once

#include "IACM.h"
#include "LinkedListCommon.h"

// ÒÆ³ýÁ´±íÔªËØ
class RemoveElements : public IACM
{
public:
    RemoveElements(ListNode* head, int val) : m_pList(head), m_nVal(val) {}
    virtual bool solve() override;

private:
    ListNode* removeElements(ListNode* head, int val);

private:
    ListNode *m_pList;
    int m_nVal;
};