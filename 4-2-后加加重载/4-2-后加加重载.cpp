/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月19日14:47:38
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 操作符重载
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
		if (this == &t) {//1.重载=运算符主要判断自我赋值！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
			return *this;
		}
		//2.释放自身垃圾，若对象本身含有堆数据，注意先释放！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
		_a = t._a;
		_b = t._b;
		//3.深拷贝操作
		return *this;
	}


	friend Complex operator+(const Complex &t1, const Complex &t2);
	friend Complex& operator+=(Complex &t1, const Complex &t2);
	friend Complex& operator++(Complex &t1);
	friend const Complex operator++(Complex &t1, int);
	friend ostream& operator<<(ostream& os, Complex t);
		
	//重载+方法2
	Complex operator+(const Complex &t)
	{
		Complex temp(_a + t._a, _b + t._b);
		return temp;
	}
	//重载+=方法2
	Complex operator+=(const Complex &t2)
	{
		_a += t2._a;
		_b += t2._b;
		return *this;
	}
	//重载++i方法2
	Complex operator++()
	{
		++_a;
		++_b;
		return *this;
	}
	//重载i++方法2
	const Complex operator++(int)//参数是占位符，亚元！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	{
		Complex tmp(*this);
		++_a;
		++_b;
		return tmp;
	}
	//重载<<方法2,但调用方法是t<<cout！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	ostream& operator<<(ostream& os)//返回ostream引用！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	{
		os << "(" << _a << "," << _b << "i)";
		return os;
	}

	//重载==
	bool operator==(const Complex &t)
	{
		if (_a == t._a && _b == t._b)
			return true;
		return false;
	}

	//重载!=
	bool operator!=(const Complex &t)
	{
		return !(*this == t);
	}


private:
	int _a;
	int _b;
};

//重载+方法1,全局重载，需要申明友元函数
Complex operator+(const Complex &t1, const Complex &t2)
{
	Complex temp(t1._a + t2._a, t1._b + t2._b);
	return temp;
}

//重载+=方法1,全局重载，需要申明友元函数
Complex& operator+=(Complex &t1, const Complex &t2)
{
	t1._a += t2._a;
	t1._b += t2._b;
	return t1;
}

//重载++i方法1,全局重载，需要申明友元函数
Complex& operator++(Complex &t1)
{
	++t1._a;
	++t1._b;
	return t1;
}

//重载i++方法1,全局重载，需要申明友元函数
const Complex operator++(Complex &t1,int)
{
	Complex tmp(t1);
	++t1._a;
	++t1._b;
	return tmp;
}

//重载<<方法1，全局重载，需要申明友元函数
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
	//重载()
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
