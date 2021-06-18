#pragma once
#include "IACM.h"
#include <vector>
#include <string>
using namespace std;

// ×ÖÄ¸ÒìÎ»´Ê·Ö×é
class GroupAnagrams : public IACM
{
public:
    GroupAnagrams(vector<string>& strs) : m_strs(strs) {}
    virtual bool solve() override;

private:
    void groupAnagrams(vector<string>& strs);
private:
    vector<string> m_strs;
    vector<vector<string>> m_res;
};