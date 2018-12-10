//////////////////////////////////////////////////////////////////////////
//  工厂方法
//////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

enum CTYPE { COREA, COREB };
//////////////////////////////////////////////////////////////////////////
// 简单工厂
/*这样设计的主要缺点之前也提到过，就是要增加新的核类型时，就需要修改工厂类。这就违反了开放封闭原则*/
namespace simpleFactory
{
    class SingleCore
    {
    public:
        virtual void Show() = 0;
    };
    //单核A  
    class SingleCoreA : public SingleCore
    {
    public:
        void Show() { cout << "SingleCore A" << endl; }
    };
    //单核B  
    class SingleCoreB : public SingleCore
    {
    public:
        void Show() { cout << "SingleCore B" << endl; }
    };
    //唯一的工厂，可以生产两种型号的处理器核，在内部判断  
    class Factory
    {
    public:
        SingleCore * CreateSingleCore(enum CTYPE ctype)
        {
            if (ctype == COREA) //工厂内部判断  
                return new SingleCoreA(); //生产核A  
            else if (ctype == COREB)
                return new SingleCoreB(); //生产核B  
            else
                return NULL;
        }
    };
}

//////////////////////////////////////////////////////////////////////////
// 工厂方法
/*工厂方法模式也有缺点，每增加一种产品，就需要增加一个对象的工厂。如果这家公司发展迅速，推出了很多新的处理器核，那么就要开设相应的新工厂*/
namespace factoryFunc
{
    class SingleCore
    {
    public:
        virtual void Show() = 0;
    };
    //单核A  
    class SingleCoreA : public SingleCore
    {
    public:
        void Show() { cout << "SingleCore A" << endl; }
    };
    //单核B  
    class SingleCoreB : public SingleCore
    {
    public:
        void Show() { cout << "SingleCore B" << endl; }
    };
    class Factory
    {
    public:
        virtual SingleCore* CreateSingleCore() = 0;
    };
    //生产A核的工厂  
    class FactoryA : public Factory
    {
    public:
        SingleCoreA * CreateSingleCore() { return new SingleCoreA; }
    };
    //生产B核的工厂  
    class FactoryB : public Factory
    {
    public:
        SingleCoreB * CreateSingleCore() { return new SingleCoreB; }
    };
}

//////////////////////////////////////////////////////////////////////////
// 抽象工厂
/*它的定义为提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类
这家公司还是开设两个工厂，一个专门用来生产A型号的单核多核处理器，而另一个工厂专门用来生产B型号的单核多核处理器*/
namespace abstractFactory
{
    //单核  
    class SingleCore
    {
    public:
        virtual void Show() = 0;
    };
    class SingleCoreA : public SingleCore
    {
    public:
        void Show() { cout << "Single Core A" << endl; }
    };
    class SingleCoreB :public SingleCore
    {
    public:
        void Show() { cout << "Single Core B" << endl; }
    };
    //多核  
    class MultiCore
    {
    public:
        virtual void Show() = 0;
    };
    class MultiCoreA : public MultiCore
    {
    public:
        void Show() { cout << "Multi Core A" << endl; }

    };
    class MultiCoreB : public MultiCore
    {
    public:
        void Show() { cout << "Multi Core B" << endl; }
    };
    //工厂  
    class CoreFactory
    {
    public:
        virtual SingleCore* CreateSingleCore() = 0;
        virtual MultiCore* CreateMultiCore() = 0;
    };
    //工厂A，专门用来生产A型号的处理器  
    class FactoryA :public CoreFactory
    {
    public:
        SingleCore * CreateSingleCore() { return new SingleCoreA(); }
        MultiCore* CreateMultiCore() { return new MultiCoreA(); }
    };
    //工厂B，专门用来生产B型号的处理器  
    class FactoryB : public CoreFactory
    {
    public:
        SingleCore * CreateSingleCore() { return new SingleCoreB(); }
        MultiCore* CreateMultiCore() { return new MultiCoreB(); }
    };
}
