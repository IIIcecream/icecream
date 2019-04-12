#include "dynamicProgramming\MaxConsecutiveOnes.h"
#include "ACMMathCommon.h"

bool MaxConsecutiveOnes::solve()
{
    findMaxConsecutiveOnes(m_nums);
    return true;
}

// LeetCode T485 最大连续1的个数
int MaxConsecutiveOnes::findMaxConsecutiveOnes(vector<int>& nums)
{
    size_t nLen = nums.size();
    int dp[100000], nRes;
    nRes = dp[0] = nums[0];
    for (size_t i = 1; i < nLen; ++i)
    {
        if (nums[i])
        {
            dp[i] = dp[i - 1] + 1;
            if (i == nLen - 1) nRes = ACM::max(nRes, dp[i - 1] + 1);
        }
        else { nRes = ACM::max(nRes, dp[i - 1]); dp[i] = 0; }
    }
    return nRes;
}

