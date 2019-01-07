#pragma once
#include "IACM.h"

// 不同的二叉搜索树
class UniqueBinarySearchTrees : public IACM
{
public:
    UniqueBinarySearchTrees(int n) : m_n(n) {}
    virtual bool solve() override;

private:
    int numTrees(int n);

private:
    int m_n;
};