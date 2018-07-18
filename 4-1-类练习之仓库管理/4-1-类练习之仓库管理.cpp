/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月18日20:31:29
* @Software     : Visual Studio 2017
* @Project      : 黑马程序员基础
* @Problem      : 类练习-仓库管理
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
		cout << "新增了" << weight << "重量的货物" << endl;
	}
	~Goods()
	{
		sum_weight -= weight;
		cout << "减少了" << weight << "重量的货物" << endl;
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
		cout << "仓库没货了！" << endl;
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
		cout << "1 进货 2 退货 0 退出" << endl;
		cin >> choice;
		switch (choice){
		case 1:
			cout << "请输入要创建的货物重量：";
			cin >> w;
			inGoods(head, w);
			break;
		case 2:
			outGoods(head);
			break;
		default:
			break;
		}
		cout << "当前仓库货物总重量为：" << Goods::Get_sum_weight() << endl;
	} while (choice);


	system("PAUSE");
}
