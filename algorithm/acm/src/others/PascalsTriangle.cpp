#include "others\PascalsTriangle.h"

using namespace std;

// Pascal's Triangle LeetCode T118
bool PascalsTriangle::solve()
{
    if (m_numRows <= 0) return false;

    for (int i = 0; i < m_numRows; ++i)
    {
        vector<int> row;
        for (int j = 0; j < i + 1; ++j)
            if (j == 0 || j == i) row.push_back(1);
            else row.push_back(m_res[i - 1][j - 1] + m_res[i - 1][j]);
       
         m_res.push_back(row);
    }

    return true;
}

