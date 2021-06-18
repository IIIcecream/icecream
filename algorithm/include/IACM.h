#pragma once

class IACM
{
public:
    virtual ~IACM() {}
    virtual bool solve() = 0;
};