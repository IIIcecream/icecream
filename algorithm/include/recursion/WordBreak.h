#pragma once
#include "IACM.h"
#include <string>
#include <vector>
#include <set>
using namespace std;

// µ¥´Ê²ð·Ö
class WordBreak : public IACM
{
public:
    WordBreak(string s, vector<string>& wordDict) : m_strWord(s), m_wordDict(wordDict) {}
    virtual bool solve() override;

private:
    bool wordBreak(string s, vector<string>& wordDict);
    bool doBreak(size_t nStart, size_t nEnd, string &s, set<string> &setWords, set<int> &err);
    bool isValid(string &s, set<string> &setWords);

private:
    string m_strWord;
    vector<string> m_wordDict;
};