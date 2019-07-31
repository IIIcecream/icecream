#pragma once
#include "IACM.h"
#include <vector>
#include <unordered_map>
using namespace std;

// 课程表
class CourseSchedule : public IACM
{
public:
    CourseSchedule(int numCourses, vector<vector<int>>& prerequisites)
        : m_nNumCourses(numCourses), m_vecPrerequisites(prerequisites) {
    }
    virtual bool solve() override;

private:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
    bool dfs(int nVertex);

private:
    int m_nNumCourses;
    vector<vector<int>>& m_vecPrerequisites;

    vector<int> visited; //记录各顶点的访问状态。 0代表未访问，1代表正在访问，2代表已被访问
    unordered_map<int, vector<int>> graph;  // 图 <顶点， vector<相连顶点>>
};
