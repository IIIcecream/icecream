#include "others/InsertInterval.h"
#include "ACMMathCommon.h"
#include <algorithm>

bool InsertInterval::solve()
{
    insert(m_intervals, m_newInterval);
    return true;
}

// LeetCode 57. Insert Interval
vector<vector<int>> InsertInterval::insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    auto itr = std::lower_bound(intervals.begin(), intervals.end(), newInterval, [](const vector<int> &left, const vector<int> &right)->bool
    {
        return left[1] < right[0];
    });

    int j = 0, i = itr - intervals.begin();
    for (j = i; j < intervals.size() && newInterval[1] >= intervals[j][0]; ++j)
        newInterval = { ACM::min(newInterval[0], intervals[j][0]), ACM::max(newInterval[1], intervals[j][1]) };

    intervals.insert(intervals.begin() + j, newInterval);
    intervals.erase(intervals.begin() + i, intervals.begin() + j);

    return intervals;
}

