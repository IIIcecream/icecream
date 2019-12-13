#pragma once
#include "IACM.h"
#include <string>
using std::string;

// ╩ьндвс╢╝
class PalindromicSubstrings : public IACM
{
public:
    PalindromicSubstrings(string s) : m_s(s) {}
    virtual bool solve() override;

private:
    int countSubstrings(string s);
    int expand(string& s, int i, int j);

private:
    string m_s;
};