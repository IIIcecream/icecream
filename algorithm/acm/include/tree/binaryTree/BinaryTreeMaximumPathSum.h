#pragma once
#include "IACM.h"
#include "binaryTreeCommon.h"
#include "ACMMathCommon.h"

// �������е����·���� Binary Tree Maximum Path Sum
class BTMaxPathSum : public IACM
{
public:
    BTMaxPathSum(TreeNode *pTree) : m_pTree(pTree) {}
    virtual bool solve() override;

private:
    int maxPathSum(TreeNode* root);

private:
    TreeNode * m_pTree;
    int m_nRes = INT_MIN;
};