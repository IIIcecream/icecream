#pragma once

/*!
*@brief        �۲�Ŀ��
*@author       tangwei  2019/04/03  19:19
*@remarks      ��
*/

#include <list>
using namespace std;

class IObserver;
class ISubject
{
public:
    virtual ~ISubject() {};

    /*!
    *@brief        ע��۲���
    *@author       tangwei  2019/04/03  19:20
    *@param[in]    pObserver    �۲���
    *@param[out]   ��
    *@remarks      ��
    */
    virtual void attach(IObserver *pObserver) = 0;

    /*!
    *@brief        ע���۲���
    *@author       tangwei  2019/04/03  19:20
    *@param[in]    pObserver    �۲���
    *@param[out]   ��
    *@remarks      ��
    */
    virtual void detach(IObserver *pObserver) = 0;

    /*!
    *@brief        ֪ͨ
    *@author       tangwei  2019/04/03  19:20
    *@remarks      ��
    */
    virtual void notify() = 0;

    /*!
    *@brief        ��ȡ״̬
    *@author       tangwei  2019/04/03  19:32
    *@remarks      ��
    */
    virtual int getStatus() = 0;

    /*!
    *@brief        ����״̬
    *@author       tangwei  2019/04/03  19:32
    *@param[in]    status    ״̬
    *@remarks      ��
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