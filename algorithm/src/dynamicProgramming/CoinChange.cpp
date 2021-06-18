#include "dynamicProgramming/CoinChange.h"

bool CoinChange::solve()
{
    return coinChange(m_coins, m_nAmount);
}

// LeetCode 322. Coin Change
int CoinChange::coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1); // 初始化为amount+1同初始化为maxInt等效

    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
    {
        for (size_t j = 0; j < coins.size(); ++j)
        {
            if (coins[j] <= i)
            {
                int n = dp[i - coins[j]] + 1;
                if (dp[i] > n) dp[i] = n;
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

