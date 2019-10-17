#include "recursion/bfs/FindBottomLeftTreeValue.h"
#include <queue>
#include "tree/binaryTree/binaryTreeCommon.h"
using std::queue;

bool FindBottomLeftTreeValue::solve()
{
    return findBottomLeftValue(m_pRoot);
}

// LeetCode 513. Find Bottom Left Tree Value
int FindBottomLeftTreeValue::findBottomLeftValue(TreeNode* root)
{
    if (!root) return -1;

    queue<TreeNode*> bfsQueue;
    bfsQueue.push(root);

    TreeNode *pResNode = nullptr;
    while (1)
    {
        queue<TreeNode*> nextLevel;

        pResNode = bfsQueue.front();
        while (!bfsQueue.empty())
        {
            TreeNode* pNode = bfsQueue.front();
            bfsQueue.pop();

            if (pNode->left) nextLevel.push(pNode->left);
            if (pNode->right) nextLevel.push(pNode->right);
        }

        if (nextLevel.empty()) return pResNode->val;
        bfsQueue = nextLevel;
    }
    return 0;
}

