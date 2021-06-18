#include "graph/CourseSchedule.h"
#include <algorithm>

bool CourseSchedule::solve()
{
    return canFinish2(m_nNumCourses, m_vecPrerequisites);
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
    for (size_t i = 0; i < prerequisites.size(); ++i)
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
        for (size_t i = 0; bRes && i < graph[nVertex].size(); ++i) bRes &= dfs(graph[nVertex][i]);

    if (bRes) visited[nVertex] = 2;
    return bRes;
}

#include <queue>
// 方法2，通过统计入度的方式，上面的方法是52ms，本方法是24ms
bool CourseSchedule::canFinish2(int numCourses, vector<vector<int>>& prerequisites)
{
    if (prerequisites.empty()) return true;
    // 边数超标，肯定有环。因为题中肯定了没有重复边
    if (prerequisites.size() > numCourses * (numCourses - 1) / 2.) return false;

    vector<int> indegree(numCourses, 0); // 入度
    vector<vector<int>> graph(numCourses, vector<int>());

    // 生成邻接表及入度map
    for (size_t i = 0; i < prerequisites.size(); ++i)
    {
        int nSrc = prerequisites[i][0];
        int nDest = prerequisites[i][1];

        graph[nSrc].push_back(nDest);
        indegree[nDest]++;
    }

    queue<int> zeroQueue;   // 当前入度为0的队列

    for (size_t i = 0; i < indegree.size(); ++i)
    {
        if (indegree[i] == 0) zeroQueue.push(i);
    }

    int nVisit = 0; // 入度已经为0的顶点
    while (!zeroQueue.empty())
    {
        int n = zeroQueue.front();
        zeroQueue.pop();
        nVisit++;
        for (size_t i = 0; i < graph[n].size(); ++i)
        {
            if (--indegree[graph[n][i]] == 0) zeroQueue.push(graph[n][i]);
        }
    }

    if (nVisit == numCourses) return true;
    return false;
}
