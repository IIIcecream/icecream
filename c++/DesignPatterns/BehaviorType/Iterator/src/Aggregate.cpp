#include "Aggregate.h"
#include "Iterator.h"

template<class Item>
ConcreteAggregate<Item>::ConcreteAggregate()
    : m_pIterator(nullptr)
{
    m_vecItems.clear();
}

template<class Item>
ConcreteAggregate<Item>::~ConcreteAggregate()
{
    if (m_pIterator) delete m_pIterator;
}

template<class Item>
size_t ConcreteAggregate<Item>::Count()
{
    return m_vecItems.size();
}

template<class Item>
void ConcreteAggregate<Item>::Push(const Item& strValue)
{
    m_vecItems.push_back(strValue);
}

template<class Item>
Item ConcreteAggregate<Item>::getItem(const size_t nIndex)
{
    if (nIndex < 0 || nIndex >= m_vecItems.size())
        return Item();

    return m_vecItems[nIndex];
}

template<class Item>
Iterator<Item>* ConcreteAggregate<Item>::CreateIterator()
{
    return new ConcreteIterator<Item>(this);
}
