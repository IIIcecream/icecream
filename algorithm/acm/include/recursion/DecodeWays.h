#pragma once

#include "IACM.h"
#include <string>
using std::string;

// ½âÂë·½·¨
class DecodeWays : public IACM
{
public:
    DecodeWays(string s) : m_s(s) {}
    virtual bool solve() override;

private:
    int numDecodings(string s);

    int numDecodings1(string &s, int nIndex);

    bool canDecodeing(string &s, int nIndex, int n);

private:
    string m_s;
};