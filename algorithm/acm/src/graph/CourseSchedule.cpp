#include "graph\CourseSchedule.h"
#include <algorithm>

bool CourseSchedule::solve()
{
    return canFinish(m_nNumCourses, m_vecPrerequisites);
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
    for (int i = 0; i < prerequisites.size(); ++i)
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
        for (int i = 0; bRes && i < graph[nVertex].size(); ++i) bRes &= dfs(graph[nVertex][i]);

    if (bRes) visited[nVertex] = 2;
    return bRes;
}
