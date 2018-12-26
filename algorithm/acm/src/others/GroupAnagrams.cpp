#include "others\GroupAnagrams.h"
#include <algorithm>
#include <unordered_map>

bool GroupAnagrams::solve()
{
    groupAnagrams(m_strs);
    return true;
}

// Group Anagrams LeetCode T49
// ��1�뷨�ǣ�����Ԫ��ȫ���У���¼��hash���У�Ȼ���Һ���Ԫ���Ƿ��ڸ�hash�У����ǳ�ʱ��
// �������˿����˵Ĵ��룬���ֲ�����ȫ���У�ֱ�Ӷ�Ԫ�������ok��
void GroupAnagrams::groupAnagrams(vector<string>& strs)
{
    unordered_map<string, int> m;
    for (auto str : strs)
    {
        string sCur = str;
        sort(sCur.begin(), sCur.end());
        if (m.count(sCur)) // �Ĵ��Ѿ���ͬ�����
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

