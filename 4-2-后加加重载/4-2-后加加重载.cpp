/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��19��14:47:38
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : ����������
* @Description  :
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

class Complex {
public:
	Complex()
	{
		_a = 0;
		_b = 0;
	}
	Complex(int a,int b):_a(a),_b(b)
	{

	}
	Complex(Complex &t)
	{
		_a = t._a;
		_b = t._b;
	}
	~Complex()
	{

	}

	Complex& operator=(Complex &t)
	{
		if (this == &t) {//1.����=�������Ҫ�ж����Ҹ�ֵ������������������������������������������������������������
			return *this;
		}
		//2.�ͷ��������������������ж����ݣ�ע�����ͷţ�������������������������������������������������������������
		_a = t._a;
		_b = t._b;
		//3.�������
		return *this;
	}


	friend Complex operator+(const Complex &t1, const Complex &t2);
	friend Complex& operator+=(Complex &t1, const Complex &t2);
	friend Complex& operator++(Complex &t1);
	friend const Complex operator++(Complex &t1, int);
	friend ostream& operator<<(ostream& os, Complex t);
		
	//����+����2
	Complex operator+(const Complex &t)
	{
		Complex temp(_a + t._a, _b + t._b);
		return temp;
	}
	//����+=����2
	Complex operator+=(const Complex &t2)
	{
		_a += t2._a;
		_b += t2._b;
		return *this;
	}
	//����++i����2
	Complex operator++()
	{
		++_a;
		++_b;
		return *this;
	}
	//����i++����2
	const Complex operator++(int)//������ռλ������Ԫ��������������������������������������������������������������
	{
		Complex tmp(*this);
		++_a;
		++_b;
		return tmp;
	}
	//����<<����2,�����÷�����t<<cout����������������������������������������������������������������������������������
	ostream& operator<<(ostream& os)//����ostream���ã���������������������������������������������������������
	{
		os << "(" << _a << "," << _b << "i)";
		return os;
	}

	//����==
	bool operator==(const Complex &t)
	{
		if (_a == t._a && _b == t._b)
			return true;
		return false;
	}

	//����!=
	bool operator!=(const Complex &t)
	{
		return !(*this == t);
	}


private:
	int _a;
	int _b;
};

//����+����1,ȫ�����أ���Ҫ������Ԫ����
Complex operator+(const Complex &t1, const Complex &t2)
{
	Complex temp(t1._a + t2._a, t1._b + t2._b);
	return temp;
}

//����+=����1,ȫ�����أ���Ҫ������Ԫ����
Complex& operator+=(Complex &t1, const Complex &t2)
{
	t1._a += t2._a;
	t1._b += t2._b;
	return t1;
}

//����++i����1,ȫ�����أ���Ҫ������Ԫ����
Complex& operator++(Complex &t1)
{
	++t1._a;
	++t1._b;
	return t1;
}

//����i++����1,ȫ�����أ���Ҫ������Ԫ����
const Complex operator++(Complex &t1,int)
{
	Complex tmp(t1);
	++t1._a;
	++t1._b;
	return tmp;
}

//����<<����1��ȫ�����أ���Ҫ������Ԫ����
ostream& operator<<(ostream& os,Complex t)
{
	os << "(" << t._a << "," << t._b << "i)";
	return os;
}


class Sqr {
public:
	Sqr(int t) :a(t)
	{

	}
	//����()
	int operator()(int t)
	{
		return t * t;
	}

private:
	int a;
};

int main()
{
	
	Sqr s(2);
	cout<<s(10)<<endl;

	system("PAUSE");
}
