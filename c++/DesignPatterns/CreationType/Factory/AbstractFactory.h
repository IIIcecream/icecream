#pragma once

/*!
*@brief        抽象工厂
*@author       tangwei  2019/03/19  11:18
*@remarks      无
*/

#include "IFactory.h"
class IProduct;
class AbstractFactory : public IFactory
{
public:
    virtual IProduct* createProduct() override;

private:
    virtual IProduct* createProductA() = 0;
    virtual IProduct* createProductB() = 0;
};

class AbstractFactoryA : public AbstractFactory
{
public:
    virtual IProduct* createProductA() override;
    virtual IProduct* createProductB() override;
};

class AbstractFactoryB : public AbstractFactory
{
public:
    virtual IProduct* createProductA();
    virtual IProduct* createProductB();
};