#include "graph/CourseScheduleII.h"
#include <queue>
using std::queue;

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
        int nSrc = prerequisites[i][1];
        int nDest = prerequisites[i][0];

        indegree[nDest]++;
        graph[nSrc].push_back(nDest);
    }

    vector<int> res;

    queue<int> zeroDegree;
    for (int i = 0; i < numCourses; ++i)
    {
        if (indegree[i] == 0) zeroDegree.push(i);
    }

    while (!zeroDegree.empty())
    {
        int n = zeroDegree.front();
        zeroDegree.pop();
        res.push_back(n);

        for (size_t i = 0; i < graph[n].size(); ++i)
        {
            if (--indegree[graph[n][i]] == 0) zeroDegree.push(graph[n][i]);
        }
    }

    if (res.size() != numCourses) return vector<int>();
    return res;
}

