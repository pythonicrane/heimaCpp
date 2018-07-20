/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018��7��20��11:12:29
* @Software     : Visual Studio 2017
* @Project      : �������Ա����
* @Problem      : ��
* @Description  :
*
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

class Point {
public:
	Point() {
		_x = 0;
		_y = 0;
		cout << "Point noList constructor" << endl;
	};
	Point(double x, double y) :_x(x), _y(y) {
		cout << "Point constructor" << endl;
	};
	Point(const Point& t) {
		_x = t._x;
		_y = t._y;
		cout << "Point copy constructor" << endl;
	};
	~Point() {
		cout << "Point destructor" << endl;
	}

	// Point operator=(const Point& t) {
	// 	_x = t._x;
	// 	_y = t._y;
	// 	cout << "Point asignment operator" << endl;
	// 	return *this;
	// }

	Point operator+(const Point& t) {
		_x += t._x;
		_y += t._y;
		cout << "Point + operator" << endl;
		return *this;
	};
private:
	double _x;
	double _y;
};

class Point3D :public Point {
public:
	Point3D(double x = 0, double y = 0, double z = 0) :Point(x, y), _z(z) {
		cout << "Point3D constructor" << endl;
	};
	~Point3D() {
		cout << "Point3D destructor" << endl;
	};
private:
	double _z;
};


int main()
{
	cout << "0" << endl;
	Point a(1, 1);
	cout << "1" << endl;
	Point b(2, 2);
	cout << "2" << endl;
	Point c(0,0);
	cout << "3" << endl;
	c = a + b;
	cout << "4" << endl;
	Point d = a + c;
	cout << "5" << endl;
	c + d;
	cout << "6" << endl;

	system("PAUSE");
}

/*
1.������Ĭ�Ϲ��캯����new�������vec_new���������ڴ���䣬����malloc
2.delete�����ָ�룬ֻ���ͷ���Ӧ�Ļ����С���ݡ�
3.���߿���ʹ�������������������ȷɾ�������ࡣ
*/