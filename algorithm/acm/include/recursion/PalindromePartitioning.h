#pragma once
#include "IACM.h"
#include <string>
#include <vector>
using namespace std;


class PalindromePartitioning : public IACM
{
public:
    PalindromePartitioning(string s) : m_str(s) {}
    virtual bool solve() override;

private:
    vector<vector<string>> partition(string s);
    void doPartition(string s, int n, vector<vector<string>> &res, vector<string> &cur);
    bool isPalindrome(string &s);

private:
    string m_str;
};