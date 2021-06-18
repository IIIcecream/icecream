#include "slidingWindow/MaXConsecutiveOnesIII.h"

bool MaxConsecutiveOnesIII::solve()
{
    findMaxConsecutiveOnes(m_nums, m_nK);
    return true;
}

// LeetCode T1004 最大连续1的个数 III nums.size:[1, 20000] k:[0, 20000]
// 滑动窗口问题
int MaxConsecutiveOnesIII::findMaxConsecutiveOnes(vector<int>& nums, int k)
{
    int nRes = 0, nTemp = 0, nZiroCount = 0, nLeft = 0, nRight = 0, nLen = nums.size();
    for (int n : nums)
    {
        if (n) nTemp++;
        else if (nZiroCount < k)
        {
            nTemp++;
            nZiroCount++;
        }
        else
        {
            nRes = nRes > nTemp ? nRes : nTemp;
            nLeft = findIndexBehindZero(nums, nLeft);
            nTemp = nRight - nLeft + 1;
        }
        ++nRight;
    }

    return nRes;
}

int MaxConsecutiveOnesIII::findIndexBehindZero(vector<int> &nums, int nCur)
{
    for (size_t i = nCur; i < nums.size(); ++i)
    {
        if (nums[i] == 0) return i + 1;
    }
    return nums.size() - 1;
}

