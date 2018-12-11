#pragma once
#include "IACM.h"
#include <vector>

// Pascal's Triangle Ñî»ÔÈý½Ç
class PascalsTriangle : public IACM
{
public:
    PascalsTriangle(int numRows) : m_numRows(numRows) {}
    virtual bool solve() override;

private:
    void pascalsTriangle1();
    void pascalsTriangle2();
private:
    int m_numRows;
    std::vector<std::vector<int>> m_res1;
    std::vector<int> m_res2;
};