#include "others/IntegerReplacement.h"
#include "ACMMathCommon.h"


bool IntegerReplacement::solve()
{
    return integerReplacement(m_n);
}

// LeetCode 397. Integer Replacement
int IntegerReplacement::integerReplacement(int n)
{
    if (n == INT_MAX) return 32;
    int nRes = 0;
    while (n != 1)
    {
        if (n % 2 == 0) n >>= 1;
        else
        {
            if (n == 3) nRes++, n = 1;// 对3特殊处理
            else if (n & 2) n += 1;
            else n -= 1;
        }
        nRes++;
    }
    return nRes;
}

