#include "tree/binaryTree/BinaryTreePaths.h"

bool BinaryTreePaths::solve()
{
    binaryTreePaths(m_pRoot);
    return true;
}

// LeetCode 257. Binary Tree Paths
vector<string> BinaryTreePaths::binaryTreePaths(TreeNode* root)
{
    vector<string> res;
    if (!root) return res;

    binaryTreePaths(root, "", res);
    return res;
}

void BinaryTreePaths::binaryTreePaths(TreeNode *pNode, string sCurPath, vector<string> &paths)
{
    sCurPath.append((sCurPath.empty() ? "" : "->") + std::to_string(pNode->val));

    if (!pNode->left && !pNode->right)
    {
        paths.push_back(sCurPath);
    }

    if (pNode->left) binaryTreePaths(pNode->left, sCurPath, paths);
    if (pNode->right) binaryTreePaths(pNode->right, sCurPath, paths);
}

