#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// 滑动窗口中位数
class SlidingWindowMedian : public IACM
{
public:
    SlidingWindowMedian(vector<int>& nums, int k) : m_nK(k), m_nums(nums) {}
    virtual bool solve() override;

private:
    vector<double> medianSlidingWindow(vector<int>& nums, int k);

private:
    int m_nK;
    vector<int> m_nums;
};