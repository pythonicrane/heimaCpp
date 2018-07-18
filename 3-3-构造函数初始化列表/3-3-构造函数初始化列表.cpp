/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月18日15:44:02
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 类构造函数初始化列表
* @Description  :
* 1.R(31)
* 2.R(35)
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

class A {
public:
	A(int a)
	{
		cout << "A(int)..." << endl;
		_a = a;
	}
	~A()
	{
		cout << "~A()..." << endl;
	}
private:
	int _a;
};

class B {
public:
	B(A& a1, A& a2, int b) :_a1(a1), _a2(a2), _b(b)//会发生隐身转换调用A（int)
	{
		cout << "B(A&,A&,int)..." << endl;
	}
	B(int a1, int a2, int b) :_a1(a1), _a2(a2), _b(b)//初始化顺序跟参数列表无关，而是跟data member顺序有关
	{
		cout << "B(int,int,int)..." << endl;
	}
private:
	int _b;
	A _a1;//初始化顺序是_a1,_a2;
	A _a2;
};

void test1()
{
	A a1(10), a2(100);
	B(a1, a2, 1000);
}


int main() 
{

	test1();

	system("pause");
}
