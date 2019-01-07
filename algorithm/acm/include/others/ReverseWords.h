#pragma once
#include <string>
#include "IACM.h"
using namespace std;

// ��ת�ַ�����ĵ���
class ReverseWords : public IACM
{
public:
    ReverseWords(string &s) : m_s(s) {}
    virtual bool solve() override;

private:
    void reverseWords(string &s);

private:
    string m_s;
};