#pragma once

#include "IACM.h"
#include <string>
using std::string;

// Í¬¹¹×Ö·û´®
class IsomorphicStrings : public IACM
{
public:
    IsomorphicStrings(string s, string t) : m_s(s), m_t(t) {}

    virtual bool solve() override;

private:
    bool isIsomorphic(string s, string t);

private:
    string m_s;
    string m_t;
};