#include "graph/CourseScheduleII.h"
#include <queue>

bool CourseScheduleII::solve()
{
    return !findOrder(m_nNumCourses, m_prerequisites).empty();
}

// LeetCode 210. Course Schedule II
// 输出拓扑排序结果，入度从小到大排序即可
vector<int> CourseScheduleII::findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> graph(numCourses, vector<int>());

    for (size_t i = 0; i < prerequisites.size(); ++i)
    {
        int nSrc = prerequisites[i][0];
        int nDest = prerequisites[i][1];

        indegree[nDest]++;


    }

    queue<int> zeroDegree;
}

