#pragma once
#include "IACM.h"
#include <vector>
using std::vector;

// ��������Ӽ�
class LargestDivisibleSubset : public IACM
{

public:
    LargestDivisibleSubset(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    vector<int> largestDivisibleSubset(vector<int>& nums);

private:
    vector<int> m_nums;
};