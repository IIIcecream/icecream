#pragma once
#include "binaryTreeCommon.h"
#include "IACM.h"
#include <vector>
#include <stack>

/*!
*@brief        ����������
*@author       tangw-b  2018/12/04  14:05
*/

class BinaryTreeTraversal : public IACM
{
public:
    BinaryTreeTraversal(TreeNode *pTree) { m_pTree = pTree; }
    virtual bool solve() override { return true; }
protected:
    TreeNode * m_pTree;
    std::vector<int> m_res;   //�������
};

/*!
*@brief        ǰ�����
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
*@brief        �������
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
*@brief        �������
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
*@brief        ��α���
*@author       tangw-b  2018/12/05  10:34
*/
class LevelOrderTraversal : public BinaryTreeTraversal
{
public:
    LevelOrderTraversal(TreeNode *p) : BinaryTreeTraversal(p) {}
    virtual bool solve() override;
private:
    void levelOrder(TreeNode *pNode);

    struct MyNode//��ǰ�ڵ�����
    {
    public:
        MyNode(TreeNode *p, int n) { node = p, nLevel = n; }
        int nLevel;
        TreeNode *node;
    };
private:
    std::vector<std::vector<int>> res;        //��α������
};

/*!
*@brief        ����α���
*@author       tangw-b  2018/12/04  14:15
*/
//              5
//            /   \
//           6     3  ==> 5 3 6 2 8  ��һ�� �����ң��ڶ�����ҵ��󣬵���������ҡ�����
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
    std::vector<std::vector<int>> res;        //��α������
    std::stack<TreeNode*> m_Nodes;
    bool m_bOrder = true;  // ��ǵ�ǰ������Ǵ������һ��Ǵ�������
};

/*!
*@brief        ������ȱ���
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

