#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// 数组中的第K个最大元素
class KthLargestElement : public IACM
{
public:
    KthLargestElement(vector<int>& nums, int k) : m_nums(nums), m_nK(k) {}
    virtual bool solve() override;

private:
    int findKthLargest(vector<int>& nums, int k);

private:
    vector<int> m_nums;
    int m_nK;
};