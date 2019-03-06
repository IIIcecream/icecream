#pragma once

#include "DDExportTest_global.h"
#include "DDExportTestIntf.h"

//extern "C"
//{
//    DDExportTest_EXPORT DDExportTestIntf * __stdcall getDDExportTestIntf();
//}

class DDExportTest_EXPORT DDExportTestImpl : public DDExportTestIntf
{
public:
    DDExportTestImpl() {}
    virtual ~DDExportTestImpl() {}

protected:
    virtual int get0() { return int(5); }
    virtual int* get() { return new int(5); }
    virtual int getVal() { return b; }

private:
    int c = 4;
    int a = 3;
    int b = 1;
};
