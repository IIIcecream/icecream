#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// �����������ֵ
class SlidingWindowMaximum : public IACM
{
public:
    SlidingWindowMaximum(vector<int>& nums, int k) : m_nums(nums), m_nK(k) {}
    virtual bool solve() override;

private:
    vector<int> maxSlidingWindow(vector<int>& nums, int k);

private:
    vector<int> m_nums;
    int m_nK;
};
