#pragma once
#include "IACM.h"
#include <string>

// 不同的子序列 https://leetcode-cn.com/problems/distinct-subsequences/
class DistinctSubsequnces : public IACM
{
public:
    DistinctSubsequnces(const std::string &s, const std::string &t) : m_sS(s), m_sT(t), m_nSLen(s.length()), m_nTLen(t.length()) {}
    virtual bool solve() override;

private:
    std::string m_sS, m_sT;
    int m_nRes = 0, m_nSLen, m_nTLen;
};