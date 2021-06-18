#pragma once
#include "IACM.h"
#include <string>
#include <map>
#include <vector>
using namespace std;

class LetterCombinationsOfPhoneNumbers : public IACM
{
public:
    LetterCombinationsOfPhoneNumbers(string &str) : m_strNums(str) { initMap(); }
    virtual bool solve() override;

private:
    void doCombination(string &digits, int cur, string s);
    void initMap();

private:
    string m_strNums;
    map<int, vector<char>> m_map;
    vector<string> m_res;
};