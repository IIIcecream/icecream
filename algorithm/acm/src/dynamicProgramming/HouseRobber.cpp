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

// House Robber III LeetCode T337
int HouseRobber::rob3(TreeNode* root)
{
    if (!root) return 0;
    if (!robMap.count(root))
    {
        int nVal = 0;
        if (root->left) nVal += rob3(root->left->left) + rob3(root->left->right);
        if (root->right)nVal += rob3(root->right->left) + rob3(root->right->right);
        nVal = ACM::max(nVal + root->val, rob3(root->left) + rob3(root->right));
        robMap[root] = nVal;
    }
    
    return robMap[root];
}

