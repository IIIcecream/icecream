#pragma once
#include "IACM.h"
#include "binaryTreeCommon.h"

class BinaryTreeDepth : public IACM
{
public:
    BinaryTreeDepth(TreeNode *pTree) : m_pTree(pTree) {}
    virtual bool solve() override { return !m_pTree; }

protected:
    TreeNode * m_pTree;
    int m_nDepth = 0;   //结果
};

/*!
*@brief        二叉树最大深度
*@author       tangw-b  2018/12/05  10:43
*/
class MaximumBinaryTreeDepth : public BinaryTreeDepth
{
public:
    MaximumBinaryTreeDepth(TreeNode *pTree) : BinaryTreeDepth(pTree) {}
    virtual bool solve() override;

private:
    int getTreeDepth(TreeNode *pNode);
};

/*!
*@brief        二叉树最小深度
*@author       tangw-b  2018/12/05  10:43
*/
class MinimumBinaryTreeDepth : public BinaryTreeDepth
{
public:
    MinimumBinaryTreeDepth(TreeNode *pTree) : BinaryTreeDepth(pTree) {}
    virtual bool solve() override;private:

private:
    int getTreeDepth(TreeNode *pNode);
};