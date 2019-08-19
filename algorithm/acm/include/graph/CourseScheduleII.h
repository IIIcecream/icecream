#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// �γ̱� II
class  CourseScheduleII : public IACM
{
public:
    CourseScheduleII(int numCourses, vector<vector<int>>& prerequisites) : m_nNumCourses(numCourses), m_prerequisites(prerequisites) {}
    virtual bool solve() override;

private:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

private:
    int m_nNumCourses;
    vector<vector<int>> m_prerequisites;
};