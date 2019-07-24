#include "tree\BinaryTree\ConstructBinaryTree.h"


ConstructBinaryTree::~ConstructBinaryTree()
{
    if (m_pTree)
    {
        deleteTreeNode(m_pTree);
        m_pTree = nullptr;
    }
}

void ConstructBinaryTree::deleteTreeNode(TreeNode *pNode)
{
    if (pNode->left) deleteTreeNode(pNode->left);
    if (pNode->right) deleteTreeNode(pNode->right);
    delete pNode;
    pNode = nullptr;
}

// ��ǰ��������������й�������� LeetCode T105
bool CBTfromPreInorder::solve()
{
    TreeNode *pTree = constructTree(0, m_preorde.size() - 1, 0, m_inorder.size() - 1);
    return true;
}

TreeNode* CBTfromPreInorder::constructTree(int preBegin, int preEnd, int inBegin, int inEnd)
{
    if (preBegin > preEnd) return nullptr;

    TreeNode *pNode = new TreeNode(m_preorde[preBegin]);
    if (preBegin < preEnd)
    {
        int nCurIndex = findObjInOrderIndex(m_preorde[preBegin]);
        int nSum = nCurIndex - inBegin;
        pNode->left = constructTree(preBegin + 1, preBegin + nSum, inBegin, nCurIndex - 1);
        pNode->right = constructTree(preBegin + nSum + 1, preEnd, nCurIndex + 1, inEnd);
    }
    return pNode;
}

// �ҵ�ǰ���б���Ԫ���������е�����
int CBTfromPreInorder::findObjInOrderIndex(int n)
{
    for (size_t i = 0; i < m_inorder.size(); ++i)
    {
        if (m_inorder[i] == n) return i;
    }
    return -1;
}

// �����������������й�������� LeetCode T106
bool CBTfromInPostOrder::solve()
{
    TreeNode *pTree = constructTree(0, m_postOrder.size() - 1, 0, m_inOrder.size() - 1);
    return true;
}

TreeNode * CBTfromInPostOrder::constructTree(int postBegin, int postEnd, int inBegin, int inEnd)
{
    if (postBegin > postEnd) return nullptr;
    TreeNode *pNode = new TreeNode(m_postOrder[postEnd]);
    if (postBegin < postEnd)
    {
        int nCurIndex = findObjInOrderIndex(m_postOrder[postEnd]);
        int nSum = nCurIndex - inBegin;
        pNode->left = constructTree(postBegin, postBegin +nSum - 1, inBegin, nCurIndex - 1);
        pNode->right = constructTree(postBegin + nSum, postEnd - 1, nCurIndex + 1, inEnd);
    }
    return pNode;
}

int CBTfromInPostOrder::findObjInOrderIndex(int n)
{
    for (size_t i = 0; i < m_inOrder.size(); ++i)
    {
        if (m_inOrder[i] == n) return i;
    }
    return -1;
}

// ����������ת��Ϊ���������� LeetCode T108
bool CBTfromSortedArray::solve()
{
    return constructTree(0, m_nums.size() - 1);
    return true;
}

TreeNode * CBTfromSortedArray::constructTree(int nBegin, int nEnd)
{
    if (nBegin > nEnd) return nullptr;
    int nMid = (nBegin + nEnd) / 2;
    TreeNode *pRoot = new TreeNode(m_nums[nMid]);
    if (nBegin < nEnd)
    {
        pRoot->left = constructTree(nBegin, nMid - 1);
        pRoot->right = constructTree(nMid + 1, nEnd);
    }
    return pRoot;
}
