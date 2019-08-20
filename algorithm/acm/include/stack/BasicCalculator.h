#pragma once

#include "IACM.h"
#include <string>
using std::string;

// »ù±¾¼ÆËãÆ÷
class BasicCalculator : public IACM
{
public:
    BasicCalculator(string s) : m_sStr(s) {}
    virtual bool solve() override;

private:
    int calculate(string s);
    int calculate(string s, int pos[]);

    int calculate2(string s);
private:
    string m_sStr;
};