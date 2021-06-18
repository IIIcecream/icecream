#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// Ò»ÊÖË³×Ó
class HandofStraights : public IACM
{
public:
    HandofStraights(vector<int>& hand, int W) : m_hand(hand), m_nW(W) {}
    virtual bool solve() override;

private:
    bool isNStraightHand(vector<int>& hand, int W);

private:
    vector<int> m_hand;
    int m_nW;
};