#include "others/HandofStraights.h"
#include <unordered_map>

bool HandofStraights::solve()
{
    return true;
}

bool HandofStraights::isNStraightHand(vector<int>& hand, int W)
{
    int nLen = hand.size();
    if (nLen % W != 0) return false;

    unordered_map<int, int> hash;
    for (int n : hand) hash[n]++;

    for (size_t i = 0; i < hand.size(); ++i)
    {
        // hash[hand[n]]--
        for (int j = 0; j < W; ++j)
        {

        }
    }

    return true;
}

