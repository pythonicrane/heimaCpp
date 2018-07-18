/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月18日16:14:40
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 类内部成员初始化
* @Description  :
-------------------------------------------------------------**/
#include <iostream>

using namespace std;

class Test
{
public:
	Test() : y(1), r(y), d(3) {} //对于常量型成员变量和引用型成员变量，必须通过参数化列表的方式进行初始化。
	~Test() {}

	int y;      //普通变量成员
	int &r;     //引用成员变量
	const int d;    //常量成员变量
	static int c;   //静态成员变量
	static const int x = 2;   //静态常量整型成员变量
	static const int xx;        //静态常量整型成员变量声明
	static const double z;  //静态常量非整型成员变量声明
	//static const float zz = 6.6;    //静态常量非整型成员变量?
	static const char ch = 'A';
};


const int Test::xx = 4; //静态常量整型成员变量定义
const double Test::z = 5.1; ////静态常量非整型成员变量定义
int Test::c = 2;

int main(void)
{
	cout << Test::x << endl;

	return 0;
}
/*
1.C++98,通常情况下，不应该在类内部初始化成员！！无论是否为静态、是否为常量、是否为int等！！
统统不建议在类内初始化，因为本质上类只是声明，并不分配内存，而初始化会分配内存，类内初始化会
将两个过程混在一起！

2.C++11标准，非静态成员也可以在内部初始化。
*/