#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;
class MyString
{
public:
	//�޲ι���
	MyString();
	//ָ�����ȹ���
	MyString(int lenght);
	//C�ַ�ָ�빹��
	MyString(const char *str);
	//��������
	MyString(const MyString &s);
	//��������
	~MyString();

	//���ز�����[]
	char& operator[](int index);
	//���ز�����=
	MyString& operator=(const MyString& s);
	//���ز�����<<
	friend ostream&  operator<<(ostream &os,const MyString &s);
	//���ز�����>>
	friend istream&  operator>>(istream &is, MyString &s);
	//���ز�����==
	bool operator==(const MyString &s);
	//���ز�����!=
	bool operator!=(const MyString &s);
	//���ز�����+
	MyString operator+(const MyString& s);

private:
	int len;
	char *str;
};

