#include "graph/CourseSchedule.h"
#include <algorithm>

bool CourseSchedule::solve()
{
    return canFinish2(m_nNumCourses, m_vecPrerequisites);
}

// Course Schedule LeetCode T207
// �ж�����ͼ���Ƿ��л�
bool CourseSchedule::canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    if (prerequisites.empty()) return true;
    // �������꣬�϶��л�����Ϊ���п϶���û���ظ���
    if (prerequisites.size() > numCourses * (numCourses - 1) / 2.) return false;

    visited.resize(numCourses, 0);
    // �����ڽӱ�
    for (size_t i = 0; i < prerequisites.size(); ++i)
    {
        int nSrc = prerequisites[i][0];
        int nDest = prerequisites[i][1];

        graph[nSrc].push_back(nDest);
    }

    // �ж��Ƿ��л�
    for (auto itr = graph.begin(); itr != graph.end(); ++itr)
    {
        if (!dfs(itr->first)) return false;
    }
    return true;
}

bool CourseSchedule::dfs(int nVertex)
{
    // �ö���֮ǰ�Ѿ����ʹ��ˣ�û�����⣬����true
    if (visited[nVertex] == 2) return true;
    // �ö������ڵ�ǰdfs�У�˵���л�������false
    if (visited[nVertex] == 1) return false;

    visited[nVertex] = 1;

    bool bRes = true;
    if(graph.count(nVertex))
        for (size_t i = 0; bRes && i < graph[nVertex].size(); ++i) bRes &= dfs(graph[nVertex][i]);

    if (bRes) visited[nVertex] = 2;
    return bRes;
}

#include <queue>
// ����2��ͨ��ͳ����ȵķ�ʽ������ķ�����52ms����������24ms
bool CourseSchedule::canFinish2(int numCourses, vector<vector<int>>& prerequisites)
{
    if (prerequisites.empty()) return true;
    // �������꣬�϶��л�����Ϊ���п϶���û���ظ���
    if (prerequisites.size() > numCourses * (numCourses - 1) / 2.) return false;

    vector<int> indegree(numCourses, 0); // ���
    vector<vector<int>> graph(numCourses, vector<int>());

    // �����ڽӱ����map
    for (size_t i = 0; i < prerequisites.size(); ++i)
    {
        int nSrc = prerequisites[i][0];
        int nDest = prerequisites[i][1];

        graph[nSrc].push_back(nDest);
        indegree[nDest]++;
    }

    queue<int> zeroQueue;   // ��ǰ���Ϊ0�Ķ���

    for (size_t i = 0; i < indegree.size(); ++i)
    {
        if (indegree[i] == 0) zeroQueue.push(i);
    }

    int nVisit = 0; // ����Ѿ�Ϊ0�Ķ���
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
