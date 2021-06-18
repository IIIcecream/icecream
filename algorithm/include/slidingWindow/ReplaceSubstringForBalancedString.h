#pragma once

#include "IACM.h"
#include <string>
using std::string;

// Ìæ»»×Ó´®µÃµ½Æ½ºâ×Ö·û´®
class ReplaceSubstringForBalancedString : public IACM
{
public:
    ReplaceSubstringForBalancedString(string s) : m_str(s) {}
    virtual bool solve() override;

private:
    int lengthOfLongestSubstring(string s);

private:
    string m_str;
};