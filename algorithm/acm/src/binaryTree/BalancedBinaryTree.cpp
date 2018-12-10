#include "binaryTree\BalancedBinaryTree.h"
#include <vcruntime_exception.h>
#include "ACMMathCommon.h"

// Æ½ºâ¶þ²æÊ÷ LeetCode T110
bool BalancedBinaryTree::solve()
{
    isBalanced(m_pTree);
    return true;
}

bool BalancedBinaryTree::isBalanced(TreeNode* root)
{
    try
    {
        getHeight(root);
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}

int BalancedBinaryTree::getHeight(TreeNode* root)
{
    if (!root) return 0;
    int nLeft = getHeight(root->left);
    int nRight = getHeight(root->right);
    if (ACM::abs(nLeft - nRight) > 1) throw std::exception("err");
    return 1 + ACM::max(nLeft, nRight);
}

