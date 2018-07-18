/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月18日20:31:29
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 类构造函数的使用
* @Description  :
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

class Test {
public:
	Test():_x(0),_y(0)//无参构造
	{
		cout << "Test()..." << &(*this) << endl;
	}
	Test(int x, int y)//有参构造
	{
		_x = x;
		_y = y;
		cout << "Test(int,int)..." << _x << " " << _y << &(*this) << endl;
	}
	Test(const Test& t)//拷贝构造
	{
		_x = t._x;
		_y = t._y;
		cout << "Test(const Test&)..." << _x << " " << _y << &(*this) << endl;
	}
	void operator=(const Test& t)
	{
		_x = t._x;
		_y = t._y;
		cout << "operator=..." << _x << " " << _y << &(*this) << endl;
	}
	~Test()//析构
	{
		cout << "~Test()..." << _x << " " << _y << &(*this) << endl;
	}

	void printT()
	{
		cout << "printT(): " << "x= " << _x << ",y= " << _y << &(*this) << endl;
	}

private:
	int _x;
	int _y;
};

//场景1
void test1()
{
	Test t1(10, 20);
	Test t2(t1);
	Test t3 = t1;//跟Test t2(t1)一样，不会调用operator=;
}

//场景2
void test2()
{
	Test t1(10, 20);
	Test t2;
	t2 = t1;
}

//场景3
void func(Test t)//编译器会构造临时变量Test t = t1,调用的构造函数是Test::Test(Test&);
{
	cout << "func begin..." << endl;
	t.printT();
	cout << "func end..." << endl;
}

void test3()
{
	cout << "test3 begin..." << endl;
	Test t1(10, 20);
	func(t1);
	cout << "test3 endl..." << endl;
}

//场景4
Test func2()
{
	cout << "func2 begin..." << endl;
	Test t(10, 20);
	t.printT();
	cout << "func2 end..." << endl;
	return t;//返回时，编译器会构造临时变量Test temp1 = t,调用的构造函数是Test::Test(Test&);然后析构t;
}

void test4()
{
	cout << "test4 begin..." << endl;
	func2();//会创建临时对象temp2，调用拷贝构造函数Test temp2(temp1)，因为未保存临时对象，该临时对象会立即析构；
	cout << "test4 endl..." << endl;
}


void test5()
{
	cout << "test5 begin..." << endl;
	Test t1 = func2();//调用拷贝还是Test t1(temp1)；
	cout << "test5 endl..." << endl;
}

void test6()
{
	cout << "test6 begin..." << endl;
	Test t1;
	t1= func2();
	cout << "test6 endl..." << endl;
}



int main()
{
	test5();

	system("PAUSE");
}

