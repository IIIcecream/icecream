#include "string/DistinctSubsequnces.h"
using namespace std;

// LeetCode T115
// 看到有关字符串的子序列或者配准类的问题，首先应该考虑的就是用动态规划Dynamic Programming来求解，然后找出递推公式
bool DistinctSubsequnces::solve()
{
    // 解法1 二维数据
    int dp[100][100];// 不知道为什么vs二维数据不能初始化成int dp[m_nTLen + 1][m_nSLen + 1];
    for (int i = 0; i < m_nTLen; ++i) dp[i][0] = 0;
    for (int i = 0; i < m_nSLen; ++i) dp[0][i] = 1;

    for (int i = 1; i <= m_nTLen; ++i)
        for (int j = 1; j <= m_nSLen; ++j)
            dp[i][j] = dp[i][j - 1] + m_sS[j - 1] == m_sT[i - 1] ? dp[i - 1][j - 1] : 0;

    // 解法2 一维数组 
    int dppppp[100]; //int dp[m_nTLen + 1];
    memset(dppppp, 0, sizeof(dppppp));
    dppppp[0] = 1;
    for (int i = 0; i < m_nSLen; ++i)
        for (int j = m_nTLen - 1; j >= 0; --j)
            if (m_sS[i] == m_sT[j]) dppppp[j + 1] += dppppp[j];

    return true;
}
