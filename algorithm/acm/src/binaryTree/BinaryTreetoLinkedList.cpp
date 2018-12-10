#include "BinaryTree\BinaryTreetoLinkedList.h"
#include <utility>
using namespace std;

// ������չ��Ϊ���� ǰ����ʽ LeeCode T114
bool BinaryTreetoLinkedList::solve()
{
    flatten(m_pTree);
    return true;
}

// 1. ���ҿ� ����
// 2. ���ҷǿ� �ؼ�Ϊ�ҵ����������ҽڵ�
// 3. ��ǿ� �ҿ� ����swap
// 4. ��� �ҷǿ� ���ҵݹ�
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

// ��ȡ�����������ҽڵ�
TreeNode * BinaryTreetoLinkedList::getLeftTreeRightNode(TreeNode *pNode)
{
    if (!pNode) return nullptr;
    if (!pNode->left && !pNode->right) return pNode;
    if (pNode->right)pNode = pNode->right;
    else pNode = pNode->left;
    return getLeftTreeRightNode(pNode);
}

