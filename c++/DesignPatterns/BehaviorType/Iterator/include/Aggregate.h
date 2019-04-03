#pragma once

#include <string>
#include <vector>
using namespace std;

template<class Item>
class Iterator;

template<class Item>
class Aggregate
{
public:
    virtual ~Aggregate() {}
    virtual size_t Count() = 0;
    virtual void Push(const Item& strValue) = 0;
    virtual Item getItem(const size_t nIndex) = 0;
    virtual Iterator* CreateIterator() = 0;
};

template<class Item>
class ConcreteAggregate : public Aggregate<Item>
{
public:
    ConcreteAggregate();
    ~ConcreteAggregate();


    virtual size_t Count() override;


    virtual void Push(const Item& strValue) override;

    virtual Item getItem(const size_t nIndex)override;

    virtual Iterator<Item>* CreateIterator() override;

private:
    vector<Item> m_vecItems;
    Iterator* m_pIterator;
};