#include "others/IsomorphicStrings.h"
#include <vector>
using std::vector;

bool IsomorphicStrings::solve()
{
    return isIsomorphic(m_s, m_t);
}

// LeetCode 205. Isomorphic Strings
bool IsomorphicStrings::isIsomorphic(string s, string t)
{
    vector<int> smap(256, -1);
    vector<int> tmap(256, -1);

    for (size_t i = 0; i < s.size(); ++i)
    {
        if (smap[s[i]] == -1 && tmap[t[i]] == -1)
        {
            smap[s[i]] = t[i];
            tmap[t[i]] = s[i];
        }
        else if (smap[s[i]] != t[i] || tmap[t[i]] != s[i])
            return false;
    }
    return true;
}

