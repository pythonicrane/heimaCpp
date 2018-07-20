/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月20日14:36:18
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 类的访问权限与继承关系
* @Description  :
*
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

class Parent {
public:
	int pub;//在类的内部和外部都可以访问
protected:
	int pro;//在类的内部可以访问，在外部不可以访问
private:
	int pri;//在类的内部可以访问，在类的外部不可以访问
};

//公有继承：
//基类公有成员变成公有成员，类内可以访问，类外可以能访问
//基类保护成员变成保护成员，类内可以访问，类外不可以能访问
//基类私有成员被隐藏,类外和类内都不可以访问
class Child1 :public Parent {
public:
	void func()
	{
		cout << pub << endl;
		cout << pro << endl;
		//cout << pri << endl;
	}
};

//保护继承：
//基类公有成员变成保护成员，类内可以访问，类外不可以能访问
//基类保护成员变成保护成员，类内可以访问，类外不可以能访问
//基类私有成员被隐藏,类外和类内都不可以访问
class Child2 :protected Parent {
public:
	void func()
	{
		cout << pub << endl;
		cout << pro << endl;
		//cout << pri << endl;
	}
};

//私有继承：
//基类公有成员变成私有成员，类内可以访问，类外不可以能访问
//基类保护成员变成私有成员，类内可以访问，类外不可以能访问
//基类私有成员被隐藏,类外和类内都不可以访问
class Child3 :private Parent {
public:
	void func()
	{
		cout << pub << endl;
		cout << pro << endl;
		//cout << pri << endl;
	}
};

int main() {

	Parent p1;
	p1.pub;


	

	system("pause");
}