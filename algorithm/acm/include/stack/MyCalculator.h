#pragma once

#include "IACM.h"
#include <string>

using namespace std;

// ¼ÆËãÆ÷
class MyCalculator : public IACM
{
public:
    MyCalculator(string s) : m_str(s) {}
    ~MyCalculator();

    virtual bool solve() override;

private:
    int calculate(string s);
    bool bNum(char c);
    bool bSymbol(char c);

private:
    string m_str;
};
