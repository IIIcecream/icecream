#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// ×î´ó¾ØÐÎ
class MaximalRectangle : public IACM
{
public:
    MaximalRectangle(vector<vector<char>>& matrix) : m_matrix(matrix) {}
    virtual bool solve() override;

private:
    int maximalRectangle(vector<vector<char>>& matrix);

private:
    vector<vector<char>> m_matrix;
};