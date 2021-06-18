#pragma once

#include "IACM.h"
#include <vector>
using namespace std;

// ����
class UglyNumber : public IACM
{
public:
    UglyNumber(int num) : m_n(num) {}
    virtual bool solve() override;

private:
    bool isUgly(int num);

private:
    int m_n;
};

// ����II
class UglyNumberII : public IACM
{
public:
    UglyNumberII(int num) : m_n(num) {}
    virtual bool solve() override;

private:
    int nthUglyNumber(int n);

private:
    int m_n;
};

// ��������
class SuperUglyNumber : public IACM
{
public:
    SuperUglyNumber(int n, vector<int>& primes) : m_n(n), m_primes(primes) {}
    virtual bool solve() override;

private:
    int nthSuperUglyNumber(int n, vector<int>& primes);

private:
    int m_n;
    vector<int> m_primes;
};