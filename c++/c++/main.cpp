//////////////////////////////////////////////////////////////////////////
//  c++ 语法层面的一些编码尝试
//////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

class A
{
public:
    A() { m_nVal = 1; }
    virtual void print() { cout << m_nVal << endl; }
public:
    int m_nVal;
};

class B : public A
{
public:
    B() {}
};

class VB : virtual public A
{
    virtual void fff() {}
};

class C : public A
{
};

class VC : virtual public A
{
};

class D : public B , public C
{
};

class VD : virtual public VB, virtual public VC
{
};

int main()
{
    A a;
    cout << "Class A size is " << sizeof(a) << endl;

    B b;
    cout << "Class B size is " << sizeof(b) << endl;

    VB vb;
    cout << "Class VB size is " << sizeof(vb) << endl;

    C c;
    cout << "Class C size is " << sizeof(c) << endl;

    VC vc;
    cout << "Class VC size is " << sizeof(vc) << endl;

    D d;
    cout << "Class D size is " << sizeof(d) << endl;

    VD vd;
    cout << "Class VD size is " << sizeof(vd) << endl;
    int i = 1;
    system("pause");
    return 0;
}