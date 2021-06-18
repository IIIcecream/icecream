#pragma once
#include "IACM.h"
#include "binaryTreeCommon.h"

// Sum Root to Leaf Numbers
class SumRootToLeafNumbers : public IACM
{
public:
    SumRootToLeafNumbers(TreeNode* root) : m_pRoot(root) {}
    virtual bool solve() override;

private:
    void sumNumbers(TreeNode* root, int sum = 0);

private:
    TreeNode *m_pRoot;
    int m_nRes = 0;
};