#pragma once
#include "IACM.h"
#include <string>
#include <vector>

// À¨ºÅÉú³É
class GenerateParentheses : public IACM
{
public:
    GenerateParentheses(int n) :m_n(n) {}
    virtual bool solve() override;

private:
    void backtrack(std::string cur, int open, int close);

private:
    std::vector<std::string> m_res;
    int m_n;
};