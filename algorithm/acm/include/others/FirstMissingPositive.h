#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// 缺失的第一个正数
class FirstMissingPositive : public IACM
{
public:
    FirstMissingPositive(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    int firstMissingPositive(vector<int>& nums);

private:
    vector<int> m_nums;
};