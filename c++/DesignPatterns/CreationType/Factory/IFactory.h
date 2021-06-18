#pragma once

class IProduct;
class IFactory
{
public:
    virtual ~IFactory() {}
    virtual IProduct* createProduct() = 0;
};
