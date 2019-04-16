#include "slidingWindow\MinimumWindowSubstring.h"

bool MinimumWindowSubstring::solve()
{
    minWindow(m_s, m_t);
    return true;
}

// LeetCode 76 Minimum Window Substring
string MinimumWindowSubstring::minWindow(string s, string t)
{
    map<char, int> mapT, mapTemp;
    for (char c : t)
    {
        if (mapT.find(c) == mapT.end())
            mapT[c] = 0;

        mapT[c]++;
    }
    mapTemp = mapT;

    int nLeft = 0, nResLen = s.length(), nLenT = t.length();
    string sRes;
    for (size_t nRight = 0; nRight < s.length(); ++nRight)
    {
        if (mapT.find(s[nRight]) != mapT.end())
        {
            if (--mapT[s[nRight]] == 0) nLenT -= mapTemp[s[nRight]];
            if (!nLenT)
            {
                while (mapT.find(s[nLeft]) == mapT.end() || mapT[s[nLeft]] < 0)
                {
                    if (mapT.find(s[nLeft]) != mapT.end() && mapT[s[nLeft]] < 0) mapT[s[nLeft]]++;
                    nLeft++;
                }
                if (nResLen >= nRight - nLeft + 1)
                {
                    nResLen = nRight - nLeft + 1;
                    sRes = s.substr(nLeft, nResLen);
                }
            }
        }
    }
    return sRes;
}

// 优化后算法
string MinimumWindowSubstring::minWindowI(string s, string t)
{
    int nSLen = s.length(), nTLen = t.length(), nLeft = 0, nRight = 0, nRes = INT_MAX, nFirst = 0;
    if (nSLen < nTLen) return "";

    int m[128] = { 0 };
    for (auto c : t) ++m[c];

    while (nRight < nSLen)
    {
        if (m[s[nRight++]]-- > 0) nTLen--;
        while (!nTLen)
        {
            if (nRes < nRight - nLeft) nRes = nRight - (nFirst = nLeft);
            if (!m[s[nLeft++]]++) nTLen++;
        }
    }

    return nRes == INT_MAX ? "" : s.substr(nFirst, nRes);
}

