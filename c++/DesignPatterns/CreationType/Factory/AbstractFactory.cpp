#include "AbstractFactory.h"

IProduct* AbstractFactory::createProduct()
{
    IProduct *pA = createProductA();
    IProduct *pB = createProductB();

    // 这里表意，可以忽视
    return nullptr;
}

//IProduct* AbstractFactoryA::createProductA()
//{
//    return nullptr;
//}
//
//IProduct* AbstractFactoryA::createProductB()
//{
//    
//}
