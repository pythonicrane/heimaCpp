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

	//���ز�����[]
	char& operator[](int index);
	//���ز�����=
	MyString& operator=(const MyString& s);
	//���ز�����<<
	friend ostream&  operator<<(ostream &os, MyString &s);
	//���ز�����>>
	friend istream&  operator>>(istream &is, MyString &s);
	//���ز�����==
	//���ز�����!=
	//���ز�����+
	MyString operator+(const MyString& s);

private:
	int len;
	char *str;
};

