#pragma once
#include "IACM.h"

// ÕûÊıÌæ»»
class IntegerReplacement : public IACM
{
public:
    IntegerReplacement(int n) : m_n(n) {}
    virtual bool solve() override;

private:
    int integerReplacement(int n);

private:
    int m_n;
};