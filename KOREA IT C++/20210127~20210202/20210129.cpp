 /*
 다운캐스팅(명시작 형변환과 비슷)
 기본 클래스 포인터가 가리키는 객체를 파생 클래스의 포인터로 가리키는 것을
 다운 캐스팅이라고 한다.
 main()함수의 다운캐스팅이 일어나며 다운캐스팅은 업캐스팅과는 달리
 명시적으로 타입변환을 지정해야한다.
 * 자식타입에 멤버변수나, 함수에 접근하기 위해서 명시적인 형변환이 필요하다.
*/


//8-2 protected 멤버함수에 대한 접근
#include <iostream>
#include <string>
using namespace std;

class Point {
protected:
	int x, y; //한점 (x,y) 좌표값
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
	showPoint(); //point클래스의 showPoint() 호출
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
	Point p; //기본 클래스 객체 생성
	p.set(2, 3); //2
	//p.x = 5; //3
	//p.y = 5; //4
	p.showPoint();

	ColorPoint cp; //파생클래스의 객체 생성
	//cp.x = 10; //5
	//cp.y = 10; //6
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint cp2; //파생클래스의 객체 생성
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2)) ? "true" : "false"); //7
}

/*
1의 코드에서는 컴파일 오류가 발생하지 않는다.
	point클래스 x,y는 protected 멤버이므로 파생클래스인 ColorPoint에서
	접근이 가능하기 때문이다.
2 set()함수가 point의 public멤버이므로 컴파일 오류가 발생하지 않는다.
3456 protected 멤버로 선언된 x,y를 접근하기 때문에 컴파일 오류발생
	(외부에서 접근 불가)
7 컴파일 오류가 발생하지 않는다.
*/


//8-3 tv, wide tv, smarttv 생성자 매개변수 전달

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
	//32인치 크기에 "192.0.0.1"의 주소를 가지는 스마트티비 객체 생성
	SmartTV htv("190.0.0.1", 32);
	cout << "size = " << htv.getSize() << endl;
	cout << "videoIn = " << boolalpha << htv.getVideoIn() << endl;
							//boolalpha는 불린 값을 true, false로 출력되게 하는 조작자
	cout << "IP = " << htv.getIpAddr() << endl;
}
