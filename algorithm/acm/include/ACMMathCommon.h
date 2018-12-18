#pragma once

/*!
*@brief        常用的一些公共函数
*@author       tangw-b  2018/12/05  10:52
*/

#include <vector>

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#ifndef INT_MIN
#define INT_MIN (-2147483647 - 1)
#endif
namespace ACM
{
    static int max(int a, int b)
    {
        return a > b ? a : b;
    }

    template <class T>
    static int max(std::vector<T> vec)
    {
        if (vec.empty()) return -1;

        int nMax = vec[0];
        for (size_t i = 1; i < vec.size(); ++i)
        {
            nMax = max(nMax, vec[i]);
        }
        return nMax;
    }

    static int min(int a, int b)
    {
        return a < b ? a : b;
    }

    static int abs(int a)
    {
        return a < 0 ? -a : a;
    }
}