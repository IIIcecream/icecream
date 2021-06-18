#pragma once
#include "IACM.h"
#include <vector>
using std::vector;

// ∞¥µ›‘ˆÀ≥–Úœ‘ æø®≈∆
class RevealCardsInIncreasingOrder : public IACM
{
public:
    RevealCardsInIncreasingOrder(vector<int>& deck) : m_deck(deck) {}
    virtual bool solve() override;

private:
    vector<int> deckRevealedIncreasing(vector<int>& deck);
    int findNextIndex(vector<int>& vec, int nBeginIndex);

private:
    vector<int> m_deck;
};