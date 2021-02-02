//Ŭ������� �������������ڷ� static����� �����ϴ� �ڵ� ����
/*
#include <iostream>
using namespace std;

class Person {
public:
	int money;
	void addMoney(int money)
	{
		this->money += money;
	}
	static int sharedMoney;
	static void addshared(int n)
	{
		sharedMoney += n;
	}
};
//static ���� ����. ���� ������ ����
int Person::sharedMoney = 10;

int main()
{
	Person::addshared(50);
	cout << Person::sharedMoney << endl;

	Person han;
	han.money = 100;
	han.sharedMoney = 200; //static ��� ����. ���� = 200
	Person::sharedMoney = 300; //static ��� ����. ���� = 300
	Person::addshared(100); //static ��� ����. ���� = 400

	cout << han.money << ' ' << Person::sharedMoney << endl;
}
*/


//6-11 static ����� ������ �������� ����ϴ� ��
/*
#include <iostream>
using namespace std;
class Circle {
private:
	static int numOfCircles;
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircles--; } //������ ���� ���� ����
	double getArea() { return 3.14*radius*radius; }
	static int getNumOfCircles() { return numOfCircles; }
};
int Circle::numOfCircles = 0; //0���� �ʱ�ȭ
Circle::Circle(int r)
{
	radius = r;
	numOfCircles++; //������ ���� ���� ����
}
int main()
{
	Circle *p = new Circle[10]; //10���� ������ ����
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;
	
	delete[] p; //10���� �Ҹ��� ����
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;

	Circle a; //������ ����
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;

	Circle b; //������ ����
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;

	return 0;
}
*/


//----------------------�� ��---------------------
/*
<����> ��� ���迡 �ִ� �� Ŭ������ �̸�
��� ���迡 �ִ� �� Ŭ������ �θ��� �̸��� ���α׷��� ���� ���� �ٸ���.
 Java������ ������ִ� Ŭ������ ����Ŭ������ ��ӹ޴� Ŭ������ ���� Ŭ������� �θ���
 c#������ �θ�Ŭ����, �ڽ�Ŭ������ ���� �θ���.
*/

/*
����� ������ ����
1. ������ Ŭ���� �ۼ�
������ �ڵ尡 ���� Ŭ������ �ߺ��Ǹ� Ŭ������ ���������� ���ŷο� ���� �Ͼ��.
����� �̿��ϸ� �� ������ ������ �ذ�ȴ�.
����� Ŭ������ ������ �ߺ��� �����Ͽ� Ŭ������ �����ϰ� ������ �� �ְ� �Ѵ�.

2. Ŭ���� ���� ������ �з� �� ������ ������
- ����� ���� ���õ� Ŭ������ ��������� ǥ�������ν�, ���α׷��� �����ϴ� Ŭ��������
�������� ���� �ľ��� ���� ���ش�.
���� ����� ǥ���Ǹ� Ŭ������ ��ü�� ������ �����ϴ�.

3. Ŭ���� ����� Ȯ���� ���� ����Ʈ������ ���꼺 ���
- ���� ū ���� : ����Ʈ���� ���꼺�� ����ϴµ� �ִ�.
����� ������ �ۼ��� ���� Ŭ������ ��ӹް� ����� Ȯ���Ͽ� ���ο� ����Ʈ���
���� �ð� ���� ����� �� �� �ְ� �Ѵ�. ����Ʈ���� ���꼺�� ��������.
*/

/*
<����> �������
����� �ʿ��ϴٴ� ���������� �������� ���� Ŭ������ ����ؼ��� �ȵȴ�.
���� �����ִ� Ŭ�������� ��Ӱ���� �����Ͽ��� ��ü ������ �v���� ��Ƴ���,
�ڵ��� ������ ��������.
������� �ڵ��� Ŭ������ ���鶧, ����� Ŭ������ �̹� ������� ���� �����
����ϰ��� ����� Ŭ������ ��ӹ����� �ȵȴ�.
�̰��� �ϴ��� ���� �ڵ����� �ۼ��Ѵٴ� ���� �Ǳ� �����̴�.
*/

//8-1  point Ŭ���� ��ӹ޴� colorpoint ����
/*
#include <iostream>
using namespace std;
#include <string>

//2���� ��鿡�� �� ���� ǥ���ϴ� Ŭ���� point ����
class Point {
	int x, y; //���� (x,y) ��ǥ��
public:
	void set(int x, int y) { 
		this->x = x; 
		this->y = y; 
	}
	void showPoint() {
		cout << '(' << x << ',' << y << ')';
	}
};
class ColorPoint : public Point{ //2���� ��鿡�� �÷� ���� ǥ���ϴ� Ŭ����
												//colorpoint. point�� ��ӹ���
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};
void ColorPoint::showColorPoint()
{
	cout << color << ": ";
	showPoint(); //Point�� showPoint() ȣ��
}
int main()
{
	Point p; //�⺻ Ŭ������ ��ü ����
	ColorPoint cp; //�Ļ� Ŭ������ ��ü ����
	cp.set(3, 4); //�⺻ Ŭ������ ��� ȣ��
	cp.setColor("Red"); //�Ļ�Ŭ������ ���ȣ��
	cp.showColorPoint(); //�Ļ�Ŭ������ ���ȣ��
}
*/


/*
���ɽ���(�ڵ�����ȯ�� ���)
��ĳ�����̶� : �Ļ�Ŭ������ ��ü�� �⺻ Ŭ������ �����ͷ� ����Ű�� ���� ���Ѵ�.
��ĳ������ �Ļ� Ŭ������ ��ü�� �⺻ Ŭ������ ��üó�� �ٷ� �� �ְ� �Ѵ�.
�̰��� �Ļ�Ŭ������ ��ü�� �⺻ Ŭ������ ����� �����ϱ� ������ �����ϴ�.

��ĳ�����̶� �⺻ Ŭ������ �����ͷδ� �⺻ Ŭ������ ����� ������ �� �ִ�.
��ĳ���� ��  Point* pbase =(Point*)pDer; �� ���� ����� Ÿ�� ��ȯ�� �ʿ� ����.
�ֳ��ϸ� cp��ü�� ColorPointŸ�������� pointŸ���̱⵵ �ϱ� �����̴�.
��? �⺻Ŭ������ �Ļ�Ŭ������ ����Ű�� �ߴ°�?
�ڽ� ��ü�� ���� �����Ǿ������� �θ� Ŭ������ �ڽ� Ŭ������ �� ����ų �� �ִ�.
*/


