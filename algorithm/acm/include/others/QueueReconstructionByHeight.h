#pragma once
#include "IACM.h"
#include <vector>
using std::vector;

// 根据身高重建队列
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