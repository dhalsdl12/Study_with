//클래스명과 범위지정연산자로 static멤버에 접근하는 코드 예제
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
//static 변수 생성. 전역 공간에 생성
int Person::sharedMoney = 10;

int main()
{
	Person::addshared(50);
	cout << Person::sharedMoney << endl;

	Person han;
	han.money = 100;
	han.sharedMoney = 200; //static 멤버 접군. 공금 = 200
	Person::sharedMoney = 300; //static 멤버 접군. 공금 = 300
	Person::addshared(100); //static 멤버 접군. 공금 = 400

	cout << han.money << ' ' << Person::sharedMoney << endl;
}
*/


//6-11 static 멤버를 공유의 목적으로 사용하는 예
/*
#include <iostream>
using namespace std;
class Circle {
private:
	static int numOfCircles;
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircles--; } //생성된 원의 개수 감소
	double getArea() { return 3.14*radius*radius; }
	static int getNumOfCircles() { return numOfCircles; }
};
int Circle::numOfCircles = 0; //0으로 초기화
Circle::Circle(int r)
{
	radius = r;
	numOfCircles++; //생성된 원의 개수 증가
}
int main()
{
	Circle *p = new Circle[10]; //10개의 생성자 실행
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
	
	delete[] p; //10개의 소멸자 실행
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

	Circle a; //생성자 실행
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

	Circle b; //생성자 실행
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

	return 0;
}
*/


//----------------------상 속---------------------
/*
<참고> 상속 관계에 있는 두 클래스의 이름
상속 관계에 있는 두 클래스를 부르는 이름은 프로그래밍 언어마다 서로 다르다.
 Java에서는 상속해주는 클래스를 슈퍼클래스로 상속받는 클래스를 서브 클래스라고 부른다
 c#에서는 부모클래스, 자식클래스로 각각 부른다.
*/

/*
상속의 목적과 장점
1. 간결한 클래스 작성
동일한 코드가 여러 클래스에 중복되면 클래스의 유지보수에 번거로운 일이 일어난다.
상속을 이용하면 이 문제는 간단히 해결된다.
상속은 클래스들 사이의 중복을 제거하여 클래스를 간결하게 구현할 수 있게 한다.

2. 클래스 간의 계층적 분류 및 관리의 용이함
- 상속은 서로 관련된 클래스를 계층관계로 표현함으로써, 프로그램에 존재하는 클래스들의
구조적인 고나계 파악을 쉽게 해준다.
계층 관계로 표현되면 클래스나 객체의 관리가 용이하다.

3. 클래스 재사용과 확장을 통한 소프트웨어의 생산성 향상
- 가장 큰 장점 : 소프트웨어 생산성을 향상하는데 있다.
상속은 기존에 작성해 놓은 클래스를 상속받고 기능을 확장하여 새로운 소프트웨어를
빠른 시간 내에 만들어 낼 수 있게 한다. 소프트웨어 생산성이 높아진다.
*/

/*
<참고> 상속주의
기능이 필요하다는 이유만으로 연관성이 없는 클래스를 상속해서는 안된다.
서로 관련있는 클래스들을 상속관계로 정의하여야 객체 지향적 틍성이 살아나며,
코드의 재사용이 높아진다.
예를들어 자동차 클래스를 만들때, 비행기 클래스에 이미 만들어진 엔진 기능을
사용하고자 비행기 클래스를 상속받으면 안된다.
이것은 하늘을 나는 자동차를 작성한다는 뜻이 되기 때문이다.
*/

//8-1  point 클래스 상속받는 colorpoint 선언
/*
#include <iostream>
using namespace std;
#include <string>

//2차원 평면에서 한 점을 표현하는 클래스 point 선언
class Point {
	int x, y; //한점 (x,y) 좌표값
public:
	void set(int x, int y) { 
		this->x = x; 
		this->y = y; 
	}
	void showPoint() {
		cout << '(' << x << ',' << y << ')';
	}
};
class ColorPoint : public Point{ //2차원 평면에서 컬러 점을 표현하는 클래스
												//colorpoint. point를 상속받음
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};
void ColorPoint::showColorPoint()
{
	cout << color << ": ";
	showPoint(); //Point의 showPoint() 호출
}
int main()
{
	Point p; //기본 클래스의 객체 생성
	ColorPoint cp; //파생 클래스의 객체 생성
	cp.set(3, 4); //기본 클래스의 멤버 호출
	cp.setColor("Red"); //파생클래스의 멤버호출
	cp.showColorPoint(); //파생클래스의 멤버호출
}
*/


/*
업케스팅(자동형변환과 비슷)
업캐스팅이란 : 파생클래스의 객체를 기본 클래스의 포인터로 가리키는 것을 말한다.
업캐스팅은 파생 클래스의 객체를 기본 클래스의 객체처럼 다룰 수 있게 한다.
이것은 파생클래스의 객체가 기본 클래스의 멤버를 포함하기 때문에 가능하다.

업캐스팅이란 기본 클래스의 포인터로는 기본 클래스의 멤버만 접근할 수 있다.
업캐스팅 시  Point* pbase =(Point*)pDer; 와 같이 명시적 타입 변환이 필요 없다.
왜냐하면 cp객체는 ColorPoint타입이지만 point타입이기도 하기 때문이다.
왜? 기본클래스로 파생클래스만 가리키게 했는가?
자식 객체가 많이 생성되었을때도 부모 클래스가 자식 클래스를 다 가리킬 수 있다.
*/


