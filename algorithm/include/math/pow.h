#pragma once
#include "IACM.h"

// Pow(x, n)
class CalcPow : public IACM
{
public:
    CalcPow(double x, int n) : m_dX(x), m_n(n) {}
    virtual bool solve() override;

private:
    double myPow(double x, int n);

private:
    double m_dX;
    int m_n;
};
