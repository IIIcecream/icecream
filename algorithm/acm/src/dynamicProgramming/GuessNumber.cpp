#include "dynamicProgramming/GuessNumber.h"
#include <vector>
#include "ACMMathCommon.h"
using std::vector;

bool GuessNumberII::solve()
{
    return getMoneyAmount(m_n);
}

// LeetCode 375. Guess Number Higher or Lower II
// dp[i][j]代表下标从i到j的闭区间，需要的花费
int GuessNumberII::getMoneyAmount(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; ++i) dp[i][i + 1] = i;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int nTemp = dp[i][j];
            for (int k = i; k <= j; ++k)
            {
                nTemp = ACM::max(dp[i][k], dp[k][j]);
            }
            dp[i][j] = ACM::min(dp[i][j], nTemp);
        }
    }

    return dp[0][n];
}

