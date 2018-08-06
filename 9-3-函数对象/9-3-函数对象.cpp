/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年8月6日17:22:11
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 函数对象
* @Description  :
-------------------------------------------------------------**/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class MyPrint {
public:
	MyPrint() 
	{
		printNum = 0;
	}

	void operator()(int val)
	{
		printNum++;
		cout << val << endl;
	}

	int printNum;//函数对象可以保存函数信息，从而避免使用全局变量来保存
};

int main()
{
	vector<int> vt;
	vt.push_back(10);
	vt.push_back(20);
	vt.push_back(30);
	vt.push_back(40);
	vt.push_back(50);

	MyPrint pt = for_each(vt.begin(),vt.end(),MyPrint());//for_each第三个参数非引用，是拷贝，故不能保存函数对象信息
	cout << "打印次数printNum = " << pt.printNum << endl;

	system("pause");
}