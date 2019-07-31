#include "graph\CourseSchedule.h"
#include <algorithm>

bool CourseSchedule::solve()
{
    return canFinish(m_nNumCourses, m_vecPrerequisites);
}

// Course Schedule LeetCode T207
// 判断有向图中是否有环
bool CourseSchedule::canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    if (prerequisites.empty()) return true;
    // 边数超标，肯定有环。因为题中肯定了没有重复边
    if (prerequisites.size() > numCourses * (numCourses - 1) / 2.) return false;

    visited.resize(numCourses, 0);
    // 生成邻接表
    for (int i = 0; i < prerequisites.size(); ++i)
    {
        int nSrc = prerequisites[i][0];
        int nDest = prerequisites[i][1];

        graph[nSrc].push_back(nDest);
    }

    // 判断是否有环
    for (auto itr = graph.begin(); itr != graph.end(); ++itr)
    {
        if (!dfs(itr->first)) return false;
    }
    return true;
}

bool CourseSchedule::dfs(int nVertex)
{
    // 该顶点之前已经刚问过了，没有问题，返回true
    if (visited[nVertex] == 2) return true;
    // 该顶点正在当前dfs中，说明有环，返回false
    if (visited[nVertex] == 1) return false;

    visited[nVertex] = 1;

    bool bRes = true;
    if(graph.count(nVertex))
        for (int i = 0; bRes && i < graph[nVertex].size(); ++i) bRes &= dfs(graph[nVertex][i]);

    if (bRes) visited[nVertex] = 2;
    return bRes;
}
