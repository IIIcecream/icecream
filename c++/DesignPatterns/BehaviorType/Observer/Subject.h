#pragma once

/*!
*@brief        观察目标
*@author       tangwei  2019/04/03  19:19
*@remarks      无
*/

#include <list>
using namespace std;

class IObserver;
class ISubject
{
public:
    virtual ~ISubject() {};

    /*!
    *@brief        注册观察者
    *@author       tangwei  2019/04/03  19:20
    *@param[in]    pObserver    观察者
    *@param[out]   无
    *@remarks      无
    */
    virtual void attach(IObserver *pObserver) = 0;

    /*!
    *@brief        注销观察者
    *@author       tangwei  2019/04/03  19:20
    *@param[in]    pObserver    观察者
    *@param[out]   无
    *@remarks      无
    */
    virtual void detach(IObserver *pObserver) = 0;

    /*!
    *@brief        通知
    *@author       tangwei  2019/04/03  19:20
    *@remarks      无
    */
    virtual void notify() = 0;

    /*!
    *@brief        获取状态
    *@author       tangwei  2019/04/03  19:32
    *@remarks      无
    */
    virtual int getStatus() = 0;

    /*!
    *@brief        设置状态
    *@author       tangwei  2019/04/03  19:32
    *@param[in]    status    状态
    *@remarks      无
    */
    virtual void setStatus(int status) = 0;
};

class Subject : public ISubject
{
public:
    Subject() { }
    ~Subject() { m_observers.clear(); }

    virtual void attach(IObserver *pObserver) override;

    virtual void detach(IObserver *pObserver) override;

    virtual void notify() override;

    virtual int getStatus() override { return m_nStatus; }

    virtual void setStatus(int status) override;

private:
    int m_nStatus = 0;
    list<IObserver *> m_observers;
};