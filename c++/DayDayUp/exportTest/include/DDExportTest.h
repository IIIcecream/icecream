#pragma once

#include "DDExportTest_global.h"
#include "DDExportTestIntf.h"

extern "C"
{
    DDExportTest_EXPORT DDExportTestIntf * getDDExportTestIntf();
}

class DDExportTestImpl : public DDExportTestIntf
{
public:
    virtual ~DDExportTestImpl() {}

    virtual int getVal() { return a; }

private:
    int a = 1;
};
