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

#define SAFE_DELETE(ptr) { if(ptr) delete(ptr); }
namespace ACM
{
    template <class T1, class T2>
    static int max(T1 a, T2 b)
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

    template <class T1, class T2>
    static int min(T1 a, T2 b)
    {
        return a < b ? a : b;
    }

    template <class T>
    static int abs(T a)
    {
        return a < 0 ? -a : a;
    }
}