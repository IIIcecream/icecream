#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// ¿Î³Ì±í
class CourseSchedule : public IACM
{
public:
    CourseSchedule(int numCourses, vector<pair<int, int>>& prerequisites)
        : m_nNumCourses(numCourses), m_vecPrerequisites(prerequisites) {}
    virtual bool solve() override;

private:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);

private:
    int m_nNumCourses;
    vector<pair<int, int>> m_vecPrerequisites;
};
