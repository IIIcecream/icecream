#include "others/MultiplyStrings.h"
#include <vector>
#include <algorithm>
using std::vector;

bool MultiplyStrings::solve()
{
    multiply(m_sNum1, m_sNum2);
    return true;
}

// LeetCode 43. Multiply Strings
string MultiplyStrings::multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0") return "0";

    vector<int> numInt1; numInt1.resize(num1.size());
    vector<int> numInt2; numInt2.resize(num2.size());

    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    for (size_t i = 0; i < num1.size(); ++i) numInt1[i] = num1[i] - '0';
    for (size_t i = 0; i < num2.size(); ++i) numInt2[i] = num2[i] - '0';

    // Result
    string sRes(num1.size() + num2.size(), '0');

    for (size_t i = 0; i < numInt1.size(); ++i)
    {
        for (size_t j = 0; j < numInt2.size(); ++j)
        {
            int nRes = numInt1[i] * numInt2[j];
            addNum(sRes, i + j, (nRes < 10 ? nRes : nRes % 10));
            if (nRes >= 10) addNum(sRes, i + j + 1, nRes / 10);
        }
    }
    if (sRes.back() == '0') sRes.pop_back();
    std::reverse(sRes.begin(), sRes.end());
    return sRes;
}

void MultiplyStrings::addNum(string &num, int nIndex, int nVal)
{
    int nSum = num[nIndex] - '0' + nVal;
    if (nSum < 10) num[nIndex] = nSum + '0';
    else
    {
        num[nIndex] = nSum - 10 + '0';
        addNum(num, nIndex + 1, 1);
    }
}

