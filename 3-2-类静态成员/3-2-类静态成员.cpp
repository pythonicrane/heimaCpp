/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��18��17:15:15
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : �ྲ̬��Ա
* @Description  :
*
-------------------------------------------------------------**/
#include<iostream>
using namespace std;

class Test {
public:
	int getC()
	{
		_c++;
		return _c;//4.�Ǿ�̬��Ա�������Է��ʾ�̬��Ա������
	}
	static int getSC()//3.��̬��Ա������ӵ��thisָ�룬�ʲ��ܷ��ʷǾ�̬��Ա����ֻ�ܷ��ʾ�̬��Ա��
	{
		return _c;
	}
private:
	int _a;
	int _b;
	static int _c;//2.���������ڳ�ʼ������̬��Ա��֪�ö����ڴ档
};

int Test::_c = 0;//1.�����ʼ�����Ҳ�Ҫ��static��������һ�㾲̬����������������

int main() {
	Test t;
	cout << t.getC() << endl;

	system("pause");
}
