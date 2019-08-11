#pragma once

#include "IACM.h"

// µÆÅÝ¿ª¹Ø
class BulbSwitcher : public IACM
{
public:
    BulbSwitcher(int n) : m_n(n) {}

    virtual bool solve() override;

private:
    int bulbSwitch(int n);
    int bulbSwitch2(int n);
    int bulbSwitch3(int n);

    int getFactorNum(int n);

private:
    int m_n;
};