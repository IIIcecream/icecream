#pragma once
#include <vector>
#include "IACM.h"

struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

// Populating Next Right Pointers in Each Node
class NextRightPointersBT : public IACM
{
public:
    NextRightPointersBT(TreeLinkNode *pTree) : m_pTree(pTree) {}
    virtual bool solve() override;

private:
    void connect(TreeLinkNode *root);

private:
    TreeLinkNode * m_pTree;
    std::vector<TreeLinkNode*> m_vecNodes;
};