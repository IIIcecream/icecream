#include "others\GroupAnagrams.h"
#include <algorithm>
#include <unordered_map>

bool GroupAnagrams::solve()
{
    groupAnagrams(m_strs);
    return true;
}

// Group Anagrams LeetCode T49
// 第1想法是，先求元素全排列，记录到hash表中，然后找后续元素是否在该hash中，但是超时了
// 后来看了看别人的代码，发现不用求全排列，直接对元素排序就ok了
void GroupAnagrams::groupAnagrams(vector<string>& strs)
{
    unordered_map<string, int> m;
    for (auto str : strs)
    {
        string sCur = str;
        sort(sCur.begin(), sCur.end());
        if (m.count(sCur)) // 改词已经有同类的了
        {
            m_res[m[sCur]].push_back(str);
        }
        else
        {
            m[sCur] = m_res.size();
            m_res.push_back(vector<string>{str});
        }
    }
}

