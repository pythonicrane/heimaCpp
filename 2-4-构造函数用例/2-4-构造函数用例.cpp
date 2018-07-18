/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��18��20:31:29
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : �๹�캯����ʹ��
* @Description  :
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

class Test {
public:
	Test():_x(0),_y(0)//�޲ι���
	{
		cout << "Test()..." << &(*this) << endl;
	}
	Test(int x, int y)//�вι���
	{
		_x = x;
		_y = y;
		cout << "Test(int,int)..." << _x << " " << _y << &(*this) << endl;
	}
	Test(const Test& t)//��������
	{
		_x = t._x;
		_y = t._y;
		cout << "Test(const Test&)..." << _x << " " << _y << &(*this) << endl;
	}
	void operator=(const Test& t)
	{
		_x = t._x;
		_y = t._y;
		cout << "operator=..." << _x << " " << _y << &(*this) << endl;
	}
	~Test()//����
	{
		cout << "~Test()..." << _x << " " << _y << &(*this) << endl;
	}

	void printT()
	{
		cout << "printT(): " << "x= " << _x << ",y= " << _y << &(*this) << endl;
	}

private:
	int _x;
	int _y;
};

//����1
void test1()
{
	Test t1(10, 20);
	Test t2(t1);
	Test t3 = t1;//��Test t2(t1)һ�����������operator=;
}

//����2
void test2()
{
	Test t1(10, 20);
	Test t2;
	t2 = t1;
}

//����3
void func(Test t)//�������ṹ����ʱ����Test t = t1,���õĹ��캯����Test::Test(Test&);
{
	cout << "func begin..." << endl;
	t.printT();
	cout << "func end..." << endl;
}

void test3()
{
	cout << "test3 begin..." << endl;
	Test t1(10, 20);
	func(t1);
	cout << "test3 endl..." << endl;
}

//����4
Test func2()
{
	cout << "func2 begin..." << endl;
	Test t(10, 20);
	t.printT();
	cout << "func2 end..." << endl;
	return t;//����ʱ���������ṹ����ʱ����Test temp1 = t,���õĹ��캯����Test::Test(Test&);Ȼ������t;
}

void test4()
{
	cout << "test4 begin..." << endl;
	func2();//�ᴴ����ʱ����temp2�����ÿ������캯��Test temp2(temp1)����Ϊδ������ʱ���󣬸���ʱ���������������
	cout << "test4 endl..." << endl;
}


void test5()
{
	cout << "test5 begin..." << endl;
	Test t1 = func2();//���ÿ�������Test t1(temp1)��
	cout << "test5 endl..." << endl;
}

void test6()
{
	cout << "test6 begin..." << endl;
	Test t1;
	t1= func2();
	cout << "test6 endl..." << endl;
}



int main()
{
	test5();

	system("PAUSE");
}

