#pragma once
#include "DDExportTest_global.h"

class  DDExportTestIntf
{
public:
    virtual ~DDExportTestIntf() {}
    virtual int* get() { return new int; }
    virtual int getVal() { return a; }

private:
    int c = 3;
    int a = 1;
    int b = 2;
};

