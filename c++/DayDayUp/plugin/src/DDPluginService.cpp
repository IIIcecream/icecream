#include "DDPluginService.h"
#include <QString>
#include <QLibrary>
#include <QCoreApplication>
#include <QFile>

#include "DDExportTestIntf.h"
#include "DDExportTest.h"


#ifdef WIN32
typedef DDExportTestIntf *(__stdcall getDDExportTestIntf)();
#else
typedef DDExportTestIntf *(__attribute__((stdcall)) getDDExportTestIntf)();
#endif

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
    }

    load();
}

DDPluginService::~DDPluginService()
{
    if (m_pIntf) delete m_pIntf;
}

int DDPluginService::print()
{
    return m_pIntf ? m_pIntf->getVal() : -1;
}

void DDPluginService::load()
{
    if (m_pIntf != nullptr)
    {
        return;
    }

    //if (!m_qLibrary->isLoaded())
    {
#if defined(WIN64) || defined(_WIN64) || defined(__WIN64__)
        const char* strFuncName = "getDDExportTestIntf";
#else
        const char* strFuncName = "_getDDExportTestIntf@0";
#endif

        //auto func = m_qLibrary->resolve(strFuncName);
        //getDDExportTestIntf *pFunc = (getDDExportTestIntf *)func;
        //if (pFunc != nullptr)
        {
            //m_pIntf = pFunc();
            m_pIntf = new DDExportTestImpl;
        }
    }
}

