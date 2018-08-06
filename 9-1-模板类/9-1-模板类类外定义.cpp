/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��24��10:05:22
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : ��ģ�����ⶨ��
* @Description  :
* ��ģ��������Ԫ����
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

	//template<class T2>//3.��Ԫ�����Ǻ���ģ�壬������������ҲҪ����ģ��
	//friend ostream& operator<<(ostream& os, Person<T2>& t);

	friend ostream& operator<< <T>(ostream& os, const Person<T>& t);//4.����ķ���G++����ͨ������������������
	//��ͨ��Ԫ����
	friend void print<T>(const Person<T>&  t);
private:
	T mAge;
	T mID;
};

template<class T>//1.���ⶨ����Ҫ����ģ��
Person<T>::Person(T age, T ID)//2.�����ռ���Ҫ����ģ��
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
