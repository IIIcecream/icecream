#pragma once

#include <vector>
#include <string>
#include "IACM.h"
#include "binaryTreeCommon.h"

using std::vector;
using std::string;

// ������������·��
class BinaryTreePaths : public IACM
{
public:
    BinaryTreePaths(TreeNode* root) : m_pRoot(root) {}

    virtual bool solve() override { return false; }

private:
    vector<string> binaryTreePaths(TreeNode* root);

    void binaryTreePaths(TreeNode *pNode, string sCurPath, vector<string> &paths);
private:
    TreeNode* m_pRoot;
};
