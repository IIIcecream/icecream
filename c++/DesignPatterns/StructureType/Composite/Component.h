#pragma once

/*!
*@brief        ���ģʽ
*@author       tangwei  2019/03/15  11:12
*@remarks      ��
*/
class IComponent
{
public:
    IComponent() {}
    virtual ~IComponent() {}

    virtual void add(IComponent *pItem) = 0;
    virtual void remove(IComponent *pItem) = 0;
    virtual void operation() = 0;
};

class Component : public IComponent
{
protected:
    virtual void add(IComponent *pItem) override;
    virtual void remove(IComponent *pItem) override;
    virtual void operation() override;
};