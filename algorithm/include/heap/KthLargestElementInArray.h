#pragma once
#include "IACM.h"
#include <vector>
using std::vector;

// 数组中第K大的元素
class KthLargestElementInArray : public IACM
{
public:
    KthLargestElementInArray(vector<int> &nums, int k) : m_nums(nums), m_nK(k) {}
    virtual bool solve() override;

private:
    int findKthLargest(vector<int>& nums, int k);

private:
    vector<int> m_nums;
    int m_nK;
};
