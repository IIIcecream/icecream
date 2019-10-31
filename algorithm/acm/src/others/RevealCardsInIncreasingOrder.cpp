#include "others/RevealCardsInIncreasingOrder.h"
#include <algorithm>

bool RevealCardsInIncreasingOrder::solve()
{
    return deckRevealedIncreasing(m_deck).size();
}

// LeetCode 950. Reveal Cards In Increasing Order
// 约瑟夫环，约瑟夫环的输出结果为有序数组，求原来的环的顺序
vector<int> RevealCardsInIncreasingOrder::deckRevealedIncreasing(vector<int>& deck)
{
    std::sort(deck.begin(), deck.end());
    int nSize = deck.size();

    vector<int> res(nSize, -1);

    int nIndex = 0, nIndexDeck = 0;
    while (nSize--)
    {
        res[nIndex] = deck[nIndexDeck++];
        if (!nSize) break;
        nIndex = findNextIndex(res, nIndex);
    }

    return res;
}

int RevealCardsInIncreasingOrder::findNextIndex(vector<int>& vec, int nBeginIndex)
{
    int nIndex = nBeginIndex;
    int n = 0;
    int nIndex1 = 0;
    while (n < 2)
    {
        nIndex = (nIndex + 1) % vec.size();
        if (n == 1 && nIndex == nBeginIndex)
        {
            return nIndex1;
        }

        if (vec[nIndex] == -1) nIndex1 = nIndex, n++;
    }
    return nIndex;
}
