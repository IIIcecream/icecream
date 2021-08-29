#include "Iterator.h"
#include "Aggregate.h"

template<class Item>
ConcreteIterator<Item>::ConcreteIterator(Aggregate<Item>* pAggregate)
    : m_pAggregate(pAggregate), m_nCur(0)
{

}

template<class Item>
ConcreteIterator<Item>::~ConcreteIterator()
{
    m_pAggregate = nullptr;
}

template<class Item>
Item ConcreteIterator<Item>::first()
{
    return m_pAggregate->getItem(0);
}

template<class Item>
Item ConcreteIterator<Item>::Next()
{
    return m_pAggregate->getItem(++m_nCur);
}

template<class Item>
Item ConcreteIterator<Item>::GetCur()
{
    return m_pAggregate->getItem(m_nCur);
}

template<class Item>
bool ConcreteIterator<Item>::IsDone()
{
    return m_nCur >= m_pAggregate->Count();
}
