/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��24��15:56:52
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : �쳣��Ӧ��
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
		cout << "Ŀ��ռ�Ϊ�գ�" << endl;
	}
	virtual ~TargetNULLException() {};
};

class SourceNULLException :public BaseMyException {
public:
	virtual void what()
	{
		cout << "Դ�ռ�Ϊ�գ�" << endl;
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
	catch (BaseMyException& e) {//���ã����Լ��ٿ���
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
