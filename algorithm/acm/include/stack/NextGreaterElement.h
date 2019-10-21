#pragma once

#include "IACM.h"
#include <vector>
using std::vector;

// 下一个更大元素 I
class NextGreaterElementI : public IACM
{
public:
    NextGreaterElementI(vector<int>& nums1, vector<int>& nums2) : m_nums1(nums1), m_nums2(nums2) {}
    virtual bool solve() override;

private:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);

private:
    vector<int> m_nums1, m_nums2;
};

// 下一个更大元素 II
class NextGreaterElementII : public IACM
{
public:
    NextGreaterElementII(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    vector<int> nextGreaterElements(vector<int>& nums);

private:
    vector<int> m_nums;
};

// 下一个更大元素 III
class NextGreaterElementIII : public IACM
{
public:
    NextGreaterElementIII(int n) : m_n(n) {}
    virtual bool solve() override;

private:
    int nextGreaterElement(int n);

private:
    int m_n;
};