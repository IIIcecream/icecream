#pragma once
#include "binaryTreeCommon.h"
#include "IACM.h"
#include <vector>
#include <stack>

/*!
*@brief        二叉树遍历
*@author       tangw-b  2018/12/04  14:05
*/

class BinaryTreeTraversal : public IACM
{
public:
    BinaryTreeTraversal(TreeNode *pTree) { m_pTree = pTree; }
    virtual bool solve() override { return true; }
protected:
    TreeNode * m_pTree;
    std::vector<int> m_res;   //遍历结果
};

/*!
*@brief        前序遍历
*@author       tangw-b  2018/12/04  14:00
*/
class PreOrderTraversal : public BinaryTreeTraversal
{
public:
    PreOrderTraversal(TreeNode *p) : BinaryTreeTraversal(p) {}
    virtual bool solve() override;
private:
    void preOrder(TreeNode *pNode);
};

/*!
*@brief        中序遍历
*@author       tangw-b  2018/12/04  14:07
*/
class InOrderTraversal : public BinaryTreeTraversal
{
public:
    InOrderTraversal(TreeNode *p) : BinaryTreeTraversal(p) {}
    virtual bool solve() override;
private:
    void inOrder(TreeNode *pNode);
};

/*!
*@brief        后序遍历
*@author       tangw-b  2018/12/04  14:10
*/
class PostOrderTraversal : public BinaryTreeTraversal
{
public:
    PostOrderTraversal(TreeNode *p) : BinaryTreeTraversal(p) {}
    virtual bool solve() override;
private:
    void postOrder(TreeNode *pNode);
};

/*!
*@brief        层次遍历
*@author       tangw-b  2018/12/05  10:34
*/
class LevelOrderTraversal : public BinaryTreeTraversal
{
public:
    LevelOrderTraversal(TreeNode *p) : BinaryTreeTraversal(p) {}
    virtual bool solve() override;
private:
    void levelOrder(TreeNode *pNode);

    struct MyNode//当前节点的深度
    {
    public:
        MyNode(TreeNode *p, int n) { node = p, nLevel = n; }
        int nLevel;
        TreeNode *node;
    };
private:
    std::vector<std::vector<int>> res;        //层次遍历结果
};

/*!
*@brief        锯齿形遍历
*@author       tangw-b  2018/12/04  14:15
*/
//              5
//            /   \
//           6     3  ==> 5 3 6 2 8  第一层 从左到右，第二层从右到左，第三层从左到右。。。
//          /     /  
//         2     8
class ZigZagLevelOrderTraversal : public BinaryTreeTraversal
{
public:
    ZigZagLevelOrderTraversal(TreeNode *p) : BinaryTreeTraversal(p) {}
    virtual bool solve() override  { return false; }

private:
    void zigZagLevelOrder();

private:
    std::vector<std::vector<int>> res;        //层次遍历结果
    std::stack<TreeNode*> m_Nodes;
    bool m_bOrder = true;  // 标记当前层遍历是从左至右还是从右至左
};

/*!
*@brief        深度优先遍历
*@author       tangw-b  2018/12/06  19:15
*/
class DepthFirstTraversal : public BinaryTreeTraversal
{
public:
    DepthFirstTraversal(TreeNode *p, int sum) : BinaryTreeTraversal(p), m_nSum(sum) {}
    virtual bool solve() override;

private:
    bool hasPathSum(TreeNode *pNode, int sum);
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum);
    void getSumPath(TreeNode *root, int sum, std::vector<int> &curPath);

private:
    int m_nSum;
    std::vector<std::vector<int>> m_res;
};

