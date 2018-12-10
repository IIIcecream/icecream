#include "string\DistinctSubsequnces.h"
using namespace std;

// LeetCode T115
bool DistinctSubsequnces::solve()
{
    subString(0, 0);
    return true;
}

void DistinctSubsequnces::subString(int nCurS, int nCurT)
{
    if (nCurS > m_nSLen) return;
    if (m_nSLen - nCurS < m_nTLen - nCurT) return; //¼ôÖ¦
    if (nCurT == m_nTLen) { ++m_nRes; return; }

    for (int i = nCurS; i < m_nSLen; ++i)
        for (int j = nCurT; j < m_nTLen; ++j)
            if (m_sS[i] == m_sT[j]) subString(++i, ++j);
}
