#include<iostream>
using namespace std;

template<class T>
void add(const T& a,const T& b)
{
	a + b;
}

int main() {
	int a = 10;
	int b = 20;
	char c = 'c';
	add(a, b);
	add(5, 10);

	system("pause");
}

