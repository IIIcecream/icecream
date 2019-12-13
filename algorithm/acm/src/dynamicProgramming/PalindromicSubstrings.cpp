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
    // �ⷨ1 ��̬�滮
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

    // �ⷨ2 ���Ρ��Ƚⷨ1��Լ��ʱ�䣺��[i,j]���ǻ��Ĵ�ʱ���ⷨ1��Ƚ�[i-1,j+1]�����ⷨ2����
    int nRes2 = 0;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        nRes2 += expand(s, i, i);       // ��iΪ���� ������������չ�����Ĵ�����Ϊ������
        nRes2 += expand(s, i, i + 1);   // ��i��i+1Ϊ���� ������������չ�����Ĵ�����Ϊż����
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

