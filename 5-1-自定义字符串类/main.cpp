/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月20日11:12:45
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 自定义String类
* @Description  :
*
-------------------------------------------------------------**/

#include<iostream>
#include"MyString.h"
using namespace std;


int main() {

	MyString s1("abc");
	MyString s2(s1);
	MyString s3("123");

	//s1 + s2;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	cout << s1 + s2 + s3 << endl;//要重载<<的const版本才能打印s1+s2;
	
	system("pause");
}
