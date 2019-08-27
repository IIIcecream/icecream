#include "recursion/DecodeWays.h"
#include <vector>
using std::vector;

bool DecodeWays::solve()
{
    return numDecodings(m_s);
}

// LeetCode 91. Decode Ways
int DecodeWays::numDecodings(string s)
{
    vector<int> res;
    res.resize(s.size(), 0);

    auto getVal = [&](int n)->int
    {
        if (n < 0) return 0;
        return res[n];
    };

    if (s.size() > 0) res[0] = s[0] != '0';

    for (size_t i = 1; i < s.size(); ++i)
    {
        if (canDecodeing(s, i, 1))
        {
            if (canDecodeing(s, i - 1, 2)) res[i] = res[i - 1] + (i >= 2 ? res[i - 2] : 1);
            else res[i] = res[i - 1];
        }
        else if (canDecodeing(s, i - 1, 2))
        {
            res[i] = i >= 2 ? res[i - 2] : 1;
        }
        else
            res[i] = 0;
    }

    return res.back();
    //return numDecodings1(s, 0);
}

// 解法1：递归，但是会超时，存在大量重复的计算
int DecodeWays::numDecodings1(string &s, int nIndex)
{
    int nRes = 0;

    if (nIndex == s.size()) return nRes + 1;
    if (nIndex + 1 <= s.size() && canDecodeing(s, nIndex, 1))
    {
        nRes += numDecodings1(s, nIndex + 1);
    }

    if (nIndex + 2 <= s.size() && canDecodeing(s, nIndex, 2))
    {
        nRes += numDecodings1(s, nIndex + 2);
    }

    return nRes;
}

bool DecodeWays::canDecodeing(string &s, int nIndex, int n)
{
    if (n == 1 || s[nIndex] == '1') return true;

    if (s[nIndex] == '2' && s[nIndex + 1] < '7') return true;
    return false;
}
