#pragma once
#include "IACM.h"
#include <string>
using std::string;

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