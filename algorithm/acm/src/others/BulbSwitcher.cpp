#include "others/BulbSwitcher.h"
#include <cmath>

bool BulbSwitcher::solve()
{
    return bulbSwitch(m_n);
}

// LeetCode 319. Bulb Switcher
// 只有某数的完全平方时，因数才会是奇数，灯才会打开。因此统计<=n的完全平方数即可
int BulbSwitcher::bulbSwitch(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        int m = i * i;
        if (m == n) return i;
        else if (m > n) return i - 1;
    }
    return 0;
}

int BulbSwitcher::bulbSwitch2(int n)
{
    return sqrt(n);
}

int BulbSwitcher::bulbSwitch3(int n)
{
    if (!n) return 0;
    int res = 0, start = 1, i = 3;
    while (start <= n)
    {
        res++;
        start += i;
        i += 2;
    }
    return res;
}
