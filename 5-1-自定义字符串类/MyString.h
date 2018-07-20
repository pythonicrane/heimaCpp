#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;
class MyString
{
public:
	//无参构造
	MyString();
	//指定长度构造
	MyString(int lenght);
	//C字符指针构造
	MyString(const char *str);
	//拷贝构造
	MyString(const MyString &s);
	//析构函数
	~MyString();

	//重载操作符[]
	char& operator[](int index);
	//重载操作符=
	MyString& operator=(const MyString& s);
	//重载操作符<<
	friend ostream&  operator<<(ostream &os,const MyString &s);
	//重载操作符>>
	friend istream&  operator>>(istream &is, MyString &s);
	//重载操作符==
	bool operator==(const MyString &s);
	//重载操作符!=
	bool operator!=(const MyString &s);
	//重载操作符+
	MyString operator+(const MyString& s);

private:
	int len;
	char *str;
};

