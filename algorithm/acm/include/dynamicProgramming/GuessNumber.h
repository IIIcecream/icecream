#pragma once
#include "IACM.h"

// �����ִ�С
class GuessNumber : public IACM
{

};

// �����ִ�С II
class GuessNumberII : public IACM
{
public:
    GuessNumberII(int n) : m_n(n) {}
    virtual bool solve() override;

private:
    int getMoneyAmount(int n);

private:
    int m_n;
};