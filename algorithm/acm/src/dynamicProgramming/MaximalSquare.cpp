#include "dynamicProgramming\MaximalSquare.h"
#include "ACMMathCommon.h"

bool MaximalSquare::solve()
{
    return maximalSquare(m_matrix);
}

// LeetCode 221 Maximal Square
int MaximalSquare::maximalSquare(vector<vector<char>>& matrix)
{
    int nRes = 0;

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] == 0) continue;
            if (i == 0 || j == 0) nRes = ACM::max(nRes, matrix[i][j] - '0');
            else
            {
                int n1 = matrix[i - 1][j - 1] - '0', n2 = matrix[i][j - 1] - '0', n3 = matrix[i - 1][j] - '0', n4 = matrix[i][j] - '0';
                if (n1 && n2 && n3 && n4)
                {

                    matrix[i][j] = '1' + ACM::min(n1, ACM::min(n2, n3));
                    nRes = ACM::max(nRes, matrix[i][j] - '0');
                }
            }
        }
    }

    return nRes * nRes;
}

