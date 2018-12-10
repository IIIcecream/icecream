#pragma once
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
    virtual bool solve() override;

private:
    void connect(TreeLinkNode *root);
};