#include "others/UglyNumber.h"

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

