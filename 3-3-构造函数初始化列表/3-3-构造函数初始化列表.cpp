/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��18��15:44:02
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : �๹�캯����ʼ���б�
* @Description  :
* 1.R(31)
* 2.R(35)
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

class A {
public:
	A(int a)
	{
		cout << "A(int)..." << endl;
		_a = a;
	}
	~A()
	{
		cout << "~A()..." << endl;
	}
private:
	int _a;
};

class B {
public:
	B(A& a1, A& a2, int b) :_a1(a1), _a2(a2), _b(b)//�ᷢ������ת������A��int)
	{
		cout << "B(A&,A&,int)..." << endl;
	}
	B(int a1, int a2, int b) :_a1(a1), _a2(a2), _b(b)//��ʼ��˳��������б��޹أ����Ǹ�data member˳���й�
	{
		cout << "B(int,int,int)..." << endl;
	}
private:
	int _b;
	A _a1;//��ʼ��˳����_a1,_a2;
	A _a2;
};

void test1()
{
	A a1(10), a2(100);
	B(a1, a2, 1000);
}


int main() 
{

	test1();

	system("pause");
}
