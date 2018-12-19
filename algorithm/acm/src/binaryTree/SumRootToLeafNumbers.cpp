#include "binaryTree\SumRootToLeafNumbers.h"

bool SumRootToLeafNumbers::solve()
{
    if (!m_pRoot) return 0;
    sumNumbers(m_pRoot, m_pRoot->val);
    return true;
}

// 求根到叶子节点数字之和 LeetCode T129
void SumRootToLeafNumbers::sumNumbers(TreeNode* root, int sum)
{
    if (!root) return;
    if (!root->left && !root->right)
    {
        m_nRes += sum;
        return;
    }

    if (root->left)
    {
        sumNumbers(root->left, sum * 10 + root->val);
    }
    if (root->right)
    {
        sumNumbers(root->right, sum * 10 + root->val);
    }
}

