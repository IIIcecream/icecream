#include "Composite.h"
#include <iostream>
using namespace std;

Composite::~Composite()
{
    for (size_t i = 0; i < m_vec.size(); ++i)
    {
        delete m_vec[i];
    }
    m_vec.clear();
}

void Composite::add(IComponent *pItem)
{
    m_vec.push_back(pItem);
}

void Composite::remove(IComponent *pItem)
{
    for (auto itr = m_vec.begin(); itr != m_vec.end(); ++itr)
    {
        if (pItem == *itr)
        {
            m_vec.erase(itr);
            break;
        }
    }
}

void Composite::operation()
{
    cout << "Composite operation" << endl;
}

