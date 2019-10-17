#include "dynamicProgramming/LongestPalindromicSubsequence.h"

#include <vector>
#include "ACMMathCommon.h"
using std::vector;

bool LongestPalindromicSubsequence::solve()
{
    return longestPalindromeSubseq(m_sStr);
}

// LeetCode 516. Longest Palindromic Subsequence
int LongestPalindromicSubsequence::longestPalindromeSubseq(string s)
{
    int nSize = s.size();
    vector<vector<int>> dp(nSize,vector<int>(nSize, 0));

    for (int i = nSize - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < nSize; j++)
            dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] + 2 : ACM::max(dp[i + 1][j], dp[i][j - 1]);
    }
    return dp[0][nSize - 1];
}

