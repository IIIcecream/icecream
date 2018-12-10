#pragma once

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

// 获取当前树最右叶子节点
template<typename T>
T *getRightNode(T *pNode)
{
    if (!pNode) return nullptr;
    if (!pNode->left && !pNode->right) return pNode;
    if (pNode->right) return  getRightNode(pNode->right);
    return getRightNode(pNode->left);
}

// 获取当前树最左叶子节点
template<typename T>
T *getLeftNode(T *pNode)
{
    if (!pNode) return nullptr;
    if (!pNode->left && !pNode->right) return pNode;
    if (pNode->left) return  getRightNode(pNode->left);
    return getRightNode(pNode->right);
}
