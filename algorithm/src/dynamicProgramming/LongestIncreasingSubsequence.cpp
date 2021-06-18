#include "dynamicProgramming/LongestIncreasingSubsequence.h"
#include <algorithm>

bool LongestIncreasingSubsequence::solve()
{
    return lengthOfLIS2(m_nums);
}

// LeetCode 300. Longest Increasing Subsequence

// O(n^2)
int LongestIncreasingSubsequence::lengthOfLIS(vector<int>& nums)
{
    vector<int> dp(nums.size(), 0);
    int nRes = 0;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        int nMax = 0;
        for (size_t j = 0; j < i; ++j)
            if (dp[j] >= nMax && nums[i] > nums[j]) nMax = dp[j];
        dp[i] = nMax;

        if (dp[i] > nRes) nRes = dp[i];
    }

    return nRes;
}

// O(nlogn)
int LongestIncreasingSubsequence::lengthOfLIS2(vector<int>& nums)
{
    vector<int> vec;
    for (int n : nums)
    {
        if (vec.empty() || n > vec.back()) vec.push_back(n);
        else
        {
            // 使用库函数，二分查找
            //auto itr = std::lower_bound(vec.begin(), vec.end(), n);
            //vec[itr - vec.begin()] = n;

            int l = 0, h = vec.size() - 1;
            while (l < h)
            {
                int nMid = (l + h) / 2;
                if (vec[nMid] < n) l = nMid + 1;
                else h = nMid;
            }

            vec[l] = n;
        }
    }

    return vec.size();
}