#pragma once

#include "IACM.h"

#include <vector>
#include <string>
using std::vector;
using std::string;

// ×î´óÊý
class LargestNumber : public IACM
{
public:
    LargestNumber(vector<int>& nums) : m_nums(nums) {}

    virtual bool solve() override;

private:
    string largestNumber(vector<int>& nums);

private:
    vector<int> m_nums;
};