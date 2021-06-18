#pragma once
#include "IACM.h"
#include <string>
using namespace std;

// 替换后的最长重复字符
class LongestRepeatingCharacterReplacement : public IACM
{
public:
    LongestRepeatingCharacterReplacement(string s, int k) : m_s(s), m_nK(k) {}
    virtual bool solve() override;

private:
    int characterReplacement(string s, int k);

private:
    string m_s;
    int m_nK;
};