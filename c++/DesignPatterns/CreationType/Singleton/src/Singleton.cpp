#include "Singleton.h"

Singleton *m_pInstance = nullptr;

Singleton* Singleton::getInstanse()
{
    if (!m_pInstance)
    {
        m_pInstance = new Singleton;
    }
    return m_pInstance;
}

Singleton::~Singleton()
{
    if (m_pInstance) delete m_pInstance;
}
