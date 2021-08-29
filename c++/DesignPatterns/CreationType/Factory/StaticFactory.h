#pragma once

/*!
*@brief        简单工厂（静态工厂），但是不属于设计模式中的，作为后续工厂方法、抽象工厂的前置
*@author       tangwei  2019/03/19  11:10
*@remarks      无
*/

#include "IFactory.h"

class StaticFactory : public IFactory
{
public:
    virtual IProduct* createProduct() override;
    void setProductType(int n) { m_nType = n; }

private:
    int m_nType = 0;
};
