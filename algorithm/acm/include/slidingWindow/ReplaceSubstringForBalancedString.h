#pragma once

#include "IACM.h"
#include <string>
using std::string;

// �滻�Ӵ��õ�ƽ���ַ���
class ReplaceSubstringForBalancedString : public IACM
{
public:
    ReplaceSubstringForBalancedString(string s) : m_str(s) {}
    virtual bool solve() override;

private:
    int lengthOfLongestSubstring(string s);

private:
    string m_str;
};