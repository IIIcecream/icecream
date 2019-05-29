#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// Ðý×ªÊý×é
class RotateArray : public IACM
{
public:
    RotateArray(vector<int>& nums, int k) : m_nums(nums), m_nK(k) {}
    virtual bool solve() override;

private:
    void rotate(vector<int>& nums, int k);

private:
    vector<int> m_nums;
    int m_nK;
};