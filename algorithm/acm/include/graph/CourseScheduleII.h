#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// ¿Î³Ì±í II
class  CourseScheduleII : public IACM
{
public:
    CourseScheduleII(int numCourses, vector<vector<int>>& prerequisites) : m_nNumCourses(nullptr), m_prerequisites(prerequisites) {}
    virtual bool solve() override;

private:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

private:
    int m_nNumCourses;
    vector<vector<int>> m_prerequisites;
};