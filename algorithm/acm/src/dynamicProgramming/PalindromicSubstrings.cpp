#include "dynamicProgramming/PalindromicSubstrings.h"
#include <vector>
using std::vector;

bool PalindromicSubstrings::solve()
{
    return countSubstrings(m_s);
}

// LeetCode 647. Palindromic Substrings
int PalindromicSubstrings::countSubstrings(string s)
{
    // 解法1 动态规划
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

    int nRes = 0;
    for (int k = 0; k < (int)s.size(); ++k)
    {
        for (int i = 0; i < (int)s.size() - k; ++i)
        {
            int j = i + k;
            if (i == j) dp[i][j] = true;
            else if (s[i] == s[j])
            {
                if (i == j - 1) dp[i][j] = true;
                else dp[i][j] = dp[i + 1][j - 1];
            }

            if (dp[i][j]) nRes++;
        }
    }

    return nRes;

    // 解法2 分治。比解法1节约的时间：当[i,j]不是回文串时，解法1会比较[i-1,j+1]，但解法2不会
    int nRes2 = 0;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        nRes2 += expand(s, i, i);       // 以i为中心 往左右两边扩展（回文串长度为奇数）
        nRes2 += expand(s, i, i + 1);   // 以i和i+1为中心 往左右两边扩展（回文串长度为偶数）
    }
    return nRes2;
}

int PalindromicSubstrings::expand(string& s, int i, int j)
{
    int nRes = (i == j && s[i--] == s[j++]) ? 1 : 0;
    while (i >= 0 && j < (int)s.size() && s[i--] == s[j++])
    {
        nRes += 1;
    }
    return nRes;
}

