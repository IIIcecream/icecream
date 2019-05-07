#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// ��״ͼ�����ľ���
class LargestRectangleInHistogram : public IACM
{
public:
    LargestRectangleInHistogram(vector<int>& heights) : m_heights(heights) {}
    virtual bool solve() override;

    int largestRectangleArea(vector<int>& heights);

private:
    vector<int> m_heights;
};