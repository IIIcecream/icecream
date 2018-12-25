#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// CombinationSum
class CombinationSum : public IACM
{
public:
    CombinationSum(vector<int>& candidates, int target) : m_candidates(candidates), m_nTarget(target) {}
    virtual bool solve() override;

private:
    void combinationSumCore(vector<int>& candidates, int target, int pos, vector<int>& cur, vector<vector<int>> &res);

private:
    vector<int> m_candidates;
    int m_nTarget;
};

// CombinationSumII
class CombinationSumII : public IACM
{
public:
    CombinationSumII(vector<int>& candidates, int target) : m_candidates(candidates), m_nTarget(target) {}
    virtual bool solve() override;

private:
    void combinationSumCore(vector<int>& candidates, int target, int pos, vector<int>& cur, vector<vector<int>> &res);

private:
    vector<int> m_candidates;
    int m_nTarget;
};