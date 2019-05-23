#include "tree\binaryTree\BinaryTreeMaximumPathSum.h"
#include "ACMMathCommon.h"
#include <string>

using namespace ACM;
using namespace std;
bool BTMaxPathSum::solve()
{
    if (!m_pTree) return false;
    maxPathSum(m_pTree);
    return true;
}

// Binary Tree Maximum Path Sum LeetCodeT124
int BTMaxPathSum::maxPathSum(TreeNode* root)
{
    if (!root) return 0;
    int nLeft = maxPathSum(root->left);
    int nRight = maxPathSum(root->right);
    m_nRes = max(m_nRes, max(0, nLeft) + max(0, nRight) + root->val);
    // ���ܷ���root.val + left + right ��Ϊ���һ���ڵ�ֻ����һ��
    return root->val + max(max(0, nLeft), nRight);
}

