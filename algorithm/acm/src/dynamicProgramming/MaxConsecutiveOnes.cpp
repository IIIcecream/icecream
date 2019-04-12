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
    int nRes = 0;

    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1) ++count;

        if (nums[i] == 0 || i == nums.size() - 1)
        {
            if (count > nRes) nRes = count;
            count = 0;
        }
    }

    return nRes;
}

