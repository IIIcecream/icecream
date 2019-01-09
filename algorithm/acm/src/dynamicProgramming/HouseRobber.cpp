#include "dynamicProgramming\HouseRobber.h"
#include "ACMMathCommon.h"

bool HouseRobber::solve()
{
    rob(m_nums);
    return true;
}

// House Robber LeetCode T198
int HouseRobber::rob(vector<int>& nums)
{
    int len = nums.size();
    if (!len) return 0;
    for (int i = 1; i < len; ++i)
    {
        if (i == 1 && nums[1] < nums[0]) nums[1] = nums[0];
        else nums[i] = ACM::max(nums[i] + nums[i - 2], nums[i - 1]);
    }
    return nums[len - 1];
}

// House Robber II LeetCode T213
int HouseRobber::rob2(vector<int>& nums)
{
    if (nums.size() < 2) return rob(nums);
    vector<int> nums1 = vector<int>(nums.begin(), nums.end() - 1);
    vector<int> nums2 = vector<int>(nums.begin() + 1, nums.end());
    return ACM::max(rob(nums1), rob(nums2));
}

