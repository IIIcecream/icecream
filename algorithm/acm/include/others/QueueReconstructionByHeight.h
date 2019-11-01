#pragma once
#include "IACM.h"
#include <vector>
using std::vector;

// ��������ؽ�����
class QueueReconstructionByHeight : public IACM
{
public:
    QueueReconstructionByHeight(vector<vector<int>>& people) : m_people(people) {}
    virtual bool solve() override;

private:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people);

private:
    vector<vector<int>> m_people;
};