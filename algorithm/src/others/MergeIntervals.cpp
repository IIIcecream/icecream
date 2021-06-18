#include "others/MergeIntervals.h"
#include <algorithm>
#include "ACMMathCommon.h"

bool MergeIntervals::solve()
{
    merge(m_intervals);
    return true;
}

// LeetCode 56. Merge Intervals
vector<vector<int>> MergeIntervals::merge(vector<vector<int>>& intervals)
{
    if (intervals.size() <= 1) return intervals;

    std::sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= intervals[i - 1][1])
        {
            intervals[i][0] = ACM::min(intervals[i][0], intervals[i - 1][0]);
            intervals[i][1] = ACM::max(intervals[i][1], intervals[i - 1][1]);
        }
        else res.push_back(intervals[i- 1]); 
    }
    res.push_back(intervals.back());
    return res;
}

