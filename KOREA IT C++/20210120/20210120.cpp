/*
�������� ����
int num1 = 2020; //������ �������� ���� num1�̶�� �̸����� �޸� ������ �Ҵ�ȴ�.
int &num2 = num1; //�������� �������� ���ؼ� num1�� �޸� ������ num2��� �̸��� �߰��� �ٰԵȴ�.
�����ڴ� ������ ����� ������ ���̴� '��Ī'�̴�.
�׸��� �̷��� �����ڰ� ��������� �̴� ������ �̸��� ��ǻ� ���̰� �ִ�.
*/


//������ ���� ���� �� ����
/*
#include <iostream>
using namespace std;
int main()
{
	int num1 = 2020;
	int &num2 = num1; //num2�� num1�� �������̴�. ���� ���ĺ��ʹ� num1�� �ϴ�
					  //��� ������ num2�� �ϴ°Ͱ� ������ ����� ���δ�.
	cout << "VAL : " << num1 << endl;
	cout << "REF : " << num2 << endl;
	cout << "VAL : " << &num1 << endl;
	cout << "REF : " << &num2 << endl;
	
	return 0;
}
*/


/*
�������� ������ ������ ������, �����ڸ� ������� �����ڸ� �����ϴ°͵� �����ϴ�.
int num1 = 1234;
int &num2 = num1;
int &num3 = num1;
int &num4 = num1;
*/


/*
������ ���� ���ɹ��� : �Ұ����� ������ ������ ��
int &ref = 20; //��� ������δ� ������ ������ �Ұ����ϴ�.
int &ref; //�����ڴ� ������ ���ÿ� �������� �����ؾ��Ѵ�.
int &ref = NULL; //������ó�� NULL�� �ʱ�ȭ�ϴ� ���� �Ұ����ϴ�.
�����ڴ� ����� ���ÿ� �������� �����ؾ��ϴµ� �� ������ ����� �⺻������ ������ �Ǿ���Ѵ�.
�׸��� �����ڴ� ������ ����� ������ �� ����.
*/


//������ ���� ����)
/*
#include <iostream>
using namespace std;

int main()
{
	int arr[3] = { 1,2,3 };
	int &ref1 = arr[0]; //������ ������ ������ ����̶�� ������ ������ �����ϴ�.
	int &ref2 = arr[1]; //�迭�� ��� ���� ������ ������ ���ϱ� ������
	int &ref3 = arr[2]; //������ ������ �����ϴ�.

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;

	return 0;
}
*/


//������ ���� ����� ������ ����
/*
#include <iostream>
using namespace std;

int main()
{
	int num1 = 20;
	int *ptr = &num1;
	int **dptr = &ptr;

	int &ref = num1;
	int *(&pref) = ptr; //ptr�� dptr���� �����̴�. �ٸ� �ּҰ��� �����ϴ� ������ �����̴�.
	int **(&dpref) = dptr; //���� ������ ������ �����ϴ�.

	cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;

	return 0;
};
*/ 


/*
<����>
�ʱ�ȭ ���� ���� ��ü �����͸� �̿��ϸ� ���� �߻�
Circle *p;
p->getArea() //�����߻�
������ ���� p�� � CircleŸ���� ��ü�� ����Ű�� ���� ���¿���
getArea() �Լ��� ȣ���ϱ� ������, ������ 'null pointer assignment' ������ �߻��Ѵ�.
*/


/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() :Circle(1) {};
	Circle(int r) { radius = r; }
	double getArea();
};
double Circle::getArea() {
	return 3.14*radius*radius;
}

int main()
{
	Circle donut;
	Circle pizza(30);

	//��ü�̸����� ����
	cout << donut.getArea() << endl;

	//��ü �����ͷ� ����
	Circle *p = &donut;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;

	p = &pizza;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;
}
*/


/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() :Circle(1) {};
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};
double Circle::getArea() {
	return 3.14*radius*radius;
}

int main()
{
	Circle circleArray[3]; //��ü �迭 ����

	for (int i = 0; i < 3; i++)
	{
		int r;
		cin >> r;
		circleArray[i].setRadius(r);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "�� ���� " << circleArray[i].getArea() << endl;
	}
	Circle *p = circleArray;
	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "�� ���� " << p->getArea() << endl;
		p++;
	}
}
*/


/*
�迭 �Ҹ�� �Ҹ���
�Լ��� �����ϸ� �Լ� ���� ����� �迭�� �Ҹ�ȴ�.
�迭�� �Ҹ�Ǹ� ��� ���� ��ü�� �Ҹ�Ǹ� �� ���� ��ü���� �Ҹ��ڰ� ȣ��ȴ�.
main() �Լ��� ����Ǹ� circleArray �迭�� �Ҹ�Ǹ�, ���� �ε����������� ���� ��ü�� �Ҹ�ǰ�,
�� ��ü���� ~Circle() �Ҹ��ڰ� ����ȴ�.
circleArray[2] �Ҹ��� ���� -> circleArray[1] �Ҹ��� ���� -> circleArray[0] �Ҹ��� ����

<����> ��ü �����͸� ����Ͽ� ��ü �迭�� �ٷ�� �پ��� ���
��ü �����͸� �̿��Ͽ� circleArray�� �� Circle ��ü�� ������ ����ϴ� �ڵ带
�پ��ϰ� �ۼ��Ҽ� �ִ�

1) ������ p�� �̿��Ͽ� ��üó�� ����
Circle *p = circleArray;
for(int i = 0l i < 3; i++)
	cout << (*p++).getArea() << endl;

2) �迭�� �̸� circleArray�� �����ͷ� ���
for(int i = 0; i < 3; i++)
	cout << (circleArray + i)->getArea() << endl;

3) ������ p�� �������� �̿�
Circle *p = circleArray;
for(int i = 0; i < 3; i++)
	cout << (p+i)->getArea() << endl;
*/


//����! ��ü�迭 �ʱ�ȭ
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() :Circle(1) {};
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};
double Circle::getArea() {
	return 3.14*radius*radius;
}
int main()
{
	Circle circleArray[3] = { Circle(10), Circle(20), Circle() };
	//circleArray[0] ��ü�� �����ɶ�, ������ Circle(10)
	//circleArray[1] ��ü�� �����ɶ�, ������ Circle(20)
	//circleArray[2] ��ü�� �����ɶ�, ������ Circle()
	//�� ȣ��ȴ�
	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "�� ������ " << circleArray[i].getArea() << endl;
	}
	return 0;
}