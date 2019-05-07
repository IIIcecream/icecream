#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// 最大正方形
class MaximalSquare : public IACM
{
public:
    MaximalSquare(vector<vector<char>>& matrix) : m_matrix(matrix) {}
    virtual bool solve() override;

private:
    int maximalSquare(vector<vector<char>>& matrix);

private:
    vector<vector<char>> m_matrix;
};