#pragma once
#include "IACM.h"
#include <string>

using namespace std;
class LongestValidParentheses : public IACM
{
public:
    LongestValidParentheses(string s) : m_str(s) {}
    virtual bool solve() override;

private:
    int longestValidParentheses(string s);

private:
    string m_str;
};