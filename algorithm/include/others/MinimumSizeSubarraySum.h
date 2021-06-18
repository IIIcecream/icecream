#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// ������С��������
class MinimumSizeSubarraySum : public IACM
{
public:
    MinimumSizeSubarraySum(int s, vector<int>& nums) : m_nS(s), m_nums(nums) {}
    virtual bool solve() override;

private:
    int minSubArrayLen(int s, vector<int>& nums);

private:
    int m_nS;
    vector<int> m_nums;
};
