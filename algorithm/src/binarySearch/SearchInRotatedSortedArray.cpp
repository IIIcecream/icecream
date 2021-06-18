#include "binarySearch\SearchInRotatedSortedArray.h"

bool SearchInRotatedSortedArray::solve()
{
    search(m_nums, m_nTarget);
    return true;
}

// 搜索旋转排序数组 LeetCode T33
int SearchInRotatedSortedArray::search(vector<int>& nums, int target)
{
    return binarySearch(0, nums.size() - 1, target);
}

// 二分，其中肯定有一个是有序的，另一个可能是无序的，如果target不在有序的那边，则继续对无序的二分，有一个有序 另一个可能无序
int SearchInRotatedSortedArray::binarySearch(int nLow, int nHigh, int nTarget)
{
    if (nLow > nHigh) return -1;
    if (nLow == nHigh) return m_nums[nLow] == nTarget ? nLow : -1;
    int nMid = (nLow + nHigh) / 2;
    if (m_nums[nMid] == nTarget) return nMid;
    // 左边有序
    if (m_nums[nLow] <= m_nums[nMid])
    {
        if (m_nums[nLow] <= nTarget && nTarget <= m_nums[nMid])
            return BinarySearch::binarySearch(m_nums, nLow, nMid, nTarget);
        else
            return binarySearch(nMid + 1, nHigh, nTarget);
    }
    // 右边有序
    else
    {
        if (m_nums[nMid] <= nTarget && nTarget <= m_nums[nHigh])
            return BinarySearch::binarySearch(m_nums, nLow, nMid, nTarget);
        else
            return binarySearch(nLow, nMid, nTarget);
    }
}

