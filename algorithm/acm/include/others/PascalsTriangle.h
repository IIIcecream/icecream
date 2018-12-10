#pragma once
#include "IACM.h"
#include <vector>

// Pascal's Triangle �������
class PascalsTriangle : public IACM
{
public:
    PascalsTriangle(int numRows) : m_numRows(numRows) {}
    virtual bool solve() override;

private:
    int m_numRows;
    std::vector<std::vector<int>> m_res;
};