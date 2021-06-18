#include "tree\BinaryTree\RightPointerBinaryTree.h"
#include "tree\binaryTree\binaryTreeCommon.h"

bool NextRightPointersBT::solve()
{
    connect1(m_pTree);
    return true;
}

//  填充二叉树的同一层兄弟节点 LeetCode T116（完全二叉树）
void NextRightPointersBT::connect1(TreeLinkNode *root)
{
    if (!root) return;
    TreeLinkNode *pCur = root;
    while (pCur)
    {
        if (pCur->left) pCur->left->next = pCur->right;
        if (pCur->right && pCur->next) pCur->right->next = pCur->next->left;
        pCur = pCur->next;
    }
    connect1(root->left);
}

// 填充同一层的兄弟节点 II LeetCode T117（非完全二叉树）
void NextRightPointersBT::connect2(TreeLinkNode *root)
{
    if (!root) return;
    if (!root->left && !root->right) connect2(root->next);
    TreeLinkNode *pCur = root;
    while (pCur)
    {
        // 当左右子节点都不为空
        if (pCur->left && pCur->right)
        {
            pCur->left->next = pCur->right;
        }

        TreeLinkNode *pCurNext = pCur->next;
        while (pCurNext)
        {
            if (pCurNext->left) { pCurNext = pCurNext->left; break; }
            if (pCurNext->right) { pCurNext = pCurNext->right; break; }
            pCurNext = pCurNext->next;
        }

        // 右节点指向next
        if (pCur->right)
        {
            pCur->right->next = pCurNext;
        }
        // 右节点为空，左节点指向next
        else if(pCur->left)
        {
            pCur->left->next = pCurNext;
        }
        // 左右都为空
        pCur = pCur->next;
    }
    connect2(root->left ? root->left : root->right);
}

