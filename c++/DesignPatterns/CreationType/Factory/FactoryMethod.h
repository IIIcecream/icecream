#pragma once
#include "Product.h"
#include "IFactory.h"

/*!
*@brief        工厂方法
*@author       tangwei  2019/03/19  11:09
*@param[in]    无
*@param[out]   无
*@remarks      无
*/

class FactoryMethod : public IFactory
{
public:
    virtual ~FactoryMethod() {}

    virtual IProduct* createProduct() override;
};

class FactoryA : public FactoryMethod
{
public:
    virtual IProduct* createProduct() override;
};

class FactoryB : public FactoryMethod
{
public:
    virtual IProduct* createProduct() override;
};

class FactoryC : public FactoryMethod
{
public:
    virtual IProduct* createProduct() override;
};

