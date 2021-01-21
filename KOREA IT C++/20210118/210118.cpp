/*
새로운 자료형 bool
 true는 '참'을 의미하는 1바이트 데이터이고,  false는 '거짓'을 의미하는 1바이트 데이터이다.
 이 둘은 각각 정수 1과 0이 아니다.
 그러나 정수가 와야할 위치에 오게되면 각각 1과 0으로 반환된다.
 예)
 int num1 = true; num1에는 1이 저장된다
 int num2 = false; num2에는 0이 저장된다
 int num3 = true + false; num3 = 1+0
*/


//자료형 bool 예제1)
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
자료형 bool
bool의 이해
true와 false는 bool형 데이터이다.
true와 false 정보를 저장할 수 있는 bool형 변수이다.
예)
bool isTrueOne = true;
bool isTrueTwo = false;
*/


//자료형 bool 예제2)
/*#include <iostream>
using namespace std;
bool IsPositive(int num); //프로토타입 선언 (함수 원형 선언)
int main()
{
	bool isPos;
	int num;
	cout << "Input number: ";
	cin >> num;
	isPos = IsPositive(num); //함수 호출
	if (isPos)
		cout << "Positive number" << endl;
	else
		cout << "Negative number" << endl;

	return 0;
}
bool IsPositive(int num) //함수 정의
{
	if (num < 0)
		return false;
	else
		return true;
}*/


/*#include <iostream>
using namespace std;

class Rectangle { //Rectangle 클래스 선언부
public:
	int width;
	int height;
	int getArea(); //면적을 계산하여 리턴하는 함수
};
int Rectangle::getArea() //Rectangle 클래스 구현부
{
	return width * height;
}

int main()
{
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "사각형 면적은 " << rect.getArea() << endl;
}*/


/*
생성자(constructor) : 클래스는 객체가 생성될때 자동으로 실행되는 생성자라는
					  특별한 멤버 함수를 통해 객체를 초기화 한다.
특징!!
1. 생성자의 목적은 객체가 생성될 때 필요한 초기 작업을 위함이다.
2. 생성자 함수는 오직 한번만 실행된다.
3. 생성자 함수의 이름은 클래스 이름과 동일하게 작성되어야 한다.
4. 생성자 함수의 원형에 리턴 타입을 선언하지 않는다.
5. 생성자는 중복이 가능하다.(매개변수나 타입을 다르게 선언)
*/


#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle(); //매개변수 없는 생성자
	Circle(int r); //매개변수 있는 생성자
	double getArea();
};

Circle::Circle(){
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}
Circle::Circle(int r){
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}
double Circle::getArea() {
	return 3.14*radius*radius;
}

int main()
{
	Circle donut;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}


/*
위임 생성자가 다른 생성자 호출
-중복된 코드를 하나의 생성자로 호출
-클래스 멤버변수들은 자동으로 초기화 되지 않기 때문에 생상자에서 초기화한다.

초기화 방법 3가지
1. 생성자 코드에서 멤버변수 초기화
2. 생성자 서두에 초기값으로 초기화
2. 클래 선언부에 직접 초기화

생성자는 꼭 있어야 하는가? 생성자가 없는 클래스에서는
컴파일러가 기본 생성자를 만들어서 삽입하고, 호출한다.

기본 생성자
-매개변수 없는 생성자
-디폴트 생성자 : 컴파일러가 자동으로 호출

생성자가 하나도 없는 클래스의 경우 -> 컴파일러가 삽입
생성자가 자동으로 생성되지 않는 경우 -> 생성자가 하나라도 선언된 클래스일 경우
*/


#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle(); //위임 생성자
	Circle(int r); //타겟 생성자
	double getArea();
};

Circle::Circle() :Circle(1) {} //위임 생성자
Circle::Circle(int r) { //타겟 생성자
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}
double Circle::getArea() {
	return 3.14*radius*radius;
}

int main()
{
	Circle donut;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}