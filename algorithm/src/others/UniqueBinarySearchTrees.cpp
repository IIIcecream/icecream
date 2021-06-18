#include "others/UniqueBinarySearchTrees.h"
#include <vector>
using namespace std;

bool UniqueBinarySearchTrees::solve()
{
    numTrees(m_n);
    return true;
}

// Unique Binary Search Trees LeetCode T96
int UniqueBinarySearchTrees::numTrees(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1, dp[1] = 1;

    for (int i = 2; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            dp[i] += dp[j] * dp[i - j - 1];

    return dp[n];
}

