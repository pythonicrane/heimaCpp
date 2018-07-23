/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月23日11:25:52
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 函数指针
* @Description  :
*
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

int fun(int a, int b)
{
	cout << "fun(" << a << ", " << b << ");" << endl;
	return 0;
}

//方法一：定义一个函数类型
typedef int(FUNC)(int, int);

//方法二：定义一个函数指针类型
typedef int(*FUNC_P)(int, int);

//方法三：定义一个函数指针
int(*funp)(int, int) = NULL;

void my_funtion(int(*fp)(int, int), int a, int b)//回调函数是多态的始祖
{
	cout << "业务逻辑1" << endl;
	cout << "业务逻辑2" << endl;
	fp(a, b);//可变业务逻辑
	cout << "业务逻辑" << endl;
}

int main() {

	FUNC *fp1 = fun;
	fp1(10, 20);
	(*fp1)(10, 20);//编译器优化

	FUNC_P fp2 = fun;
	fp2(100, 200);

	funp = fun;
	funp(1000, 2000);

	cout << "-------------" << endl;
	my_funtion(fp1, 10, 20);
	my_funtion(fp2, 100, 200);
	my_funtion(funp, 1000, 2000);

	system("pause");
}




