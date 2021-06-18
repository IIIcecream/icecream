#include "others/FactorialTrailingZeroes.h"

bool FactorialTrailingZeroes::solve()
{
    return trailingZeroes(m_n);
}

// LeetCode 172. Factorial Trailing Zeroes
int FactorialTrailingZeroes::trailingZeroes(int n)
{
    int nRes = 0;
    while (n >= 5)
    {
        n /= 5;
        nRes += n;
    }
    return nRes;
}

