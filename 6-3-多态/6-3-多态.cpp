/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月20日15:56:09
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 多态
* @Description  :
* 1.多态发生条件：继承，虚函数覆盖，基类指针或引用
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

class A{
public:
	A()
	{
		a = 'a';
	}
	void print()
	{
		cout << a << endl;
	}
	virtual void vprint()
	{
		cout << a << endl;
	}
	char a;
};

class B:public A{
public:
	B()
	{
		b = 'b';
	}
	void print()//此函数存在两个版本，一个是B的版本，一个是继承自A的版本
	{
		cout << b << endl;
	}

	virtual void vprint()
	{
		cout << b << endl;//此处有两个版本，但A的版本被覆盖,会发生多态，A的可以通过命名空间调用
	}
	char b;
};

class C :public A {
public:
	C()
	{
		c = 'c';
	}
	virtual void print()
	{
		cout << c << endl;
	}
	void vprint(int i)//此处发生重载，不会继承A的vprint!!!!!!!!
	{
		cout << c << "+" << i << endl;
	}
	char c;
};


void printT(A& t)
{
	t.print();
}

void vprintT(A& t)
{
	t.vprint();
}

int main() {

	A ta;
	B tb;
	C tc;


	printT(ta);
	tb.A::print();
	printT(tb);//1.等同上一句，没有虚函数，不触发多态
	vprintT(tb);//2.满足多态三要素，触发多态
	tb.A::vprint();

	
	tc.vprint(10);//3.调用重载版本
	//tc.vprint();//4.不能直接调用vprint()
	tc.A::vprint();
	vprintT(tc);//5.但可以间接通过vptr调用！！！！！！！！！
	printT(tc);//6.无法触发多态，在基类中，print()不是虚函数，仅在派生类中指定了虚函数，只能在其后面继承发生多态！！！！！！！！
	
	cout << "--------------" << endl;


	system("pause");
}
