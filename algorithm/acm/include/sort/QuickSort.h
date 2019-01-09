#pragma once
#include "SortCommon.h"

class QuickSort : public MySort
{
public:
    QuickSort(vector<int> &nums) : MySort(nums) {}
    virtual void sort(vector<int> &nums) override;

private:
    virtual void sort(vector<int> &nums, int left, int right);

private:

};