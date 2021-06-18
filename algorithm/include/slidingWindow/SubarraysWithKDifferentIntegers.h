#pragma once
#include "IACM.h"
#include <vector>
using namespace std;

class SubarraysWithKDifferentIntegers : public IACM
{
public:
    SubarraysWithKDifferentIntegers(vector<int>& A, int K) : m_vecA(A), m_nK(K) { }
    virtual bool solve() override;

private:
    int subarraysWithKDistinct(vector<int>& A, int K);

private:
    vector<int> m_vecA;
    int m_nK;
};