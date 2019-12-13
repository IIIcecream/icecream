#include "tree/binaryTree/RightSideView.h"
#include <queue>
#include "tree/binaryTree/binaryTreeCommon.h"
using std::queue;

bool RightSideView::solve()
{
    return rightSideView(m_pRoot).size();
}

// LeetCode 199. Binary Tree Right Side View
vector<int> RightSideView::rightSideView(TreeNode* root)
{
    vector<int> res;
    if (!root) return res;

    queue<TreeNode*> myQueue, tempQueue;
    myQueue.push(root);

    while (!myQueue.empty())
    {
        res.push_back(myQueue.front()->val);
        while (!myQueue.empty())
        {
            TreeNode* pNode = myQueue.front();
            if (pNode->right) tempQueue.push(pNode->right);
            if(pNode->left) tempQueue.push(pNode->left);
            myQueue.pop();
        }

        swap(tempQueue, myQueue);
    }

    return res;
}

