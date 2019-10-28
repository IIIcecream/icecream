#pragma once
#include "IACM.h"

class TilingRectWithRewestSquares : public IACM
{
public:
    TilingRectWithRewestSquares(int n, int m) : m_n(n), m_m(m) {}
    virtual bool solve() override;

private:
    int tilingRectangle(int n, int m);

private:
    int m_n, m_m;
};