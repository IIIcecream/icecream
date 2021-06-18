#pragma once
#include "IACM.h"
#include <string>
#include <vector>
using namespace std;

// Word Ladder
class WordLadder : public IACM
{
public:
    WordLadder(string beginWord, string endWord, vector<string>& wordList)
        :m_sBeginWord(beginWord), m_sEndWord(endWord), m_words(wordList) {}
    virtual bool solve() override;

private:
    int ladderLength();
    bool canLink(string s1, string s2);

private:
    string m_sBeginWord, m_sEndWord;
    vector<string> m_words;
};