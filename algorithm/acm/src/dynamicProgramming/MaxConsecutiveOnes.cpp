#include "dynamicProgramming\MaxConsecutiveOnes.h"
#include "ACMMathCommon.h"

bool MaxConsecutiveOnes::solve()
{
    findMaxConsecutiveOnes(m_nums);
    return true;
}

// LeetCode T485 �������1�ĸ���
int MaxConsecutiveOnes::findMaxConsecutiveOnes(vector<int>& nums)
{
    int dp = 0, temp = 0;
    for (int n : nums)
        if (n) ++temp;
        else {
            if (temp > dp) dp = temp;
            temp = 0;
        }

    return temp > dp ? temp : dp;
}

