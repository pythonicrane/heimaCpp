/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��23��11:25:52
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : ����ָ��
* @Description  :
*
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

int fun(int a, int b)
{
	cout << "fun(" << a << ", " << b << ");" << endl;
	return 0;
}

//����һ������һ����������
typedef int(FUNC)(int, int);

//������������һ������ָ������
typedef int(*FUNC_P)(int, int);

//������������һ������ָ��
int(*funp)(int, int) = NULL;

void my_funtion(int(*fp)(int, int), int a, int b)//�ص������Ƕ�̬��ʼ��
{
	cout << "ҵ���߼�1" << endl;
	cout << "ҵ���߼�2" << endl;
	fp(a, b);//�ɱ�ҵ���߼�
	cout << "ҵ���߼�" << endl;
}

int main() {

	FUNC *fp1 = fun;
	fp1(10, 20);
	(*fp1)(10, 20);//�������Ż�

	FUNC_P fp2 = fun;
	fp2(100, 200);

	funp = fun;
	funp(1000, 2000);

	cout << "-------------" << endl;
	my_funtion(fp1, 10, 20);
	my_funtion(fp2, 100, 200);
	my_funtion(funp, 1000, 2000);

	system("pause");
}




