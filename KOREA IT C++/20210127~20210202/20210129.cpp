 /*
 �ٿ�ĳ����(����� ����ȯ�� ���)
 �⺻ Ŭ���� �����Ͱ� ����Ű�� ��ü�� �Ļ� Ŭ������ �����ͷ� ����Ű�� ����
 �ٿ� ĳ�����̶�� �Ѵ�.
 main()�Լ��� �ٿ�ĳ������ �Ͼ�� �ٿ�ĳ������ ��ĳ���ð��� �޸�
 ��������� Ÿ�Ժ�ȯ�� �����ؾ��Ѵ�.
 * �ڽ�Ÿ�Կ� ���������, �Լ��� �����ϱ� ���ؼ� ������� ����ȯ�� �ʿ��ϴ�.
*/


//8-2 protected ����Լ��� ���� ����
#include <iostream>
#include <string>
using namespace std;

class Point {
protected:
	int x, y; //���� (x,y) ��ǥ��
public:
	void set(int x, int y);
	void showPoint();
};
void Point::set(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Point::showPoint()
{
	cout << "(" << x << "," << y << ")" << endl;
}
class ColorPoint : public Point {
	string color;
public:
	void setColor(string color);
	void showColorPoint();
	bool equals(ColorPoint p);
};

void ColorPoint::setColor(string color)
{
	this->color = color;
}
void ColorPoint::showColorPoint()
{
	cout << color << " : ";
	showPoint(); //pointŬ������ showPoint() ȣ��
}
bool ColorPoint::equals(ColorPoint p)
{


if (x == p.x && y = p.y && color == p.color) //1
		return true;
	else
		return false;
}
int main()
{
	Point p; //�⺻ Ŭ���� ��ü ����
	p.set(2, 3); //2
	//p.x = 5; //3
	//p.y = 5; //4
	p.showPoint();

	ColorPoint cp; //�Ļ�Ŭ������ ��ü ����
	//cp.x = 10; //5
	//cp.y = 10; //6
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint cp2; //�Ļ�Ŭ������ ��ü ����
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2)) ? "true" : "false"); //7
}

/*
1�� �ڵ忡���� ������ ������ �߻����� �ʴ´�.
	pointŬ���� x,y�� protected ����̹Ƿ� �Ļ�Ŭ������ ColorPoint����
	������ �����ϱ� �����̴�.
2 set()�Լ��� point�� public����̹Ƿ� ������ ������ �߻����� �ʴ´�.
3456 protected ����� ����� x,y�� �����ϱ� ������ ������ �����߻�
	(�ܺο��� ���� �Ұ�)
7 ������ ������ �߻����� �ʴ´�.
*/


//8-3 tv, wide tv, smarttv ������ �Ű����� ����

#include <iostream>
#include <string>
using namespace std;

class TV {
	int size;
public:
	TV() { size = 20; }
	TV(int size) { this->size = size; }
	int getSize() { return size; }
};
class WideTV : public TV {
	bool videoIn;
public:
	WideTV(int size, bool videoIn) :TV(size) {
		this->videoIn = videoIn;
	}
	bool getVideoIn() { return videoIn; }
};
class SmartTV :public WideTV {
	string ipAddr;
public:
	SmartTV(string ipAddr, int size) :WideTV(size, true) {
		this->ipAddr = ipAddr;
	}
	string getIpAddr() { return ipAddr; }
};

int main()
{
	//32��ġ ũ�⿡ "192.0.0.1"�� �ּҸ� ������ ����ƮƼ�� ��ü ����
	SmartTV htv("190.0.0.1", 32);
	cout << "size = " << htv.getSize() << endl;
	cout << "videoIn = " << boolalpha << htv.getVideoIn() << endl;
							//boolalpha�� �Ҹ� ���� true, false�� ��µǰ� �ϴ� ������
	cout << "IP = " << htv.getIpAddr() << endl;
}
