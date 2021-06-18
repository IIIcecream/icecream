#include "others/SpiralMatrix.h"

bool SpiralMatrix::solve()
{
    spiralOrder(m_matrix);
    return true;
}

// SpiralMatrix LeetCode T54
vector<int> SpiralMatrix::spiralOrder(vector<vector<int>>& matrix)
{
    int nMin = -2147483600;
    vector<int> result;
    int i = 0, j = 0, m = matrix.size(), n = 0;
    if (m > 0) n = matrix[0].size();
    if (n <= 0) return result;

    while (1)
    {
        int nFlag = 0;
        if (!check(i, j, m, n)) break;
        while (j < n && matrix[i][j] != nMin) result.push_back(matrix[i][j]), matrix[i][j++] = nMin, nFlag = 1;
        if (nFlag == 1) --j, ++i;
        if (!check(i, j, m, n)) break;
        while (i < m && matrix[i][j] != nMin) result.push_back(matrix[i][j]), matrix[i++][j] = nMin, nFlag = 2;
        if (nFlag == 2) --i, --j;
        if (!check(i, j, m, n)) break;
        while (j >= 0 && matrix[i][j] != nMin) result.push_back(matrix[i][j]), matrix[i][j--] = nMin, nFlag = 3;
        if (nFlag == 3) ++j, --i;
        if (!check(i, j, m, n)) break;
        while (i >= 0 && matrix[i][j] != nMin) result.push_back(matrix[i][j]), matrix[i--][j] = nMin, nFlag = 4;
        if (nFlag == 4) ++i, ++j;
        if (!nFlag) break;
    }
    return result;
}

bool SpiralMatrix::check(int i, int j, int m, int n)
{
    return 0 <= i && i < m && 0 <= j && j < n;
}


bool SpiralMatrixII::solve()
{
    generateMatrix(m_n);
    return true;
}

// SpiralMatrixII LeeteCode T59
vector<vector<int>> SpiralMatrixII::generateMatrix(int n)
{
    vector<vector<int>> res(n, vector<int>(n, 0));
    generate(res, 0, 0, 0, 1);
    return res;
}

void SpiralMatrixII::generate(vector<vector<int>> &res, int i, int j, int flag, int num)
{
    if (i >= (int)res.size() || j >= (int)res.size() || res[i][j]) return;
    switch (flag)
    {
    case 0://Õ˘”“
    {
        for (int k = 0; k < (int)res.size(); ++k)
        {
            if (res[i][k]) continue;
            j = k;
            res[i][k] = num++;
        }
        ++i;
        break;
    }
    case 1://Õ˘œ¬
    {
        for (int k = 0; k < (int)res.size(); ++k)
        {
            if (res[k][j]) continue;
            i = k;
            res[k][j] = num++;
        }
        --j;
        break;
    }
    case 2://Õ˘◊Û
    {
        for (int k = (int)res.size() - 1; k >= 0; --k)
        {
            if (res[i][k]) continue;
            j = k;
            res[i][k] = num++;
        }
        --i;
        break;
    }
    default://Õ˘…œ
    {
        for (int k = (int)res.size() - 1; k >= 0; --k)
        {
            if (res[k][j]) continue;
            i = k;
            res[k][j] = num++;
        }
        ++j;
    }
    }
    generate(res, i, j, (++flag) % 4, num);
}
