#include "MyString.h"



MyString::MyString()
{
	this->len = 0;
	this->str = nullptr;
	cout << "MyString()..." << endl;
}


MyString::~MyString()
{
	cout << "~MyString()..." << endl;
	if (str != nullptr) {
		delete str;
		str = nullptr;
		len = 0;
	}

}


MyString::MyString(int lenght)
{
	cout << "MyString(int)..." << endl;
	this->len = lenght;
	this->str = new char[lenght+1];
	strcpy(str, "");
}


MyString::MyString(const char *s)
{
	cout << "MyString(const char*)..." << endl;
	if (s == nullptr) {
		len = 0;
		str = new char[1];
		strcpy(str, "");
	}
	else {
		len = strlen(s);
		str = new char[len + 1];
		strcpy(str, s);
	}
}


MyString::MyString(const MyString &s)
{
	cout << "MyString(const MyString&)..." << endl;
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}

ostream& operator<<(ostream &os,const MyString &s)
{
	os << s.str;
	return os;
}

istream&  operator>>(istream &is, MyString &s)
{
	if (s.str != nullptr) {
		delete[] s.str;
		s.str = nullptr;
		s.len = 0;
	}
	char temp_str[4096] = { 0 };
	cin >> temp_str;
	s.len = strlen(temp_str);
	s.str = new char[s.len + 1];
	strcpy(s.str, temp_str);

	return is;
}

char& MyString::operator[](int index)
{
	return this->str[index];
}

MyString& MyString::operator=(const MyString& s)
{
	cout << "MyString::operator=..." << endl;
	if (this == &s) {
		return *this;
	}
	if (this->str != nullptr)
	{
		delete[] this->str;
		this->str = nullptr;
		this->len = 0;
	}
	if (s.str == nullptr) {
		len = 0;
		str = new char[1];
		strcpy(str, "");
	}
	else {
		len = strlen(s.str);
		str = new char[len + 1];
		strcpy(str, s.str);
	}
	return *this;
}

MyString MyString::operator+(const MyString& s)
{
	cout << "MyString::operator+..." << endl;
	MyString tmp;
	tmp.len = this->len + s.len;
	tmp.str = new char[tmp.len + 1];
	strcpy(tmp.str, this->str);
	strcat(tmp.str, s.str);
	return tmp;
}

bool MyString::operator==(const MyString &s)
{
	if (this->len != s.len) {
		return false;
	}
	else {
		return !strcmp(this->str, s.str);
	}
}

bool MyString::operator!=(const MyString &s)
{
	return !(*this == s);
}