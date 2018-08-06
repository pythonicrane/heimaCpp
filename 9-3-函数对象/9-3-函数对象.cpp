/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��8��6��17:22:11
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : ��������
* @Description  :
-------------------------------------------------------------**/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class MyPrint {
public:
	MyPrint() 
	{
		printNum = 0;
	}

	void operator()(int val)
	{
		printNum++;
		cout << val << endl;
	}

	int printNum;//����������Ա��溯����Ϣ���Ӷ�����ʹ��ȫ�ֱ���������
};

int main()
{
	vector<int> vt;
	vt.push_back(10);
	vt.push_back(20);
	vt.push_back(30);
	vt.push_back(40);
	vt.push_back(50);

	MyPrint pt = for_each(vt.begin(),vt.end(),MyPrint());//for_each���������������ã��ǿ������ʲ��ܱ��溯��������Ϣ
	cout << "��ӡ����printNum = " << pt.printNum << endl;

	system("pause");
}