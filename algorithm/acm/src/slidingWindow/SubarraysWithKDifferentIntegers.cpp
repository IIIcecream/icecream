#include "slidingWindow\SubarraysWithKDifferentIntegers.h"
#include <set>
#include <string>

bool SubarraysWithKDifferentIntegers::solve()
{
    subarraysWithKDistinct(m_vecA, m_nK);
    return true;
}

int SubarraysWithKDifferentIntegers::subarraysWithKDistinct(vector<int>& A, int K)
{
    int nRes = 0, nLeft = 0, nLen = A.size(), nSum = 0;
    set<int> nums;

    for (int i = 0; i < nLen; ++i)
    {
        if(nums.size() < K || nums.count(A[i])) continue;
    }

    return nRes;
}

