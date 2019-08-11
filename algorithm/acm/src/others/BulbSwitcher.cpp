#include "others/BulbSwitcher.h"
#include <cmath>

bool BulbSwitcher::solve()
{
    return bulbSwitch(m_n);
}

// LeetCode 319. Bulb Switcher
// ֻ��ĳ������ȫƽ��ʱ�������Ż����������ƲŻ�򿪡����ͳ��<=n����ȫƽ��������
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

/*!
*@brief        ��ȡn����������
*@author       tangw   2019/08/09  19:48
*/
int BulbSwitcher::getFactorNum(int n)
{
    int nSqrt = sqrt(n);
    if (nSqrt * nSqrt == n) return 1;

    int nRes = 0;
    for (int i = 0; i <= nSqrt; ++i)
    {
        if (n % i == 0) nRes += 2;
    }
    return nRes;
}

