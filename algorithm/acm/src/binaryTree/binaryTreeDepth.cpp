#include "binaryTree\binaryTreeDepth.h"

#include "ACMMathCommon.h"
using namespace ACM;

// ������������ LeetCode T104
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

// ��������С��� LeetCode T111(��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�����)
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
