#include "dynamicProgramming/MaximumProductSubarray.h"
#include "ACMMathCommon.h"

bool MaximumProductSubarray::solve()
{
    return maxProduct(m_nums);
}

// LeetCode 152. Maximum Product Subarray
// ˼·����¼һ����������ǰ�±����С�˻����ټ�¼һ������ǰ�±�����˻�
// ��С�˻����ô��Ǹ�������
int MaximumProductSubarray::maxProduct(vector<int>& nums)
{
    if (nums.empty()) return 0;

    int nMax = nums[0];
    int nMin = nums[0];
    
    int nRes = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
    {
        if (nums[i] < 0) swap(nMax, nMin);

        nMax = ACM::max(nMax * nums[i], nums[i]);
        nMin = ACM::min(nMin * nums[i], nums[i]);

        if (nMax > nRes) nRes = nMax;
    }

    return nRes;
}

