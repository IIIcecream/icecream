
class A  //��СΪ4
{
public:
	int fff() { return a; }

	int a;
};

class B :virtual public A  //��СΪ12������a,b��8�ֽڣ�������ָ��4
{
public:
	int b;
};

class C :virtual public A //��Bһ��12
{
public:
	int c;
};

class D :public B, public C //24,����a,b,c,d��16��B�������ָ��4��C�������ָ��
{
public:
	int d;
};
