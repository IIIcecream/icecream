#pragma once
#include "IACM.h"

class GenerateParentheses : public IACM
{
public:
    GenerateParentheses(int n) :m_n(n) {}
    virtual bool solve() override;

private:
    int m_n;
};