#pragma once
#include "IACM.h"
#include <string>
#include <map>
using namespace std;

// ×îÐ¡¸²¸Ç×Ó´®
class MinimumWindowSubstring : public IACM
{
public:
    MinimumWindowSubstring(string s, string t) : m_s(s), m_t(t) {}
    virtual bool solve() override;

private:
    string minWindow(string s, string t);
    string minWindowI(string s, string t);

private:
    string m_s, m_t;
};