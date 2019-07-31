#pragma once
#include "IACM.h"
#include <vector>
#include <unordered_map>
using namespace std;

// �γ̱�
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

    vector<int> visited; //��¼������ķ���״̬�� 0����δ���ʣ�1�������ڷ��ʣ�2�����ѱ�����
    unordered_map<int, vector<int>> graph;  // ͼ <���㣬 vector<��������>>
};
