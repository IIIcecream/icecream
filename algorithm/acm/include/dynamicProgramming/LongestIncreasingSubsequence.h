#pragma once

#include <vector>
#include "IACM.h"
using std::vector;

// 最长上升子序列
class LongestIncreasingSubsequence : public IACM
{
public:
    LongestIncreasingSubsequence(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    int lengthOfLIS(vector<int>& nums);
    int lengthOfLIS2(vector<int>& nums);

private:
    vector<int> m_nums;
};