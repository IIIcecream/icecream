#pragma once
#include "IACM.h"

// 猜数字大小
class GuessNumber : public IACM
{

};

// 猜数字大小 II
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