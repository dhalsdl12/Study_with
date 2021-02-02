/*
예제1)
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point();
	Point(int a, int b);
	void show() { cout << "{" << x << "," << y << "}" << endl; }
};

Point::Point() : Point(0, 0) {} //위임 생성자
Point::Point(int a, int b) //타겟 생성자
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
예제2)
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
//정사각형이면 true를 리턴하는 멤버함수
bool Rect::isSquare() {
	if (width == height) return true;
	else return false;
}
int main()
{
	Rect rect1;
	Rect rect2(3, 50);
	Rect rect3(3);

	if (rect1.isSquare()) cout << "rect1은 정사각형이다" << endl;
	if (rect2.isSquare()) cout << "rect2은 정사각형이다" << endl;
	if (rect3.isSquare()) cout << "rect3은 정사각형이다" << endl;
}
*/


/*
소멸자(destructor) : 객체가 소멸되는 시점에서 자동으로 호출되는
					클래스의 멤버함수이다.
객체가 소멸되면 객체 메모리는 시스템으로 반환된다.
또한 객체 생성시 생성자 함수가 실행되는 것 처럼 객체 소멸시 소멸자 함수가 실행된다.
특징:
1. 소멸자의 목적은 객체가 사라질 때 필요한 마무리 작업을 위함이다.
2. 소멸자의 이름은 클래스 이름 앞에 ~을 붙인다.
3. 소멸자는 리턴 타입이 없으며 어떤 값도 리턴해서도 안된다.
4. 소멸자는 오직 한개만 존재하며 매개변수를 가지지 않는다.
5. 소멸자가 선언되어 있찌 않으면 기본 소멸자(default destructor)가 자동으로 생성된다.

*/


/*
#include <iostream>
using namespace std;

class Circle {
public:
	int radius; //멤버변수

	Circle(); //생성자
	Circle(int r); //생성자
	~Circle(); //소멸자
	double getArea(); //멤버함수
};

Circle::Circle() { //생성자 구현
	radius = 1;
	cout << "반지름 " << radius << "  원 생성" << endl;
}
Circle::Circle(int r) { //생성자 구현
	radius = r;
	cout << "반지름 " << radius << "  원 생성" << endl;
}
Circle::~Circle() { //소멸자 구현
	cout << "반지름 " << radius << "  원 소멸" << endl;
} //객체 생성의 반대순으로 소멸
double Circle::getArea() { //멤버함수 구현
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
객체 생성 순서
전역 객체는 프로그램에 선언된 순서로 생서
지역 객체는 함수가 호출되는 순간에 순서대로 생성

객체 소멸 순서
함수가 종료하면, 지역객체가 생성된 순서의 역순으로 소멸
프로그램이 종료하면, 전역객체가 생성된 순서의 역순으로 소멸
*/


/*
#include <iostream>
using namespace std;

class Circle {
public:
	int radius; //멤버변수

	Circle(); //생성자
	Circle(int r); //생성자
	~Circle(); //소멸자
	double getArea(); //멤버함수
};

Circle::Circle() { //생성자 구현
	radius = 1;
	cout << "반지름 " << radius << "  원 생성" << endl;
}
Circle::Circle(int r) { //생성자 구현
	radius = r;
	cout << "반지름 " << radius << "  원 생성" << endl;
}
Circle::~Circle() { //소멸자 구현
	cout << "반지름 " << radius << "  원 소멸" << endl;
} //객체 생성의 반대순으로 소멸
double Circle::getArea() { //멤버함수 구현
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
인라인 함수를 호출하는 곳에 인라인 함수 코드를 확장 삽입
	매크로와 유사
	코드확장후 인라인 함수는 사라짐
인라인 함수 호출
	함수 호출에 따른 오버헤드 존재하지 않음
	프로그램의 실행속도 개선
인라인 함수 제약사항
	컴파일에게 주는 요구하는 메세지
	컴파일러가 판단하여 요구를 수용할지 결정
	recursion, static변수, for, switch, goto문 등 긴함수를 가진 함수를 제약
*/


/*
<참고>
생성자를 private, protected로 선언하는 경우
생성자가 public이 아니면 외부에서 객체를 생성할 수 없다.
그러면 생성자는 항상 public으로 생성해야 하는가?
아니다. 의도적으로 외부에서 객체를 생성할 수 없도록 생성자를 private로 선언하기도 하고,
자식 클래스에서만 생성자를 호출하도록 protected로 선언하기도 한다.
*/


/*
인라인 함수란 :
  - 짧은 코드로 구성된 함수에 대해, 함수 호출 오버헤드로 인한
  프로그램 실행속도 저하를 막기 위해 도입한 기능이다.
  - 컴파일러는 인라인 함수를 호출하는 곳에 인라인 함수의 코드를 그대로 삽입하여
  함수 호출이 일어나지 않게한다. 이렇게 함수호출 오버헤드가 없어지기 때문에
  함수 실행 속도가 빨라진다.
  - c++에서는 멤버함수의 크기가 작을경우, 클래스의 선언부에 직접 구현하여도 무방하다.
  - 컴파일러는 클래스의 선언부에 구현된 멤버함수들에 대해서
  inline선언이 없어도 인라인 함수로 자동처리한다.
*/

//예제3
/*
#include <iostream>
using namespace std;
//C++ 구조체 선언
struct StructCircle { //struct의 defult 접근 지정자는 public이다.
private:
	int radius;
public:
	StructCircle(int r) { radius = r; } //구조체 생성자
	double getArea();
};
double StructCircle::getArea() {
	return 3.14*radius*radius;
}

int main()
{
	StructCircle waffle(3);
	cout << "면적은 " << waffle.getArea();
}
*/

/*
<참구>
구조체보다 클래스를 사용하라.
구조체 클래스가 거의 같다면 구조체와 클래스 중 어떤것을 사용하는 것이 좋을까?
정답은 없다. 개발자에 따라 멤버변수만 있는 자료구조의 경우 구조체를 사용하기도 한다.
다만, C언어의 사고의 탈피를 위해 구조체의 사용을 피하는 것이 좋다.
구조체와 클래스를 함께 사용하면서 스스로 혼란을 줄 필요가 없다.
*/


/*
헤더파일을 만들때 위에
#ifndef CIRCLE_H
#define CIRCLE_H
마지막에
#endif
하면 여려번 Circle.h를 불러와도 문제가 되지 않는다.
*/