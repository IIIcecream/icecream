#include "DDPluginService.h"
#include <QString>
#include <QLibrary>
#include <QCoreApplication>
#include <QFile>

#include "DDExportTest.h"

typedef DDExportTestIntf *GetExportTestIntfFunc();

DDPluginService::DDPluginService()
    : m_pIntf(nullptr)
{
    QString strPath = qApp->applicationDirPath();
#ifdef NDEBUG
    strPath = strPath + "/exportTest.dll";
#else
    strPath = strPath + "/exportTestd.dll";
#endif

    QFile oFile(strPath);
    if (oFile.exists())
    {
        m_qLibrary = new QLibrary(strPath);
    }
    else
    {
        m_qLibrary = nullptr;
        return;
    }

    load();
}

DDPluginService::~DDPluginService()
{
    if (m_pIntf) delete m_pIntf;
}

int DDPluginService::print()
{
    int a = m_pIntf->getaaa();
    return m_pIntf ? m_pIntf->getVal() : a;
}

void DDPluginService::load()
{
    if (m_pIntf != nullptr)
    {
        return;
    }

    if (!m_qLibrary->isLoaded())
    {
        const char* strFuncName = "getDDExportTestIntf";
        GetExportTestIntfFunc *pFunc = (GetExportTestIntfFunc *)m_qLibrary->resolve(strFuncName);

        if (pFunc != nullptr)
        {
            m_pIntf = pFunc();
        }
    }
}

