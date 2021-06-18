#pragma once

#include "IACM.h"
#include <vector>
using std::vector;

// ≤Â»Î«¯º‰
class  InsertInterval : public IACM
{
public:
    InsertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) : m_intervals(intervals), m_newInterval(newInterval) {}
    virtual bool solve() override;

private:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);

private:
    vector<vector<int>> m_intervals;
    vector<int> m_newInterval;
};