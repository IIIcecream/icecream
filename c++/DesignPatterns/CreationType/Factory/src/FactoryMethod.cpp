#include "FactoryMethod.h"

IProduct* FactoryMethod::createProduct()
{
    return new Product();
}

IProduct* FactoryA::createProduct()
{
    return new Product1();
}

IProduct* FactoryB::createProduct()
{
    return new Product2();
}

IProduct* FactoryC::createProduct()
{
    return new Product3();
}
