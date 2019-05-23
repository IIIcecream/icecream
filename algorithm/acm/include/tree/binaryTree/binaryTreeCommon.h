#pragma once

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

// ��ȡ��ǰ������Ҷ�ӽڵ�
template<typename T>
T *getRightNode(T *pNode)
{
    if (!pNode) return nullptr;
    if (!pNode->left && !pNode->right) return pNode;
    if (pNode->right) return  getRightNode(pNode->right);
    return getRightNode(pNode->left);
}

// ��ȡ��ǰ������Ҷ�ӽڵ�
template<typename T>
T *getLeftNode(T *pNode)
{
    if (!pNode) return nullptr;
    if (!pNode->left && !pNode->right) return pNode;
    if (pNode->left) return  getRightNode(pNode->left);
    return getRightNode(pNode->right);
}
