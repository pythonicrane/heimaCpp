/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��20��20:14:07
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : vptr�ֲ���ʼ��
* @Description  :
* 
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

class Parent {
public:
	Parent(int a)
	{
		cout << "Parent(int)..." << endl;
		this->a = a;
		print();//ֻ����ø����print()
	}
	virtual void print()
	{
		cout << "Parent::print()...a= " << a << endl;
	}
private:
	int a;
};

class Child :public Parent{
public:
	Child(int a,int b):Parent(a)//1.�ڴ˴����ø��๹��������ʱvptr��ֻ��ָ�����麯����
	{
		//2.��ʱ������麯�����γɣ�vptr�Ѿ�ָ��������麯����
		cout << "Child(int)..." << endl;
		this->b = b;
		print();//���õ�������ĺ���
	}
	virtual void print()
	{
		cout << "Child::print()...b= " << b << endl;
	}
private:
	int b;
};

int main() {

	Parent *pp = new Child(10, 20);

	delete pp;

	system("pause");
}
