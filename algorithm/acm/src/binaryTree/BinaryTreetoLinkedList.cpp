#include "BinaryTree\BinaryTreetoLinkedList.h"
#include <utility>
using namespace std;

// 二叉树展开为链表， 前序形式 LeeCode T114
bool BinaryTreetoLinkedList::solve()
{
    flatten(m_pTree);
    return true;
}

// 1. 左右空 返回
// 2. 左右非空 关键为找到左子树最右节点
// 3. 左非空 右空 左右swap
// 4. 左空 右非空 往右递归
void BinaryTreetoLinkedList::flatten(TreeNode* pNode)
{
    if (!pNode || !pNode->left && !pNode->right) return;    // 1
    else if (pNode->left && pNode->right)                   // 2
    {
        TreeNode *pLeftRight = getLeftTreeRightNode(pNode->left);
        TreeNode *pRight = pNode->right;
        pNode->right = pNode->left;
        pNode->left = nullptr;
        pLeftRight->right = pRight;
        flatten(pNode->right);
    }
    else
    {
        if (pNode->left) swap(pNode->left, pNode->right);   // 3
        flatten(pNode->right);                              // 4
    }
}

// 获取左子树的最右节点
TreeNode * BinaryTreetoLinkedList::getLeftTreeRightNode(TreeNode *pNode)
{
    if (!pNode) return nullptr;
    if (!pNode->left && !pNode->right) return pNode;
    if (pNode->right)pNode = pNode->right;
    else pNode = pNode->left;
    return getLeftTreeRightNode(pNode);
}

