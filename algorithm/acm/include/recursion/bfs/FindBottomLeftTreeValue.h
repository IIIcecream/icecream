#pragma once

#include "IACM.h"
struct TreeNode;

// 找树最下层最左边元素
class FindBottomLeftTreeValue : public IACM
{
public:
    FindBottomLeftTreeValue(TreeNode* root) : m_pRoot(root) {}
    virtual bool solve() override;

private:
    int findBottomLeftValue(TreeNode* root);

private:
    TreeNode* m_pRoot;
};