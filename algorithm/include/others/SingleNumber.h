#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// ֻ����һ�ε�����
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

// ֻ����һ�ε�����II
class SingleNumberII : public IACM
{
public:
    SingleNumberII(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    int singleNumber(vector<int>& nums);

private:
    vector<int> m_nums;
};

// ֻ����һ�ε�����III
class SingleNumberIII : public IACM
{
public:
    SingleNumberIII(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    vector<int> singleNumber(vector<int>& nums);

private:
    vector<int> m_nums;
};