#include "dynamicProgramming/TilingRectWithRewestSquares.h"
#include "ACMMathCommon.h"

bool TilingRectWithRewestSquares::solve()
{
    return tilingRectangle(m_n, m_m);
}

// LeetCode 5241. ÆÌ´É×©
int TilingRectWithRewestSquares::tilingRectangle(int n, int m)
{
    // https://leetcode-cn.com/problems/tiling-a-rectangle-with-the-fewest-squares/solution/5241-pu-ci-zhuan-dong-tai-gui-hua-by-xu-yuan-shu/
    int f[14][14];
    memset(f, 1, sizeof(f));
    for (int i = 0; i <= n; i++)f[i][0] = 0;
    for (int i = 0; i <= m; i++)f[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= ACM::min(i, j); k++)
            {
                int i2 = i - k;
                int j1 = j - k;
                for (int i1 = 0; i1 <= i2; i1++)
                {
                    for (int j2 = j1; j2 <= j; j2++)
                    {
                        f[i][j] = ACM::min(f[i][j], f[i1][j2] + f[i2][j - j2] + f[i - i1][j1] + f[i2 - i1][j2 - j1] + 1);
                    }
                }

            }
        }
    }

    return f[n][m];
}

