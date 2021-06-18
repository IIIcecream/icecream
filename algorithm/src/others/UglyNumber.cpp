#include "others/UglyNumber.h"

#include <vector>
#include "ACMMathCommon.h"

bool UglyNumber::solve()
{
    return isUgly(m_n);
}

// LeetCode 263. Ugly Number
bool UglyNumber::isUgly(int num)
{
    if (num <= 0) return false;
    
    while (num > 1)
    {
        if (num % 2 == 0) num /= 2;
        else if (num % 3 == 0) num /= 3;
        else if (num % 5 == 0) num /= 5;
        else return false;
    }
    return num == 1;
}

bool UglyNumberII::solve()
{
    return nthUglyNumber(m_n);
}

// LeetCode 264. Ugly NumberII
int UglyNumberII::nthUglyNumber(int n)
{
    if (n < 7) return n;

    std::vector<int> uglyNumbers(n, 1);
    int i = 1, i2 = 0, i3 = 0, i5 = 0;

    while (i < n)
    {
        int nUgly = ACM::min(ACM::min(uglyNumbers[i2] * 2, uglyNumbers[i3] * 3), uglyNumbers[i5] * 5);
        uglyNumbers[i++] = nUgly;

        if (nUgly == uglyNumbers[i2] * 2) ++i2;
        if (nUgly == uglyNumbers[i3] * 3) ++i3;
        if (nUgly == uglyNumbers[i5] * 5) ++i5;
    }

    return uglyNumbers.back();
}

bool SuperUglyNumber::solve()
{
    return nthSuperUglyNumber(m_n, m_primes);
}


// LeetCode 313. Ugly NumberII
int SuperUglyNumber::nthSuperUglyNumber(int n, vector<int>& primes)
{
    vector<int> pointers(primes.size(), 0);

    vector<int> res(n, 1);
    int nIndex = 1;

    while (nIndex < n)
    {
        int nMinUgly = res[pointers[0]] * primes[0];
        int nMinIndex = 0;
        for (size_t i = 1; i < primes.size(); ++i)
        {
            int nTemp = primes[i] * res[pointers[i]];
            if (nMinUgly > nTemp) nMinUgly = nTemp;
        }

        res[nIndex++] = nMinUgly;

        for (size_t i = 0; i < primes.size(); ++i)
        {
            if (nMinUgly == primes[i] * res[pointers[i]]) pointers[i]++;
        }
    }

    return res.back();
}
