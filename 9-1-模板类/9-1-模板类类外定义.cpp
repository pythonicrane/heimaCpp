/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月24日10:05:22
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 类模板类外定义
* @Description  :
* 类模板慎用友元函数
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

template <class T>
class Person;
template <class T>
void print(const Person<T>&  t);

template<class T>
class Person {
public:
	Person(T age, T ID);

	void show();

	//template<class T2>//3.友元函数是函数模板，所以类内申明也要附加模板
	//friend ostream& operator<<(ostream& os, Person<T2>& t);

	friend ostream& operator<< <T>(ostream& os, const Person<T>& t);//4.上面的方法G++不能通过！！！！！！！！
	//普通友元函数
	friend void print<T>(const Person<T>&  t);
private:
	T mAge;
	T mID;
};

template<class T>//1.类外定义需要带上模板
Person<T>::Person(T age, T ID)//2.命名空间需要加上模板
{
	mAge = age;
	mID = ID;
}

template<class T>
void Person<T>::show()
{
	cout << "Teacher ID = " << mID << ", Age = " << mAge << endl;
}

//template<class T2>
//ostream& operator<<(ostream& os, Person<T2>& t)
//{
//	os << "Teacher ID = " << t.mID << ", Age = " << t.mAge;
//	return os;
//}

template<class T>
ostream& operator<<(ostream& os, const Person<T>& t)
{
	os << "Teacher ID = " << t.mID << ", Age = " << t.mAge;
	return os;
}

template<class T>
void print(const Person<T>&  t)
{
	cout << "Teacher ID = " << t.mID << ", Age = " << t.mAge << endl;
}

void test1()
{
	Person<int> p(20, 2018);
	cout << p << endl;
	print(p);

	
}

void func() throw(int ,double ,char)
{
	throw "abc";
}


int main() {

	try {
		func();
	}
	catch(char* str){
		cout << str << endl;
	}
	catch (...) {
		cout << "No !" << endl;
	}

	system("pause");
}
