#pragma once

/*!
*@brief        观察者
*@author       tangwei  2019/04/03  19:14
*@remarks      无
*/

#include <string>
using namespace std;

class IObserver
{
public:
    virtual ~IObserver() {}

    /*!
    *@brief        观察者监听到之后更新
    *@author       tangwei  2019/04/03  19:31
    *@remarks      无
    */
    virtual void update() = 0;
};

class ISubject;
class Observer : public IObserver
{
public:
    Observer(string &sName, ISubject *pSub);
    ~Observer();

    virtual void update() override;

private:
    string m_sName;
    ISubject *m_pSubject;
};
