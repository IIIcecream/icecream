#include "others\PascalsTriangle.h"

using namespace std;

bool PascalsTriangle::solve()
{
    if (m_numRows <= 0) return false;

    pascalsTriangle1();
    pascalsTriangle2();

    return true;
}

// Pascal's Triangle LeetCode T118
void PascalsTriangle::pascalsTriangle1()
{
    for (int i = 0; i < m_numRows; ++i)
    {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; ++j)
            row[j] = m_res1[i - 1][j - 1] + m_res1[i - 1][j];

        m_res1.push_back(row);
    }
}

// // Pascal's Triangle2 LeetCode T119 要求空间复杂度为O(n)
void PascalsTriangle::pascalsTriangle2()
{
    m_res2.resize(m_numRows + 1, 0);

    for (int i = 0; i <= m_numRows; ++i)
    {
        m_res2[i] = 1;
        for (int j = i - 1; j >= 0; --j)
            m_res2[j] += m_res2[j - 1];
    }
}

