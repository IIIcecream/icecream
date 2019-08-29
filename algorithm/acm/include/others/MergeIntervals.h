#pragma once

#include "IACM.h"
#include <vector>
using std::vector;

class MergeIntervals : public IACM
{
public:
    MergeIntervals(vector<vector<int>>& intervals) : m_intervals(intervals) {}

    virtual bool solve() override;

private:
    vector<vector<int>> merge(vector<vector<int>>& intervals);

private:
    vector<vector<int>> m_intervals;
};