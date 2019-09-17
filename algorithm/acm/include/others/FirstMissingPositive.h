#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// ȱʧ�ĵ�һ������
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