#include "Subject.h"
#include "Observer.h"
#include <iostream>

void Subject::attach(IObserver *pObserver)
{
    if(find(m_observers.begin(), m_observers.end(), pObserver) == m_observers.end())
        m_observers.push_back(pObserver);
}

void Subject::detach(IObserver *pObserver)
{
    m_observers.remove(pObserver);
}

void Subject::notify()
{
    for (auto itr = m_observers.begin(); itr != m_observers.end(); ++itr)
    {
        (*itr)->update();
    }
}

// 可以自动调用通知，也可外部手动调用
void Subject::setStatus(int status)
{
    cout << "cur status " << m_nStatus << " change to " << status << endl;
    m_nStatus = status;
    notify();
}
