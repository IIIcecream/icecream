#pragma once
#include "IACM.h"

// ³óÊý
class UglyNumber : public IACM
{
public:
    UglyNumber(int num) : m_n(num) {}
    virtual bool solve() override;

private:
    bool isUgly(int num);

private:
    int m_n;
};