#pragma once
#include "IACM.h"
#include <vector>
using std::vector;

// �����е�K���Ԫ��
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
