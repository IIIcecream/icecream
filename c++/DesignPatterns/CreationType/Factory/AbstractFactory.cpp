#include "AbstractFactory.h"

IProduct* AbstractFactory::createProduct()
{
    IProduct *pA = createProductA();
    IProduct *pB = createProductB();

    // ������⣬���Ժ���
    return nullptr;
}

IProduct* AbstractFactoryA::createProductA()
{

}
