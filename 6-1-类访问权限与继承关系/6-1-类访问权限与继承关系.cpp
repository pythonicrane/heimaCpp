/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��20��14:36:18
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : ��ķ���Ȩ����̳й�ϵ
* @Description  :
*
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

class Parent {
public:
	int pub;//������ڲ����ⲿ�����Է���
protected:
	int pro;//������ڲ����Է��ʣ����ⲿ�����Է���
private:
	int pri;//������ڲ����Է��ʣ�������ⲿ�����Է���
};

//���м̳У�
//���๫�г�Ա��ɹ��г�Ա�����ڿ��Է��ʣ���������ܷ���
//���ౣ����Ա��ɱ�����Ա�����ڿ��Է��ʣ����ⲻ�����ܷ���
//����˽�г�Ա������,��������ڶ������Է���
class Child1 :public Parent {
public:
	void func()
	{
		cout << pub << endl;
		cout << pro << endl;
		//cout << pri << endl;
	}
};

//�����̳У�
//���๫�г�Ա��ɱ�����Ա�����ڿ��Է��ʣ����ⲻ�����ܷ���
//���ౣ����Ա��ɱ�����Ա�����ڿ��Է��ʣ����ⲻ�����ܷ���
//����˽�г�Ա������,��������ڶ������Է���
class Child2 :protected Parent {
public:
	void func()
	{
		cout << pub << endl;
		cout << pro << endl;
		//cout << pri << endl;
	}
};

//˽�м̳У�
//���๫�г�Ա���˽�г�Ա�����ڿ��Է��ʣ����ⲻ�����ܷ���
//���ౣ����Ա���˽�г�Ա�����ڿ��Է��ʣ����ⲻ�����ܷ���
//����˽�г�Ա������,��������ڶ������Է���
class Child3 :private Parent {
public:
	void func()
	{
		cout << pub << endl;
		cout << pro << endl;
		//cout << pri << endl;
	}
};

int main() {

	Parent p1;
	p1.pub;


	

	system("pause");
}