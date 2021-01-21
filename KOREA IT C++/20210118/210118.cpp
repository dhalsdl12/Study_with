/*
���ο� �ڷ��� bool
 true�� '��'�� �ǹ��ϴ� 1����Ʈ �������̰�,  false�� '����'�� �ǹ��ϴ� 1����Ʈ �������̴�.
 �� ���� ���� ���� 1�� 0�� �ƴϴ�.
 �׷��� ������ �;��� ��ġ�� ���ԵǸ� ���� 1�� 0���� ��ȯ�ȴ�.
 ��)
 int num1 = true; num1���� 1�� ����ȴ�
 int num2 = false; num2���� 0�� ����ȴ�
 int num3 = true + false; num3 = 1+0
*/


//�ڷ��� bool ����1)
/*#include <iostream>
using namespace std;
int main()
{
	int num = 10;
	int i = 0;
	cout << "true : " << true << endl;
	cout << "false : " << false << endl;

	while (true)
	{
		cout << i++ << ' ';
		if (i > num)
			break;
	}
	cout << endl;
	cout << "sizeof     1 : " << sizeof(1) << endl;
	cout << "sizeof     0 : " << sizeof(0) << endl;
	cout << "sizeof  true : " << sizeof(true) << endl;
	cout << "sizeof false : " << sizeof(false) << endl;

	return 0;
}*/


/*
�ڷ��� bool
bool�� ����
true�� false�� bool�� �������̴�.
true�� false ������ ������ �� �ִ� bool�� �����̴�.
��)
bool isTrueOne = true;
bool isTrueTwo = false;
*/


//�ڷ��� bool ����2)
/*#include <iostream>
using namespace std;
bool IsPositive(int num); //������Ÿ�� ���� (�Լ� ���� ����)
int main()
{
	bool isPos;
	int num;
	cout << "Input number: ";
	cin >> num;
	isPos = IsPositive(num); //�Լ� ȣ��
	if (isPos)
		cout << "Positive number" << endl;
	else
		cout << "Negative number" << endl;

	return 0;
}
bool IsPositive(int num) //�Լ� ����
{
	if (num < 0)
		return false;
	else
		return true;
}*/


/*#include <iostream>
using namespace std;

class Rectangle { //Rectangle Ŭ���� �����
public:
	int width;
	int height;
	int getArea(); //������ ����Ͽ� �����ϴ� �Լ�
};
int Rectangle::getArea() //Rectangle Ŭ���� ������
{
	return width * height;
}

int main()
{
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "�簢�� ������ " << rect.getArea() << endl;
}*/


/*
������(constructor) : Ŭ������ ��ü�� �����ɶ� �ڵ����� ����Ǵ� �����ڶ��
					  Ư���� ��� �Լ��� ���� ��ü�� �ʱ�ȭ �Ѵ�.
Ư¡!!
1. �������� ������ ��ü�� ������ �� �ʿ��� �ʱ� �۾��� �����̴�.
2. ������ �Լ��� ���� �ѹ��� ����ȴ�.
3. ������ �Լ��� �̸��� Ŭ���� �̸��� �����ϰ� �ۼ��Ǿ�� �Ѵ�.
4. ������ �Լ��� ������ ���� Ÿ���� �������� �ʴ´�.
5. �����ڴ� �ߺ��� �����ϴ�.(�Ű������� Ÿ���� �ٸ��� ����)
*/


#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle(); //�Ű����� ���� ������
	Circle(int r); //�Ű����� �ִ� ������
	double getArea();
};

Circle::Circle(){
	radius = 1;
	cout << "������ " << radius << " �� ����" << endl;
}
Circle::Circle(int r){
	radius = r;
	cout << "������ " << radius << " �� ����" << endl;
}
double Circle::getArea() {
	return 3.14*radius*radius;
}

int main()
{
	Circle donut;
	double area = donut.getArea();
	cout << "donut ������ " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza ������ " << area << endl;
}


/*
���� �����ڰ� �ٸ� ������ ȣ��
-�ߺ��� �ڵ带 �ϳ��� �����ڷ� ȣ��
-Ŭ���� ����������� �ڵ����� �ʱ�ȭ ���� �ʱ� ������ �����ڿ��� �ʱ�ȭ�Ѵ�.

�ʱ�ȭ ��� 3����
1. ������ �ڵ忡�� ������� �ʱ�ȭ
2. ������ ���ο� �ʱⰪ���� �ʱ�ȭ
2. Ŭ�� ����ο� ���� �ʱ�ȭ

�����ڴ� �� �־�� �ϴ°�? �����ڰ� ���� Ŭ����������
�����Ϸ��� �⺻ �����ڸ� ���� �����ϰ�, ȣ���Ѵ�.

�⺻ ������
-�Ű����� ���� ������
-����Ʈ ������ : �����Ϸ��� �ڵ����� ȣ��

�����ڰ� �ϳ��� ���� Ŭ������ ��� -> �����Ϸ��� ����
�����ڰ� �ڵ����� �������� �ʴ� ��� -> �����ڰ� �ϳ��� ����� Ŭ������ ���
*/


#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle(); //���� ������
	Circle(int r); //Ÿ�� ������
	double getArea();
};

Circle::Circle() :Circle(1) {} //���� ������
Circle::Circle(int r) { //Ÿ�� ������
	radius = r;
	cout << "������ " << radius << " �� ����" << endl;
}
double Circle::getArea() {
	return 3.14*radius*radius;
}

int main()
{
	Circle donut;
	double area = donut.getArea();
	cout << "donut ������ " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza ������ " << area << endl;
}