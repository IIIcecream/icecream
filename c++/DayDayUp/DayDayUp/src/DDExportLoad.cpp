#include "DDExportLoad.h"
#include <QString>
#include <QLibrary>
#include <QCoreApplication>
#include <QFile>
#include "..\..\exportTest\include\DDExportTestIntf.h"

typedef DDExportTestIntf *GetExportTestIntfFunc();

DDExportLoad::DDExportLoad()
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

DDExportLoad::~DDExportLoad()
{

}

void DDExportLoad::load()
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

int DDExportLoad::print()
{
    return m_pIntf ? m_pIntf->getVal() : -1;
}

