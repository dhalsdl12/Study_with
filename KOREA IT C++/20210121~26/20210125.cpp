/*
- ���� ���� ȣ��� �ּҿ� ���� ȣ�� Ư¡
���� ���� ȣ�� : �����ڰ��� �����Ͽ� �����ϹǷ� �Լ������� �����ڸ�
�ջ��ų�� ���� ������ �ִ�.
�׷��Ƿ� �Լ� ȣ�⿡ ���� ���ۿ��� ����.

�ּҿ� ���� ȣ�� : �������� �ּҸ� �Ѱ��־� �ǵ������� �Լ� ������
�������� ���� �����ϰ��� �Ҷ� �̿�ȴ�.
*/


/*
<����>
���� ���� ȣ�� �� ��ü ���� �ð�
'���� ���� ȣ��'�� �Լ� �ȿ��� �Ű����� ��ü�� � ��ȭ�� �Ͼ��
������(������ü)�� �Ѽ� ��Ű�� �ʴ� ������ �Ҵ� �ݸ�,
������ ��ü�� ũ�Ⱑ ũ�� ��ü�� �����ϴ� �ð��� Ŀ���� ������ �ִ�.
*/

//���� 5-1 '���� ���� ȣ��'�� �Ű������� �����ڰ� ������� ����
/*
#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(); //������
	Circle(int r); //�Ű����� �ִ� ������
	~Circle(); //�Ҹ���
	double getArea() { return 3.14*radius*radius; } //����Լ�
	int getRadius() { return radius; } //����Լ�
	void setRAdius(int radius){ //����Լ�
		this->radius = radius;
	}
};
Circle::Circle() {
	radius = 1;
	cout << "������ ����  radius = " << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << "������ ����  radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "�Ҹ��� ����  radius = " << radius << endl;
}
void increase(Circle c) //waffle�� ������ �״�� C�� �����
{
	int r = c.getRadius();
	c.setRAdius(r + 1);
}
int main()
{
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
}
*/

/*
#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(); //������
	Circle(int r); //�Ű����� �ִ� ������
	~Circle(); //�Ҹ���
	double getArea() { return 3.14*radius*radius; } //����Լ�
	int getRadius() { return radius; } //����Լ�
	void setRAdius(int radius) { //����Լ�
		this->radius = radius;
	}
};
Circle::Circle() {
	radius = 1;
	cout << "������ ����  radius = " << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << "������ ����  radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "�Ҹ��� ����  radius = " << radius << endl;
}
void increase(Circle *c)
{
	int r = c->getRadius();
	c->setRAdius(r + 1);
}
int main()
{
	Circle waffle(30);
	increase(&waffle);
	cout << waffle.getRadius() << endl;
}
*/


/*
<����> ���������
'���� ���� ȣ��'��, �����Ϸ��� �Ű����� ��ü�� ������ ��� ���� �����ڰ�
ȣ��ǵ��� ������ �ϱ� ������, �����ڰ� ������� �ʴ� ���̴�.
�����Ϸ��� Ŭ������ ���� �����ڰ� �ۼ��Ǿ� ���� ���� ���,
������ ��ü�� ��� ������ 1:1�� �Ű����� ��ü�� �����ϴ�
����Ʈ ���� �����ڸ� �ڵ����� �����Ѵ�.
*/


/*
��ü ġȯ :
- ��ü ġȯ �� ��ü�� ��� �����Ͱ� ��Ʈ ������ ����ȴ�.
- ��ü ġȯ �� c1�� c2�� ������ ������ ����. ������ ���빰�� ���� ���̴�.
- ��ü ġȯ�� ������ Ŭ���� Ÿ�Կ� ���ؼ��� ����ȴ�.
*/

/*
�Լ��� ��ü ����
return ���� ����Ǹ� tmp�� ���纻�� ����� ���纻�� getCircle()�� ȣ���� ������
���޵ȴ�. �׸��� tmp�� �Ҹ�ȴ�.
��ü c�� �����ɶ� �������� 1�̾�����, getCircle()�� ������ tmp��ü�� ġȯ�Ǹ�
��ü c�� �������� 30�� �ȴ�.
*/

//���� 5-3 ��ü ����
/*
#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int Radius) { this->radius = radius; }
	double getArea() { return 3.17*radius*radius; }
};
Circle getCircle() {
	Circle tmp(30);
	return tmp; //��ütmp�� �����Ѵ�. (���纻 ����)
}
int main()
{
	Circle c;
	cout << c.getArea() << endl; //��ü�� �����ȴ�. radius = 1�� �ʱ�ȭ�ȴ�.

	c = getCircle();
	cout << c.getArea() << endl; //tmp��ü�� c�� ����ȴ�.
}
*/


/*
����(reference)
������ ������ �����ϱ� ���� *��ȣ�� ���������, ���������� �����ϱ����� &��ȣ�� ����Ѵ�.

- & : ������
- ������ ����Ų�ٴ� ��, ���������� �̹� ����� ������ ���� ����(alias)
- �����, �ݵ�� ���������� �ʱ�ȭ�Ͽ����Ѵ�.  int &refn; �ȵȴ�
- refn�� refc�� �̸��� �����Ǹ�, ������ ������ �Ҵ���� �ʴ´�.
  ��� ���������� �ʱ�ȭ�� ������ ���� ������ ������ �����Ѵ�.
- ���������� ���� ����� �ٷ� ���� ������ ����̴�.
- ���������� �����Ͱ� �ƴϹǷ� refc->setRadius(30); //������ ����
refc.setRadius(30); �� ����ؾ� �Ѵ�.
*/

/*
���������� ���� �����͸� ���� �� �ִ�
int *p = &refn;
*p = 20;
*/

/*
- �������� ����� ���ǻ���
1. �ʱ�ȭ�� ���ٸ� ������ ������ �߻��Ѵ�.
2. ������ &�� ��ġ�� �����ϴ�.
int &refn = n;
int & refn = n;
int&refn = n;
3. ������ &�� ��뿡 �����ؾ� �Ѵ�. ���������� �߸��� �������� ����.
& int refn = n;
int refn & = n;
4. ���� ������ �迭�� ���� �� ����.
char &n[10];
5. ���������� ���� ���� ������ �����ϴ�.
*/


//���� 5-3 �⺻ Ÿ�Կ� ���� ���� ����
/*
#include <iostream>
using namespace std;

int main()
{
	cout << "i\tn\trefn" << endl;
	int i = 1, n = 2;
	int &refn = n; //�������� refn ����. refn�� n�� ���� ����
	n = 4;
	refn++; // refn = 5, n = 5
	cout << i << '\t' << n << '\t' << refn << endl;

	refn = i; // refn = 1, n = 1
	refn++; //refn = 2, n = 2
	cout << i << '\t' << n << '\t' << refn << endl;

	int *p = &refn;
	*p = 20; //refn = 20, n = 20
	cout << i << '\t' << n << '\t' << refn << endl;
}
*/

/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};
int main()
{
	Circle circle; //��ü����
	Circle &refc = circle; // circle��ü�� ���� �������� refc����
	refc.setRadius(10);
	cout << refc.getArea() << '\t' << circle.getArea() << endl;
}
*/



/*
���� 5-5 ���� �Ű������� ��� �����ϱ�
���� �Ű������� ���� ����� �����ϰ� ���Ϲ��� ���ؼ��� �Լ��� �������θ�
�����ϵ��� average() �Լ��� �ۼ��϶�
*/

/*
#include <iostream>
using namespace std;

bool average(int a[], int size, double &avg) //�����Ű����� avg�� ��հ� ����
{
	if (size <= 0)
		return false;
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += a[i];
	}
	avg = sum / double(size);
	return true;
}
int main()
{
	int x[] = { 0,1,2,3,4,5 };
	double avg;
	if (average(x, 6, avg))
		//avg�� ����� �Ѿ����, average()�� true ����
		cout << "����� " << avg << endl;
	else
		cout << "�Ű����� ����" << endl;
	
	if (average(x, -2, avg))
		//avg�� ���� �ǹ̾���, average()�� false����
		cout << "����� " << avg << endl;
	else
		cout << "�Ű����� ����" << endl;
}
*/


//���� 5-6 ������ ���� ȣ��� Circle��ü�� ���� ����
/*
#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(); //������
	Circle(int r); //�Ű����� �ִ� ������
	~Circle(); //�Ҹ���
	double getArea() { return 3.14*radius*radius; } //����Լ�
	int getRadius() { return radius; } //����Լ�
	void setRAdius(int radius) { //����Լ�
		this->radius = radius;
	}
};
Circle::Circle() {
	radius = 1;
	cout << "������ ����  radius = " << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << "������ ����  radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "�Ҹ��� ����  radius = " << radius << endl;
}
void increase(Circle &c) //���� �Ű����� c
{
	int r = c.getRadius();
	c.setRAdius(r + 1);
}
int main()
{
	Circle waffle(30);
	increase(waffle); //������ ���� ȣ��
	cout << waffle.getRadius() << endl;
}
*/

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};
void readRadius(Circle &c)
{
	cout << "���� ������ �������� �Է��ϼ��� >> ";
	int radius;
	cin >> radius;
	c.setRadius(radius);
}
int main()
{
	Circle donut;
	readRadius(donut);
	cout << "donut�� ���� = " << donut.getArea() << endl;
}