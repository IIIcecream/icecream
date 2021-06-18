#include "binarySearch\FindPeakElement.h"

bool FindPeakElement::solve()
{
    return findPeakElement(m_nums);
}

// LeetCode 162 Find Peak Element
int FindPeakElement::findPeakElement(vector<int>& nums)
{
    if (nums.empty()) return -1;
    return f1(nums);
    return f2(nums);
}

// 解法1，递归
int FindPeakElement::f1(vector<int>& nums)
{

    return binarySearch(nums, 0, nums.size() - 1);
}

// 解法2，非递归
int FindPeakElement::f2(vector<int>& nums)
{
    int nLeft = 0, nRight = nums.size() - 1;
    while(nLeft < nRight)
    {
        int mid = nLeft + (nRight - nLeft) * 0.5;
        if (nums[mid] > nums[mid + 1]) nRight = mid;
        else nLeft = mid + 1;
    }
    return nLeft;
}

int FindPeakElement::binarySearch(vector<int>& nums, int nLow, int nHigh)
{
    if (nLow > nHigh) return -1;
    if (nLow == nHigh) return nLow;

    int nMid = (nLow + nHigh) * 0.5;
    if (nMid == nLow) return nums[nHigh] > nums[nMid] ? nHigh : nMid;

    //if (nums[nHigh] > nums[nMid]) return binarySearch(nums, nMid, nHigh);
    /*else */if(nums[nLow] > nums[nMid] || nums[nMid - 1] > nums[nMid]) return binarySearch(nums, nLow, nMid);
    else return binarySearch(nums, nMid, nHigh);
}
