#include "others/BullsAndCows.h"
#include <unordered_map>
using std::unordered_map;

bool BullsAndCows::solve()
{
    getHint(m_sSecret, m_sGuess);
    return true;
}

// LeetCode 299. Bulls and Cows
string BullsAndCows::getHint(string secret, string guess)
{
    int nA = 0, nB = 0;

    int sum[10] = { 0 };
    for (char c : secret) sum[c - '0']++; // 记录secret中各字母出现的次数

    for (size_t i = 0; i < secret.size(); ++i)
    {
        if (secret[i] == guess[i])
        {
            nA++;
            int n = secret[i] - '0';
            if (sum[n] <= 0) nB--;
            sum[n]--;
        }
        else if(sum[guess[i] - '0'])
        {
            nB++;
            sum[guess[i] - '0']--;
        }
    }

    return std::to_string(nA) + "A" + std::to_string(nB) + "B";

    // 解法2
    int m[256] = { 0 };
    int bull = 0, cow = 0, len = secret.size();

    for (int i = 0; i < len; i++) {
        if (secret[i] == guess[i]) {
            bull++;
        }
        else {
            if (m[secret[i]]++ < 0) cow++;
            if (m[guess[i]]-- > 0) cow++;
        }
    }

    return std::to_string(bull) + "A" + std::to_string(cow) + "B";
}

