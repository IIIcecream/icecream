#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

class SingleNumber : public IACM
{
public:
    SingleNumber(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    int singleNumber(vector<int>& nums);

private:
    vector<int> m_nums;
};

class SingleNumber2 : public IACM
{
public:
    SingleNumber2(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    int singleNumber(vector<int>& nums);

private:
    vector<int> m_nums;
};