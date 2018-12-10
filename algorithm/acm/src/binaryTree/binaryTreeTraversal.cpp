#include "binaryTree\binaryTreeTraversal.h"
#include <queue>
using namespace std;

// 二叉树前序遍历
bool PreOrderTraversal::solve()
{
    if (!m_pTree) return false;
    preOrder(m_pTree);
    return true;
}

void PreOrderTraversal::preOrder(TreeNode *pNode)
{
    if (!pNode) return;
    m_res.push_back(pNode->val);
    preOrder(pNode->left);
    preOrder(pNode->right);
}

// 中序遍历
bool InOrderTraversal::solve()
{
    if (!m_pTree) return false;
    inOrder(m_pTree);
    return true;
}

void InOrderTraversal::inOrder(TreeNode *pNode)
{
    if (!pNode) return;
    inOrder(pNode->left);
    m_res.push_back(pNode->val);
    inOrder(pNode->right);
}

// 后序遍历
bool PostOrderTraversal::solve()
{
    if (!m_pTree) return false;
    postOrder(m_pTree);
    return true;
}

void PostOrderTraversal::postOrder(TreeNode *pNode)
{
    if (!pNode) return;
    postOrder(pNode->left);
    postOrder(pNode->right);
    m_res.push_back(pNode->val);
}

// 层次遍历 LeetCode T102
bool LevelOrderTraversal::solve()
{
    levelOrder(m_pTree);
    return !res.empty();
}

void LevelOrderTraversal::levelOrder(TreeNode *pNode)
{
    MyNode myNode(pNode, 0);
    queue<MyNode> myQueue;
    myQueue.push(myNode);

    while (!myQueue.empty())
    {
        auto itr = myQueue.front();
        myQueue.pop();
        if (itr.node == nullptr) continue;
        if (itr.nLevel >= (int)res.size())
            res.push_back({ itr.node->val });
        else
            res[itr.nLevel].push_back(itr.node->val);

        if (itr.node->left)
        {
            MyNode myNode(itr.node->left, itr.nLevel + 1);
            myQueue.push(myNode);
        }
        if (itr.node->right)
        {
            MyNode myNode(itr.node->right, itr.nLevel + 1);
            myQueue.push(myNode);
        }
    }
}

// 锯齿形层次遍历 LeetCode T103
bool ZigZagLevelOrderTraversal::solve()
{
    if (!m_pTree) return false;
    m_Nodes.push(m_pTree);
    zigZagLevelOrder();

    return true;
}

void ZigZagLevelOrderTraversal::zigZagLevelOrder()
{
    if (m_Nodes.empty()) return;
    stack<TreeNode*> tempNodes;
    vector<int> tempRes;

    while (!m_Nodes.empty())
    {
        auto itr = m_Nodes.top();
        m_Nodes.pop();
        if (itr == nullptr) continue;
        tempRes.push_back(itr->val);

        tempNodes.push(m_bOrder ? itr->left : itr->right);
        tempNodes.push(m_bOrder ? itr->right : itr->left);
    }
    
    m_bOrder = !m_bOrder;
    if (!tempRes.empty()) res.push_back(tempRes);
    m_Nodes.swap(tempNodes);
    zigZagLevelOrder();
}


bool DepthFirstTraversal::solve()
{
    hasPathSum(m_pTree, m_nSum);
    pathSum(m_pTree, m_nSum);
    return true;
}

// 深度优先遍历 LeetCode T112
bool DepthFirstTraversal::hasPathSum(TreeNode *pNode, int sum)
{
    if (!pNode) return false;
    sum -= pNode->val;
    if (0 == sum && !pNode->left && !pNode->right) return true;
    return hasPathSum(pNode->left, sum) || hasPathSum(pNode->right, sum);
}

// 深度优先遍历 LeetCode T113
vector<vector<int>> DepthFirstTraversal::pathSum(TreeNode* root, int sum)
{
    vector<int> curPath;
    getSumPath(root, sum, curPath);
    return m_res;
}

void DepthFirstTraversal::getSumPath(TreeNode *root, int sum, std::vector<int> &curPath)
{
    if (!root) return;
    sum -= root->val;
    curPath.push_back(root->val);
    if (0 == sum && !root->left && !root->right) m_res.push_back(curPath);
    getSumPath(root->left, sum, curPath);
    getSumPath(root->right, sum, curPath);
    curPath.pop_back();
}
