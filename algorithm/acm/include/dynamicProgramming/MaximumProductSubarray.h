#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

//  乘积最大子序列
class MaximumProductSubarray : public IACM
{
public:
    MaximumProductSubarray(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    int maxProduct(vector<int>& nums);

private:
    vector<int> m_nums;
};