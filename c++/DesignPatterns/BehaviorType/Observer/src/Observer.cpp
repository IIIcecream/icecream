#include "Observer.h"

#include <iostream>
#include "Subject.h"

Observer::Observer(string &sName, ISubject *pSub)
    : m_sName(sName), m_pSubject(pSub)
{
    m_pSubject->attach(this);
}

Observer::~Observer()
{
    m_pSubject->detach(this);
}

void Observer::update()
{
    cout << "I'm " << m_sName << ", cur state is " << m_pSubject->getStatus() <<endl;
}

