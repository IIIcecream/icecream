#include "sort\KthLargestElement.h"

bool KthLargestElement::solve()
{
    findKthLargest(m_nums, m_nK);
    return true;
}

// Kth Largest Element in an Array Leetcode T215
// 快排剪枝，因为快排正好是将比当前值小的放到左边，把当前值大的放到右边，然后根据数量判断是只用继续排左边还是继续排右边，如果当前值右边数量刚好等于k-1，那直接输出当前值即可
int KthLargestElement::findKthLargest(vector<int>& nums, int k)
{
    return 0;
}

