#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

class MySort : public IACM
{
public:
    MySort(vector<int> &nums) : m_nums(nums) {}
    virtual bool solve() override { sort(m_nums); return; }
    virtual void sort(vector<int> &nums) = 0;
private:
    vector<int> m_nums;
};