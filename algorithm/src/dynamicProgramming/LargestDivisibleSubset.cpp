#include "dynamicProgramming/LargestDivisibleSubset.h"
#include <algorithm>

bool LargestDivisibleSubset::solve()
{
    return largestDivisibleSubset(m_nums).size();
}

// LeetCode 368. Largest Divisible Subset
vector<int> LargestDivisibleSubset::largestDivisibleSubset(vector<int>& nums)
{
    if (nums.size() == 0) return nums;

    std::sort(nums.begin(), nums.end());

    vector<int> dp(nums.size(), 1), path(nums.size(), -1);
    int nMax = 0, nMaxIndex = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        int nHalf = nums[i] / 2;
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] > nHalf) break;  // 优化一下
            int nCur = dp[j] + 1;
            if (nums[i] % nums[j] == 0 && nCur > dp[i])
            {
                dp[i] = nCur;
                path[i] = j;

                if (nMax < dp[i])
                {
                    nMax = dp[i];
                    nMaxIndex = i;
                }
            }
        }
    }

    vector<int> res;
    while (nMaxIndex != -1)
    {
        res.push_back(nums[nMaxIndex]);
        nMaxIndex = path[nMaxIndex];
    }

    reverse(res.begin(), res.end());
    return res;
}

