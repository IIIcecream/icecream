#pragma once

#include "BinarySearch.h"
#include <vector>
using namespace std;

// Search in Rotated Sorted Array
class SearchInRotatedSortedArray : public BinarySearch
{
public:
    SearchInRotatedSortedArray(vector<int>& nums, int target) : m_nums(nums), m_nTarget(target) {}
    virtual bool solve() override  { return false; }

private:
    int search(vector<int>& nums, int target);
    int binarySearch(int nLow, int nHigh, int nTarget);

private:
    vector<int> m_nums;
    int m_nTarget;
};
