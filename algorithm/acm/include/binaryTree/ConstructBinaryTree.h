#pragma once
#include "IACM.h"
#include "binaryTreeCommon.h"
#include <vector>

/*!
*@brief        构造二叉树
*@author       tangw-b  2018/12/05  11:04
*/
class ConstructBinaryTree : public IACM
{
public:
    ConstructBinaryTree() {}
    virtual ~ConstructBinaryTree();
    virtual bool solve() override { return !m_pTree; }

private:
    void deleteTreeNode(TreeNode *pNode);
private:
    TreeNode * m_pTree = nullptr;
};

/*!
*@brief        Construct Binary Tree from Preorder and Inorder Traversal
               通过前序中序遍历，构造二叉树
*@author       tangw-b  2018/12/05  11:07
*/
class CBTfromPreInorder : public ConstructBinaryTree
{
public:
    CBTfromPreInorder(std::vector<int>& preorder, std::vector<int>& inorder) : m_preorde(preorder), m_inorder(inorder) {}
    virtual bool solve() override;

private:
    TreeNode* constructTree(int preBegin, int preEnd, int inBegin, int inEnd);
    int findObjInOrderIndex(int n);
private:
    std::vector<int> m_preorde;
    std::vector<int> m_inorder;
};


/*!
*@brief        Construct Binary Tree from Inorder and Postorder Traversal
               通过中序后序遍历，构造二叉树
*@author       tangw-b  2018/12/05  11:07
*/
class CBTfromInPostOrder : public ConstructBinaryTree
{
public:
    CBTfromInPostOrder(std::vector<int>& inorder, std::vector<int>& postOrder) : m_inOrder(inorder), m_postOrder(postOrder) {}
    virtual bool solve() override;

private:
    TreeNode * constructTree(int postBegin, int prostEnd, int inBegin, int inEnd);
    int findObjInOrderIndex(int n);
private:
    std::vector<int> m_inOrder;
    std::vector<int> m_postOrder;
};

/*!
*@brief        Convert Sorted Array to Binary Search Tree
               将有序数组转换为二叉搜索树
*@author       tangw-b  2018/12/05  17:24
*/
class CBTfromSortedArray : public ConstructBinaryTree
{
public:
    CBTfromSortedArray(std::vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    TreeNode * constructTree(int nBegin, int nEnd);

private:
    std::vector<int> m_nums;
};


