#pragma once

class QLibrary;
class DDExportTestIntf;
class DDExportLoad
{
public:
    DDExportLoad();
    ~DDExportLoad();
    int print();

private:
    void load();

private:
    DDExportTestIntf * m_pIntf;
    QLibrary* m_qLibrary;
};
