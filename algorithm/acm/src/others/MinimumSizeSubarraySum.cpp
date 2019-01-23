#include "others\MinimumSizeSubarraySum.h"
#include "ACMMathCommon.h"

bool MinimumSizeSubarraySum::solve()
{
    minSubArrayLen(m_nS, m_nums);
    return true;
}

// Minimum Size Subarray Sum Leetcode T209
// »¬¶¯´°¿Ú
int MinimumSizeSubarraySum::minSubArrayLen(int s, vector<int>& nums)
{
    int nRes = nums.size() + 1;
    int nSum = 0, left = 0, right = 0;
    while (right <= (int)nums.size())
    {
        if (nSum < s) nSum += nums[right++];
        else nSum -= nums[left++];

        if (nSum >= s) nRes = ACM::min(nRes, right - left);
    }

    return nRes == nums.size() + 1 ? 0 : nRes;
}

