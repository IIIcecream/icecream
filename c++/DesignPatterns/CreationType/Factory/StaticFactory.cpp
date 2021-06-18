#include "StaticFactory.h"
#include "Product.h"

IProduct* StaticFactory::createProduct()
{
    switch (m_nType)
    {
    case 0:
        return new Product();
    case 1:
        return new Product1();
    case 2:
        return new Product2();
    case 3:
        return new Product3();
    default:
        return nullptr;
    }
}

