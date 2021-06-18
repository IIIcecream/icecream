#pragma once
#include "IACM.h"
#include <string>
using std::string;

// 反转每对括号间的子串
class ReverseSubstringsBetweenParentheses : public IACM
{
public:
    ReverseSubstringsBetweenParentheses(string s) : m_str(s) {}
    virtual bool solve() override;

private:
    string reverseParentheses(string& s);

private:
    string m_str;
};