#include "recursion/WordBreak.h"

bool WordBreak::solve()
{
    wordBreak(m_strWord, m_wordDict);
    return true;
}

// WordBreak LeetCode T139
bool WordBreak::wordBreak(string s, vector<string>& wordDict)
{
    // 方法1，递归
    //使用set（红黑树）来加速查询
    set<string> setWords(wordDict.begin(), wordDict.end());
    set<int> err;//用于剪枝
    return doBreak(0, s.length(), s, setWords, err);

    // 方法2 动态规划
    vector<bool> state(s.length() + 1, false);
    state[0] = true;
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; j <= i; j++) {
            if (state[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                state[i] = true;
            }
        }
    }
    return state[s.length()];
}

bool WordBreak::doBreak(size_t nStart, size_t nEnd, string &s, set<string> &setWords, set<int> &err)
{
    if (err.find(nStart) != err.end()) return false;
    if (nStart >= nEnd) return true;

    for (size_t i = nEnd; i >= nStart; --i)
    {
        string sub = s.substr(nStart, i - nStart);
        if (sub.empty()) return false;
        if (isValid(sub, setWords))
        {
            if (doBreak(i, nEnd, s, setWords, err)) return true;
            else err.insert(i);
        }
    }
    return false;
}

bool WordBreak::isValid(string &s, set<string> &setWords)
{
    return setWords.find(s) != setWords.end();
}

