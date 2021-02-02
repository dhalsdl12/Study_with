/*
����1)
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point();
	Point(int a, int b);
	void show() { cout << "{" << x << "," << y << "}" << endl; }
};

Point::Point() : Point(0, 0) {} //���� ������
Point::Point(int a, int b) //Ÿ�� ������
	: x(a), y(b) {}

int main()
{
	Point origin;
	Point target(10, 20);
	origin.show();
	target.show();
}
*/


/*
����2)
#include <iostream>
using namespace std;

class Rect{
public:
	int width, height;
	Rect();
	Rect(int w, int h);
	Rect(int length);
	bool isSquare();
};
Rect::Rect() : Rect(1,1){}
Rect::Rect(int w, int h) {
	width = w, height = h;
}
Rect::Rect(int length) {
	width = height = length;
}
//���簢���̸� true�� �����ϴ� ����Լ�
bool Rect::isSquare() {
	if (width == height) return true;
	else return false;
}
int main()
{
	Rect rect1;
	Rect rect2(3, 50);
	Rect rect3(3);

	if (rect1.isSquare()) cout << "rect1�� ���簢���̴�" << endl;
	if (rect2.isSquare()) cout << "rect2�� ���簢���̴�" << endl;
	if (rect3.isSquare()) cout << "rect3�� ���簢���̴�" << endl;
}
*/


/*
�Ҹ���(destructor) : ��ü�� �Ҹ�Ǵ� �������� �ڵ����� ȣ��Ǵ�
					Ŭ������ ����Լ��̴�.
��ü�� �Ҹ�Ǹ� ��ü �޸𸮴� �ý������� ��ȯ�ȴ�.
���� ��ü ������ ������ �Լ��� ����Ǵ� �� ó�� ��ü �Ҹ�� �Ҹ��� �Լ��� ����ȴ�.
Ư¡:
1. �Ҹ����� ������ ��ü�� ����� �� �ʿ��� ������ �۾��� �����̴�.
2. �Ҹ����� �̸��� Ŭ���� �̸� �տ� ~�� ���δ�.
3. �Ҹ��ڴ� ���� Ÿ���� ������ � ���� �����ؼ��� �ȵȴ�.
4. �Ҹ��ڴ� ���� �Ѱ��� �����ϸ� �Ű������� ������ �ʴ´�.
5. �Ҹ��ڰ� ����Ǿ� ���� ������ �⺻ �Ҹ���(default destructor)�� �ڵ����� �����ȴ�.

*/


/*
#include <iostream>
using namespace std;

class Circle {
public:
	int radius; //�������

	Circle(); //������
	Circle(int r); //������
	~Circle(); //�Ҹ���
	double getArea(); //����Լ�
};

Circle::Circle() { //������ ����
	radius = 1;
	cout << "������ " << radius << "  �� ����" << endl;
}
Circle::Circle(int r) { //������ ����
	radius = r;
	cout << "������ " << radius << "  �� ����" << endl;
}
Circle::~Circle() { //�Ҹ��� ����
	cout << "������ " << radius << "  �� �Ҹ�" << endl;
} //��ü ������ �ݴ������ �Ҹ�
double Circle::getArea() { //����Լ� ����
	return 3.14*radius*radius;
}

int main()
{
	Circle donut;
	Circle pizza(30);

	return 0;
}
*/


/*
��ü ���� ����
���� ��ü�� ���α׷��� ����� ������ ����
���� ��ü�� �Լ��� ȣ��Ǵ� ������ ������� ����

��ü �Ҹ� ����
�Լ��� �����ϸ�, ������ü�� ������ ������ �������� �Ҹ�
���α׷��� �����ϸ�, ������ü�� ������ ������ �������� �Ҹ�
*/


/*
#include <iostream>
using namespace std;

class Circle {
public:
	int radius; //�������

	Circle(); //������
	Circle(int r); //������
	~Circle(); //�Ҹ���
	double getArea(); //����Լ�
};

Circle::Circle() { //������ ����
	radius = 1;
	cout << "������ " << radius << "  �� ����" << endl;
}
Circle::Circle(int r) { //������ ����
	radius = r;
	cout << "������ " << radius << "  �� ����" << endl;
}
Circle::~Circle() { //�Ҹ��� ����
	cout << "������ " << radius << "  �� �Ҹ�" << endl;
} //��ü ������ �ݴ������ �Ҹ�
double Circle::getArea() { //����Լ� ����
	return 3.14*radius*radius;
}

Circle gobaldonut(1000);
Circle gobalpizza(2000);
void f()
{
	Circle fdonut(100);
	Circle fpizza(200);
}
int main()
{
	Circle maindonut;
	Circle mainpizza(30);
	f();
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

inline int odd(int x)
{
	return (x % 2);
}
int main()
{
	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		if (odd(i))
			sum += i;
	}
	cout << sum;
}*/


/*
�ζ��� �Լ��� ȣ���ϴ� ���� �ζ��� �Լ� �ڵ带 Ȯ�� ����
	��ũ�ο� ����
	�ڵ�Ȯ���� �ζ��� �Լ��� �����
�ζ��� �Լ� ȣ��
	�Լ� ȣ�⿡ ���� ������� �������� ����
	���α׷��� ����ӵ� ����
�ζ��� �Լ� �������
	�����Ͽ��� �ִ� �䱸�ϴ� �޼���
	�����Ϸ��� �Ǵ��Ͽ� �䱸�� �������� ����
	recursion, static����, for, switch, goto�� �� ���Լ��� ���� �Լ��� ����
*/


/*
<����>
�����ڸ� private, protected�� �����ϴ� ���
�����ڰ� public�� �ƴϸ� �ܺο��� ��ü�� ������ �� ����.
�׷��� �����ڴ� �׻� public���� �����ؾ� �ϴ°�?
�ƴϴ�. �ǵ������� �ܺο��� ��ü�� ������ �� ������ �����ڸ� private�� �����ϱ⵵ �ϰ�,
�ڽ� Ŭ���������� �����ڸ� ȣ���ϵ��� protected�� �����ϱ⵵ �Ѵ�.
*/


/*
�ζ��� �Լ��� :
  - ª�� �ڵ�� ������ �Լ��� ����, �Լ� ȣ�� �������� ����
  ���α׷� ����ӵ� ���ϸ� ���� ���� ������ ����̴�.
  - �����Ϸ��� �ζ��� �Լ��� ȣ���ϴ� ���� �ζ��� �Լ��� �ڵ带 �״�� �����Ͽ�
  �Լ� ȣ���� �Ͼ�� �ʰ��Ѵ�. �̷��� �Լ�ȣ�� ������尡 �������� ������
  �Լ� ���� �ӵ��� ��������.
  - c++������ ����Լ��� ũ�Ⱑ �������, Ŭ������ ����ο� ���� �����Ͽ��� �����ϴ�.
  - �����Ϸ��� Ŭ������ ����ο� ������ ����Լ��鿡 ���ؼ�
  inline������ ��� �ζ��� �Լ��� �ڵ�ó���Ѵ�.
*/

//����3
/*
#include <iostream>
using namespace std;
//C++ ����ü ����
struct StructCircle { //struct�� defult ���� �����ڴ� public�̴�.
private:
	int radius;
public:
	StructCircle(int r) { radius = r; } //����ü ������
	double getArea();
};
double StructCircle::getArea() {
	return 3.14*radius*radius;
}

int main()
{
	StructCircle waffle(3);
	cout << "������ " << waffle.getArea();
}
*/

/*
<����>
����ü���� Ŭ������ ����϶�.
����ü Ŭ������ ���� ���ٸ� ����ü�� Ŭ���� �� ����� ����ϴ� ���� ������?
������ ����. �����ڿ� ���� ��������� �ִ� �ڷᱸ���� ��� ����ü�� ����ϱ⵵ �Ѵ�.
�ٸ�, C����� ����� Ż�Ǹ� ���� ����ü�� ����� ���ϴ� ���� ����.
����ü�� Ŭ������ �Բ� ����ϸ鼭 ������ ȥ���� �� �ʿ䰡 ����.
*/


/*
��������� ���鶧 ����
#ifndef CIRCLE_H
#define CIRCLE_H
��������
#endif
�ϸ� ������ Circle.h�� �ҷ��͵� ������ ���� �ʴ´�.
*/