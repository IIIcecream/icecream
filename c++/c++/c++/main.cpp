//////////////////////////////////////////////////////////////////////////
//  c++ 语法层面的一些编码尝试
//////////////////////////////////////////////////////////////////////////

#pragma warning(disable:4996)

#include <iostream>
#include <string.h>
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


class Base
{
public:
	Base() { a = 1; }
	void print() { cout << a; }

private:
	int a;
};

class Child : public Base
{
public:
	int a;
	Child() { a = 2; }
};

struct MyStruct
{
	int i;
	int *p;
};

class CDemo
{
public:
	CDemo() : str(nullptr), a(0) {}
	CDemo(const CDemo &o) { this->a = 333; this->str = o.str; }
	~CDemo() 
	{
		if (str)
		{
			delete str;
		}
	}

	int a;
	char *str;

	int c = 3;
	const int d = 4;
};

#include <vector>
void fff()
{
	CDemo d1, d2;
	d1.str = new char[32];
	d1.a = 111;
	d2.str = new char[32];
	d2.a = 222;
	strcpy(d1.str, "hahahah");
	strcpy(d2.str, "hahahah444");
	{
		vector<CDemo> vec;
		vec.resize(4);
		vec.push_back(d1);
		cout << "push 1\n";
		vec.push_back(d2);
		cout << "push 2\n";

		cout << vec[0].a << "  " << vec[1].a << endl;
	}
}

int main()
{
	fff();
    //A a;
    //cout << "Class A size is " << sizeof(a) << endl;

    //B b;
    //cout << "Class B size is " << sizeof(b) << endl;

    //VB vb;
    //cout << "Class VB size is " << sizeof(vb) << endl;

    //C c;
    //cout << "Class C size is " << sizeof(c) << endl;

    //VC vc;
    //cout << "Class VC size is " << sizeof(vc) << endl;

    //D d;
    //cout << "Class D size is " << sizeof(d) << endl;

    //VD vd;
    //cout << "Class VD size is " << sizeof(vd) << endl;
    //int i = 1;
    //system("pause");

	Child ccc;
	ccc.print();
	cout << ccc.a;

	void (Child::*pFunc)();
	pFunc = &Child::print;

	MyStruct m;
	int *p = &m.i;
	p[0] = 4;
	p[1] = 3;
	m.p = p;
	m.p[1] = 1;
	//m.p[0] = 2;

    return 0;
}