/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月17日15:26:58
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 函数默认参数
* @Description  :
*
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

int get_Volume(int len, int width, int hight = 10) {//默认参数必须从后面开始！！！！！！！！
	cout << "Lenght = " << len << endl;
	cout << "Width = " << width << endl;
	cout << "Hight = " << hight << endl;
	cout << "V = " << len * width*hight << endl;
	return  len * width*hight;
}

int main() {



	system("pause");
}
