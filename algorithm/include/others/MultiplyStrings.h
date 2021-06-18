#pragma once

#include "IACM.h"
#include <string>
using std::string;

// ×Ö·û´®Ïà³Ë
class MultiplyStrings : public IACM
{
public:
    MultiplyStrings(string num1, string num2) : m_sNum1(num1), m_sNum2(num2) {}
    virtual bool solve() override;

private:
    string multiply(string num1, string num2);
    void addNum(string &num, int nIndex, int nVal);

private:
    string m_sNum1, m_sNum2;
};