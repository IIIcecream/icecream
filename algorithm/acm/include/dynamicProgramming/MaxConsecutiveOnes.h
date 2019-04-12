#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// Max Consecutive Ones
class MaxConsecutiveOnes : public IACM
{
public:
    MaxConsecutiveOnes(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    int findMaxConsecutiveOnes(vector<int>& nums);

private:
    vector<int> m_nums;
};