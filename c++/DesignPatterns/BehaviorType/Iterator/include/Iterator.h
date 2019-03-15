#pragma once

/*!
*@brief        µü´úÆ÷Ä£Ê½
*@author       tangw-b  2019/03/14  17:33
*/

#include <string>
using namespace std;

template<class Item>
class Iterator
{
public:
    Iterator() {}
    virtual ~Iterator() {}
    virtual Item first() = 0;
    virtual Item next() = 0;
    virtual Item cur() = 0;
    virtual bool isDone() = 0;
};

template<class Item>
class Aggregate;

template<class Item>
class ConcreteIterator : public Iterator<Item>
{
public:
    ConcreteIterator(Aggregate<Item>* pAggregate);
    virtual ~ConcreteIterator();

    virtual Item first() override;
    virtual Item Next() override;
    virtual Item GetCur() override;
    virtual bool IsDone() override;

private:
    Aggregate *m_pAggregate;
    int m_nCur;
};