#pragma once

#include "IACM.h"
#include <string>
using std::string;

// 最长回文子序列
class LongestPalindromicSubsequence : public IACM
{
public:
    LongestPalindromicSubsequence(string s) : m_sStr(s) {}
    virtual bool solve() override;

private:
    int longestPalindromeSubseq(string s);

private:
    string m_sStr;
};