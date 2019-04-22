#include "DDExportTest.h"

DDExportTestIntf * getDDExportTestIntf()
{
    return new DDExportTestImpl();
}
