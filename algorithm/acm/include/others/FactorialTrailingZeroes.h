#pragma once
#include "IACM.h"

// �׳˺����
class FactorialTrailingZeroes : public IACM
{
public:
    FactorialTrailingZeroes(int n) : m_n(n) {}
    virtual bool solve() override;

private:
    int trailingZeroes(int n);

private:
    int m_n;
};