/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��4��24��21:47:12
* @Software     : Visual Studio 2017
* @Project      : C++ Primer
* @Problem      : List�Ļ�������
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

	s1 + s2;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	//cout << s1 + s2 << endl;
	
	system("pause");
}
