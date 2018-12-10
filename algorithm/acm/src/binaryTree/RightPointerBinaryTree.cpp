#include "BinaryTree\RightPointerBinaryTree.h"
#include "binaryTree\binaryTreeCommon.h"

bool NextRightPointersBT::solve()
{
    connect(m_pTree);
    return true;
}

//  填充二叉树的同一层兄弟节点 LeetCode T116（完全二叉树）
void NextRightPointersBT::connect(TreeLinkNode *root)
{
    if (!root) return;
    TreeLinkNode *pCur = root;
    while (pCur)
    {
        if (pCur->left) pCur->left->next = pCur->right;
        if (pCur->right && pCur->next) pCur->right->next = pCur->next->left;
        pCur = pCur->next;
    }
    connect(root->left);
    
}

