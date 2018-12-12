#pragma once
#include "IACM.h"
#include <vector>

// ÂòÂô¹ÉÆ± dp
class BuySellSrock : public IACM
{
public:
    BuySellSrock(std::vector<int>& prices) : m_prices(prices) {}
    virtual bool solve() override;

private:
    int question1();
    int question2();
    int question3();

private:
    std::vector<int> m_prices;
};