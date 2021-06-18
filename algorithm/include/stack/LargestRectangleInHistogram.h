#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// 柱状图中最大的矩形
class LargestRectangleInHistogram : public IACM
{
public:
    LargestRectangleInHistogram(vector<int>& heights) : m_heights(heights) {}
    virtual bool solve() override;

    int largestRectangleArea(vector<int>& heights);

private:
    vector<int> m_heights;
};