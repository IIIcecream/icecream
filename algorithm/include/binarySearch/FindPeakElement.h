#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// Ѱ�ҷ�ֵ
class FindPeakElement : public IACM
{
public:
    FindPeakElement(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override { return false; }

private:
    int findPeakElement(vector<int>& nums);

    int f1(vector<int>& nums);
    int f2(vector<int>& nums);
    int binarySearch(vector<int>& nums, int nLow, int nHigh);

private:
    vector<int> m_nums;
};
