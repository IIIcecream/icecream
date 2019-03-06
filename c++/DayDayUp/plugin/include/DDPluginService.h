#pragma once
#include "Plugin_global.h"

class DDExportTestIntf;
class QLibrary;
class Plugin_Export DDPluginService
{
public:
    DDPluginService();
    ~DDPluginService();

    int print();

private:
    void load();

private:
    DDExportTestIntf * m_pIntf;
    QLibrary* m_qLibrary;
};
