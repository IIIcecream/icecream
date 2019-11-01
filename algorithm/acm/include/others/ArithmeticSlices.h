#pragma once
#include "IACM.h"
#include <vector>
using std::vector;

// 等差数列划分
class ArithmeticSlices : public IACM
{
public:
    ArithmeticSlices(vector<int>& vec) : m_vec(vec) {}
    virtual bool solve() override;

private:
    int numberOfArithmeticSlices(vector<int>& A);

private:
    vector<int> m_vec;
};