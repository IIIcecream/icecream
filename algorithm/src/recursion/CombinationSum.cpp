#include "recursion/CombinationSum.h"
#include <algorithm>

bool CombinationSum::solve()
{
    vector<vector<int>> res;
    vector<int> cur;
    sort(m_candidates.begin(), m_candidates.end());
    combinationSumCore(m_candidates, m_nTarget, 0, cur, res);
    return true;
}

//  组合总和 LeetCode T39
void CombinationSum::combinationSumCore(vector<int>& candidates, int target, int pos, vector<int>& cur, vector<vector<int>> &res)
{
    for (int i = pos; i < (int)candidates.size(); ++i)
    {
        if(target < candidates[i]) break;

        cur.push_back(candidates[i]);
        if (target == candidates[i]) res.push_back(cur);
        else combinationSumCore(candidates, target - candidates[i], i, cur, res);
        cur.pop_back();
    }
}

bool CombinationSumII::solve()
{
    vector<vector<int>> res;
    vector<int> cur;
    sort(m_candidates.begin(), m_candidates.end());
    combinationSumCore(m_candidates, m_nTarget, 0, cur, res);
    return true;
}

//  组合总和 LeetCode T40
void CombinationSumII::combinationSumCore(vector<int>& candidates, int target, int pos, vector<int>& cur, vector<vector<int>> &res)
{
    for (int i = pos; i < (int)candidates.size(); ++i)
    {
        if (target < candidates[i]) break;

        cur.push_back(candidates[i]);
        if (target == candidates[i]) res.push_back(cur);
        else combinationSumCore(candidates, target - candidates[i], i + 1, cur, res);
        int nBack = cur.back();
        cur.pop_back();

        while (i + 1 < (int)candidates.size() && candidates[i + 1] == nBack) ++i;
    }
}
