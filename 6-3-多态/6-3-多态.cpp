/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��20��15:56:09
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : ��̬
* @Description  :
* 1.��̬�����������̳У��麯�����ǣ�����ָ�������
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

class A{
public:
	A()
	{
		a = 'a';
	}
	void print()
	{
		cout << a << endl;
	}
	virtual void vprint()
	{
		cout << a << endl;
	}
	char a;
};

class B:public A{
public:
	B()
	{
		b = 'b';
	}
	void print()//�˺������������汾��һ����B�İ汾��һ���Ǽ̳���A�İ汾
	{
		cout << b << endl;
	}

	virtual void vprint()
	{
		cout << b << endl;//�˴��������汾����A�İ汾������,�ᷢ����̬��A�Ŀ���ͨ�������ռ����
	}
	char b;
};

class C :public A {
public:
	C()
	{
		c = 'c';
	}
	virtual void print()
	{
		cout << c << endl;
	}
	void vprint(int i)//�˴��������أ�����̳�A��vprint!!!!!!!!
	{
		cout << c << "+" << i << endl;
	}
	char c;
};


void printT(A& t)
{
	t.print();
}

void vprintT(A& t)
{
	t.vprint();
}

int main() {

	A ta;
	B tb;
	C tc;


	printT(ta);
	tb.A::print();
	printT(tb);//1.��ͬ��һ�䣬û���麯������������̬
	vprintT(tb);//2.�����̬��Ҫ�أ�������̬
	tb.A::vprint();

	
	tc.vprint(10);//3.�������ذ汾
	//tc.vprint();//4.����ֱ�ӵ���vprint()
	tc.A::vprint();
	vprintT(tc);//5.�����Լ��ͨ��vptr���ã�����������������
	printT(tc);//6.�޷�������̬���ڻ����У�print()�����麯����������������ָ�����麯����ֻ���������̳з�����̬����������������
	
	cout << "--------------" << endl;


	system("pause");
}
