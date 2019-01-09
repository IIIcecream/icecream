#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// ¥Úº“ΩŸ…·
class HouseRobber : public IACM
{
public:
    HouseRobber(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    int rob(vector<int>& nums);
    int rob2(vector<int>& nums);

private:
    vector<int> m_nums;
};