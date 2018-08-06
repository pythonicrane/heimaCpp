/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月24日15:56:52
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 异常类应用
* @Description  :
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

class BaseMyException {
public:
	virtual void what() = 0;
	virtual ~BaseMyException() {};
};

class TargetNULLException :public BaseMyException{
public:
	virtual void what()
	{
		cout << "目标空间为空！" << endl;
	}
	virtual ~TargetNULLException() {};
};

class SourceNULLException :public BaseMyException {
public:
	virtual void what()
	{
		cout << "源空间为空！" << endl;
	}
	~SourceNULLException() {};
};


void str_copy(char* target,const char* source)
{
	if (target == NULL) {
		throw TargetNULLException();
	}
	if (source == NULL) {
		throw SourceNULLException();
	}

	while ((*(target++) = *(source++))!= '\0') {}
}

int main() {

	const char* source = "abc++";
	char buff[1024] = { 0 };

	try {
		str_copy(NULL, source);
	}
	catch (BaseMyException& e) {//引用，可以减少拷贝
		e.what();
	}
	try {
		str_copy(buff, NULL);
	}
	catch (BaseMyException& e) {
		e.what();
	}
	try {
		str_copy(buff, source);
	}
	catch (BaseMyException& e) {
		e.what();
	}
	cout << buff << endl;


	

	system("pause");
}
