#include "binaryTree\binaryTreeDepth.h"

#include "ACMMathCommon.h"
using namespace ACM;

// 二叉树最大深度 LeetCode T104
bool MaximumBinaryTreeDepth::solve()
{
    if (!m_pTree) return false;
    m_nDepth = getTreeDepth(m_pTree);
    return true;
}

int MaximumBinaryTreeDepth::getTreeDepth(TreeNode *pNode)
{
    if (!pNode)return 0;
    return 1 + max(getTreeDepth(pNode->left), getTreeDepth(pNode->right));
}

// 二叉树最小深度 LeetCode T111(最小深度是从根节点到最近叶子节点的最短路径上的节点数量)
bool MinimumBinaryTreeDepth::solve()
{
    if (!m_pTree) return false;
    m_nDepth = getTreeDepth(m_pTree);
    return true;
}

int MinimumBinaryTreeDepth::getTreeDepth(TreeNode *pNode)
{
    if (!pNode)return 0;
    if (!pNode->left) return 1 + getTreeDepth(pNode->right);
    if (!pNode->right) return 1 + getTreeDepth(pNode->left);
    return 1 + min(getTreeDepth(pNode->left), getTreeDepth(pNode->right));
}
