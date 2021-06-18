#include "recursion/PalindromePartitioning.h"

bool PalindromePartitioning::solve()
{
    partition(m_str);
    return true;
}

vector<vector<string>> PalindromePartitioning::partition(string s)
{
    vector<vector<string>> res;
    vector<string> curPartition;

    doPartition(s, 0, res, curPartition);
    return res;
}

void PalindromePartitioning::doPartition(string s, int n, vector<vector<string>> &res, vector<string> &cur)
{
    if (n == s.length())
    {
        res.push_back(cur);
        return;
    }

    for (size_t i = n + 1; i <= s.length(); ++i)
    {
        string sub = s.substr(n, i - n);
        if (isPalindrome(sub))
        {
            cur.push_back(sub);
            doPartition(s, i, res, cur);
            cur.pop_back();
        }
    }
}

bool PalindromePartitioning::isPalindrome(string &s)
{
    for (int i = 0, j = s.length() - 1; i <= j; ++i, --j)
    {
        if (s[i] != s[j]) return false;
    }
    return true;
}

