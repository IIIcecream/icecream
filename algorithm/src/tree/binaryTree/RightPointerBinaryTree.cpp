#include "tree\BinaryTree\RightPointerBinaryTree.h"
#include "tree\binaryTree\binaryTreeCommon.h"

bool NextRightPointersBT::solve()
{
    connect1(m_pTree);
    return true;
}

//  ����������ͬһ���ֵܽڵ� LeetCode T116����ȫ��������
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

// ���ͬһ����ֵܽڵ� II LeetCode T117������ȫ��������
void NextRightPointersBT::connect2(TreeLinkNode *root)
{
    if (!root) return;
    if (!root->left && !root->right) connect2(root->next);
    TreeLinkNode *pCur = root;
    while (pCur)
    {
        // �������ӽڵ㶼��Ϊ��
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

        // �ҽڵ�ָ��next
        if (pCur->right)
        {
            pCur->right->next = pCurNext;
        }
        // �ҽڵ�Ϊ�գ���ڵ�ָ��next
        else if(pCur->left)
        {
            pCur->left->next = pCurNext;
        }
        // ���Ҷ�Ϊ��
        pCur = pCur->next;
    }
    connect2(root->left ? root->left : root->right);
}

