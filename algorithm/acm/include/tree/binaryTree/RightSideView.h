#pragma once
#include "IACM.h"
#include <vector>

struct TreeNode;
using std::vector;

// ¶þ²æÊ÷µÄÓÒÊÓÍ¼
class RightSideView : public IACM
{
public:
    RightSideView(TreeNode* root) : m_pRoot(root) {}
    virtual bool solve() override;

private:
    vector<int> rightSideView(TreeNode* root);

private:
    TreeNode* m_pRoot;
};