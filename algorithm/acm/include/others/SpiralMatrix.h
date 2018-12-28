#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// ÂÝÐý¾ØÕó
class SpiralMatrix : public IACM
{
public:
    SpiralMatrix(vector<vector<int>>& matrix) : m_matrix(matrix) {}
    virtual bool solve() override;

private:
    vector<int> spiralOrder(vector<vector<int>>& matrix);
    bool check(int i, int j, int m, int n);

private:
    vector<vector<int>> m_matrix;
};

// ÂÝÐý¾ØÕóII
class SpiralMatrixII : public IACM
{
public:
    SpiralMatrixII(int n) : m_n(n) {}
    virtual bool solve() override;

private:
    vector<vector<int>> generateMatrix(int n);
    void generate(vector<vector<int>> &res, int i, int j, int flag, int num);

private:
    int m_n;
};