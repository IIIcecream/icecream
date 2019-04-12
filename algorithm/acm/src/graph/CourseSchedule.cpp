#include "graph\CourseSchedule.h"

bool CourseSchedule::solve()
{
    return canFinish(m_nNumCourses, m_vecPrerequisites);
}

// Course Schedule LeetCode T207
// 判断有向图中是否有环
bool CourseSchedule::canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
    return false;
}

