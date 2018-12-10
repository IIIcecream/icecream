#pragma once
#include "IACM.h"
#include "binaryTreeCommon.h"

class BalancedBinaryTree : public IACM
{
public:
    BalancedBinaryTree(TreeNode *pTree) : m_pTree(pTree) {}
    virtual bool solve() override;

protected:
    bool isBalanced(TreeNode* root);
    int getHeight(TreeNode* root);

private:
    TreeNode * m_pTree;
};