#pragma once
#include "IACM.h"
#include <vector>
using std::vector;

// ¡„«Æ∂“ªª
class CoinChange : public IACM
{
public:
    CoinChange(vector<int>& coins, int amount) : m_coins(coins), m_nAmount(amount) {}
    virtual bool solve() override;

private:
    int coinChange(vector<int>& coins, int amount);

private:
    vector<int> m_coins;
    int m_nAmount;
};