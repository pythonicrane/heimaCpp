#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;
class MyString
{
public:
	MyString();
	MyString(int lenght);
	MyString(const char *str);
	MyString(const MyString &s);
	~MyString();

	//重载操作符[]
	char& operator[](int index);
	//重载操作符=
	MyString& operator=(const MyString& s);
	//重载操作符<<
	friend ostream&  operator<<(ostream &os, MyString &s);
	//重载操作符>>
	friend istream&  operator>>(istream &is, MyString &s);
	//重载操作符==
	//重载操作符!=
	//重载操作符+
	MyString operator+(const MyString& s);

private:
	int len;
	char *str;
};

