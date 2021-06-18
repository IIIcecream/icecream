#pragma once
#include "IACM.h"
#include "binaryTreeCommon.h"

/*!
*@brief        二叉树展开为链表（前序形式）
*@author       tangw-b  2018/12/07  11:10
*/
class BinaryTreetoLinkedList : public IACM
{
public:
    BinaryTreetoLinkedList(TreeNode *pTree) : m_pTree(pTree) {}
    virtual bool solve() override  { return false; }

private:
    void flatten(TreeNode* pNode);
    TreeNode *getLeftTreeRightNode(TreeNode *pNode);
private:
    TreeNode * m_pTree;
};
