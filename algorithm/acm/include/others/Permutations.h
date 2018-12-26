#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

// Permutations
class Premutations : public IACM
{
public:
    Premutations(vector<int>& nums) : m_nums(nums) {}
    virtual bool solve() override;

private:
    void permute(vector<int>& nums, int pos = 0);
    void permuteUnique(vector<int> &nums, int pos = 0);

private:
    vector<int> m_nums;
    vector<vector<int>> m_res;
};