/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月20日20:14:07
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : vptr分步初始化
* @Description  :
* 
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

class Parent {
public:
	Parent(int a)
	{
		cout << "Parent(int)..." << endl;
		this->a = a;
		print();//只会调用父类的print()
	}
	virtual void print()
	{
		cout << "Parent::print()...a= " << a << endl;
	}
private:
	int a;
};

class Child :public Parent{
public:
	Child(int a,int b):Parent(a)//1.在此处调用父类构造器，此时vptr还只是指向父类虚函数表。
	{
		//2.此时子类的虚函数表形成，vptr已经指向子类的虚函数表
		cout << "Child(int)..." << endl;
		this->b = b;
		print();//调用的是子类的函数
	}
	virtual void print()
	{
		cout << "Child::print()...b= " << b << endl;
	}
private:
	int b;
};

int main() {

	Parent *pp = new Child(10, 20);

	delete pp;

	system("pause");
}
