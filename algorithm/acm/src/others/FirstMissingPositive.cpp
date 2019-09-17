#include "others/FirstMissingPositive.h"

bool FirstMissingPositive::solve()
{
    return firstMissingPositive(m_nums);
}

// LeetCode 41. First Missing Positive
int FirstMissingPositive::firstMissingPositive(vector<int>& nums)
{
    for (size_t i = 0; i < nums.size(); ++i)
    {
        while (nums[i] != i + 1)
        {
            // �������������ڸ����������������������λ�õ�������ȵ�ʱ������while
            if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]) break;

            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (size_t i = 0; i < nums.size(); ++i)
        if (nums[i] != i + 1) return i + 1;

    return nums.size() + 1;
}

