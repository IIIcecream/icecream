#include "others/RotateArray.h"
#include <algorithm>

bool RotateArray::solve()
{
    rotate(m_nums, m_nK);
    return true;
}

// Leetcode 189. Rotate Array
// 矩阵变化
// [A转置  B转置]转置 = [B A]
void RotateArray::rotate(vector<int>& nums, int k)
{
    size_t nLen = nums.size();
    k %= nLen;
    if (!nLen || !k) return;

    int n1 = (nLen - k) / 2;
    for (size_t i = 0; i < n1; ++i) swap(nums[i], nums[nLen - k - i - 1]);

    int n2 = nLen - k / 2;
    for (size_t i = (nLen - k); i < n2; ++i) swap(nums[i], nums[2 * nLen - i - k - 1]);

    for (size_t i = 0; i < nLen / 2; ++i) swap(nums[i], nums[nLen - i - 1]);
}

void  rotate2(vector<int>& nums, int k)
{
    size_t nLen = nums.size();
    k %= nLen;
    if (!nLen || !k) return;

    reverse(nums.begin(), nums.begin() + nLen - k);
    reverse(nums.begin() + nLen - k, nums.end());
    reverse(nums.begin(), nums.end());
}

