#pragma once

/*!
*@brief        �۲���
*@author       tangwei  2019/04/03  19:14
*@remarks      ��
*/

#include <string>
using namespace std;

class IObserver
{
public:
    virtual ~IObserver() {}

    /*!
    *@brief        �۲��߼�����֮�����
    *@author       tangwei  2019/04/03  19:31
    *@remarks      ��
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