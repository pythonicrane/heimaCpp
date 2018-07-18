/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月18日17:15:15
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 类静态成员
* @Description  :
*
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

class Test {
public:
	int getC()
	{
		_c++;
		return _c;//4.非静态成员函数可以访问静态成员变量。
	}
	static int getSC()//3.静态成员函数不拥有this指针，故不能访问非静态成员，即只能访问静态成员。
	{
		return _c;
	}
private:
	int _a;
	int _b;
	static int _c;//2.不能在类内初始化，静态成员不知用对象内存。
};

int Test::_c = 0;//1.类外初始化，且不要加static，以免与一般静态变量或对象相混淆；

int main() {
	Test t;
	cout << t.getC() << endl;

	system("pause");
}
