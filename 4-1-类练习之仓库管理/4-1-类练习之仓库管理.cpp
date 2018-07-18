/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��18��20:31:29
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : ����ϰ-�ֿ����
* @Description  :
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

class Goods {
public:
	Goods *next;
	Goods()
	{
		weight = 0;
		next = NULL;
	}
	Goods(int w)
	{
		weight = w;
		next = NULL;
		sum_weight += weight;
		cout << "������" << weight << "�����Ļ���" << endl;
	}
	~Goods()
	{
		sum_weight -= weight;
		cout << "������" << weight << "�����Ļ���" << endl;
	}
	int get_Weight()
	{
		return weight;
	}
	static int Get_sum_weight()
	{
		return sum_weight;
	}
private:
	int weight;
	static int sum_weight;
};

int Goods::sum_weight = 0;

void inGoods(Goods * &head, int w)
{
	Goods *new_goods = new Goods(w);
	if (head == NULL) {
		head = new_goods;
	}else {
		new_goods->next = head;
		head = new_goods;
	}
}

void outGoods(Goods *&head)
{
	if (head == NULL) {
		cout << "�ֿ�û���ˣ�" << endl;
		return;
	}

	Goods * tmp = head;
	head = head->next;
	delete tmp;
}

int main()
{
	int choice = 0;
	int w = 0;
	Goods *head = NULL;
	do {
		cout << "1 ���� 2 �˻� 0 �˳�" << endl;
		cin >> choice;
		switch (choice){
		case 1:
			cout << "������Ҫ�����Ļ���������";
			cin >> w;
			inGoods(head, w);
			break;
		case 2:
			outGoods(head);
			break;
		default:
			break;
		}
		cout << "��ǰ�ֿ����������Ϊ��" << Goods::Get_sum_weight() << endl;
	} while (choice);


	system("PAUSE");
}
