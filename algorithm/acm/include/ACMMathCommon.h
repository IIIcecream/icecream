#pragma once

/*!
*@brief        ���õ�һЩ��������
*@author       tangw-b  2018/12/05  10:52
*/

namespace ACM
{
    static int max(int a, int b)
    {
        return a > b ? a : b;
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