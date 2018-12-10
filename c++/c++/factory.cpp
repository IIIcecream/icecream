//////////////////////////////////////////////////////////////////////////
//  ��������
//////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

enum CTYPE { COREA, COREB };
//////////////////////////////////////////////////////////////////////////
// �򵥹���
/*������Ƶ���Ҫȱ��֮ǰҲ�ᵽ��������Ҫ�����µĺ�����ʱ������Ҫ�޸Ĺ����ࡣ���Υ���˿��ŷ��ԭ��*/
namespace simpleFactory
{
    class SingleCore
    {
    public:
        virtual void Show() = 0;
    };
    //����A  
    class SingleCoreA : public SingleCore
    {
    public:
        void Show() { cout << "SingleCore A" << endl; }
    };
    //����B  
    class SingleCoreB : public SingleCore
    {
    public:
        void Show() { cout << "SingleCore B" << endl; }
    };
    //Ψһ�Ĺ������������������ͺŵĴ������ˣ����ڲ��ж�  
    class Factory
    {
    public:
        SingleCore * CreateSingleCore(enum CTYPE ctype)
        {
            if (ctype == COREA) //�����ڲ��ж�  
                return new SingleCoreA(); //������A  
            else if (ctype == COREB)
                return new SingleCoreB(); //������B  
            else
                return NULL;
        }
    };
}

//////////////////////////////////////////////////////////////////////////
// ��������
/*��������ģʽҲ��ȱ�㣬ÿ����һ�ֲ�Ʒ������Ҫ����һ������Ĺ����������ҹ�˾��չѸ�٣��Ƴ��˺ܶ��µĴ������ˣ���ô��Ҫ������Ӧ���¹���*/
namespace factoryFunc
{
    class SingleCore
    {
    public:
        virtual void Show() = 0;
    };
    //����A  
    class SingleCoreA : public SingleCore
    {
    public:
        void Show() { cout << "SingleCore A" << endl; }
    };
    //����B  
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
    //����A�˵Ĺ���  
    class FactoryA : public Factory
    {
    public:
        SingleCoreA * CreateSingleCore() { return new SingleCoreA; }
    };
    //����B�˵Ĺ���  
    class FactoryB : public Factory
    {
    public:
        SingleCoreB * CreateSingleCore() { return new SingleCoreB; }
    };
}

//////////////////////////////////////////////////////////////////////////
// ���󹤳�
/*���Ķ���Ϊ�ṩһ������һϵ����ػ��໥��������Ľӿڣ�������ָ�����Ǿ������
��ҹ�˾���ǿ�������������һ��ר����������A�ͺŵĵ��˶�˴�����������һ������ר����������B�ͺŵĵ��˶�˴�����*/
namespace abstractFactory
{
    //����  
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
    //���  
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
    //����  
    class CoreFactory
    {
    public:
        virtual SingleCore* CreateSingleCore() = 0;
        virtual MultiCore* CreateMultiCore() = 0;
    };
    //����A��ר����������A�ͺŵĴ�����  
    class FactoryA :public CoreFactory
    {
    public:
        SingleCore * CreateSingleCore() { return new SingleCoreA(); }
        MultiCore* CreateMultiCore() { return new MultiCoreA(); }
    };
    //����B��ר����������B�ͺŵĴ�����  
    class FactoryB : public CoreFactory
    {
    public:
        SingleCore * CreateSingleCore() { return new SingleCoreB(); }
        MultiCore* CreateMultiCore() { return new MultiCoreB(); }
    };
}
