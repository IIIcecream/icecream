#pragma once

#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// Max Consecutive OnesIII
class MaxConsecutiveOnesIII : public IACM
{
public:
    MaxConsecutiveOnesIII(vector<int>& nums, int k) : m_nums(nums), m_nK(k) {}
    virtual bool solve() override;

private:
    int findMaxConsecutiveOnes(vector<int>& nums, int k);
    int findIndexBehindZero(vector<int> &nums, int nCur);

private:
    int m_nK;
    vector<int> m_nums;
};