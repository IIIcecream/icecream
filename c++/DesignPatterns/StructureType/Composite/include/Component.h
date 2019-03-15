#pragma once

/*!
*@brief        组合模式
*@author       tangwei  2019/03/15  11:12
*@remarks      无
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