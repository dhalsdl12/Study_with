/*
- 값에 의한 호출과 주소에 의한 호출 특징
값에 의한 호출 : 실인자값을 복사하여 전달하므로 함수내에서 실인자를
손상시킬수 없는 장점이 있다.
그러므로 함수 호출에 따른 부작용은 없다.

주소에 의한 호출 : 실인자의 주소를 넘겨주어 의도적으로 함수 내에서
실인자의 값을 변경하고자 할때 이용된다.
*/


/*
<참고>
값에 의해 호출 시 객체 복사 시간
'값에 의한 호출'은 함수 안에서 매개변수 객체에 어떤 변화가 일어나도
실인자(원본객체)를 훼손 시키지 않는 장점이 았는 반면,
실인자 객체의 크기가 크면 객체를 복사하는 시간이 커지는 단점이 있다.
*/

//예제 5-1 '값에 의한 호출'시 매개변수의 생성자가 실행되지 않음
/*
#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(); //생성자
	Circle(int r); //매개변수 있는 생성자
	~Circle(); //소멸자
	double getArea() { return 3.14*radius*radius; } //멤버함수
	int getRadius() { return radius; } //멤버함수
	void setRAdius(int radius){ //멤버함수
		this->radius = radius;
	}
};
Circle::Circle() {
	radius = 1;
	cout << "생성자 실행  radius = " << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << "생성자 실행  radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자 실행  radius = " << radius << endl;
}
void increase(Circle c) //waffle의 내용이 그대로 C에 복사됨
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
	Circle(); //생성자
	Circle(int r); //매개변수 있는 생성자
	~Circle(); //소멸자
	double getArea() { return 3.14*radius*radius; } //멤버함수
	int getRadius() { return radius; } //멤버함수
	void setRAdius(int radius) { //멤버함수
		this->radius = radius;
	}
};
Circle::Circle() {
	radius = 1;
	cout << "생성자 실행  radius = " << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << "생성자 실행  radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자 실행  radius = " << radius << endl;
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
<참고> 복사생성자
'값에 의한 호출'시, 컴파일러는 매개변수 객체의 생성자 대신 복사 생성자가
호출되도록 컴파일 하기 때문에, 생성자가 실행되지 않는 것이다.
컴파일러는 클래스에 복사 생성자가 작성되어 있지 않은 경우,
실인자 객체의 멤버 변수를 1:1로 매개변수 객체에 복사하는
디폴트 복사 생성자를 자동으로 삽입한다.
*/


/*
객체 치환 :
- 객체 치환 시 객체의 모든 데이터가 비트 단위로 복사된다.
- 객체 치환 후 c1과 c2의 내용이 완전히 같다. 하지만 내용물만 같을 뿐이다.
- 객체 치환은 동일한 클래스 타입에 대해서만 적용된다.
*/

/*
함수의 객체 리턴
return 문이 실행되면 tmp의 복사본이 생기고 복사본이 getCircle()을 호출한 곳으로
전달된다. 그리고 tmp는 소멸된다.
객체 c가 생성될때 반지름이 1이었지만, getCircle()이 리턴한 tmp객체로 치환되면
객체 c의 반지름은 30이 된다.
*/

//예제 5-3 객체 리턴
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
	return tmp; //객체tmp를 리턴한다. (복사본 리턴)
}
int main()
{
	Circle c;
	cout << c.getArea() << endl; //객체가 생성된다. radius = 1로 초기화된다.

	c = getCircle();
	cout << c.getArea() << endl; //tmp객체가 c에 복사된다.
}
*/


/*
참조(reference)
포인터 변수를 선언하기 위해 *기호를 사용하지만, 참조변수를 선언하기위해 &기호를 사용한다.

- & : 참조자
- 참조란 가리킨다는 뜻, 참조변수는 이미 선언된 변수에 대한 별명(alias)
- 선언시, 반드시 원본변수로 초기화하여야한다.  int &refn; 안된다
- refn과 refc는 이름만 생성되며, 별도의 공간이 할당되지 않는다.
  대신 참조변수는 초기화로 지정된 원본 변수의 공간을 공유한다.
- 참조변수에 대한 사용은 바로 원본 변수의 사용이다.
- 참조변수는 포인터가 아니므로 refc->setRadius(30); //컴파일 오류
refc.setRadius(30); 로 사용해야 한다.
*/

/*
참조변수에 대한 포인터를 만들 수 있다
int *p = &refn;
*p = 20;
*/

/*
- 참조변수 선언시 주의사항
1. 초기화가 없다면 컴파일 오류가 발생한다.
2. 참조자 &의 위치에 무관하다.
int &refn = n;
int & refn = n;
int&refn = n;
3. 참조자 &의 사용에 유의해야 한다. 문법적으로 잘못된 참조변수 선언.
& int refn = n;
int refn & = n;
4. 참조 변수의 배열을 만들 수 없다.
char &n[10];
5. 참조변수에 대한 참조 선언이 가능하다.
*/


//예제 5-3 기본 타입에 대한 변수 참조
/*
#include <iostream>
using namespace std;

int main()
{
	cout << "i\tn\trefn" << endl;
	int i = 1, n = 2;
	int &refn = n; //참조변수 refn 선언. refn은 n에 대한 별명
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
	Circle circle; //객체생성
	Circle &refc = circle; // circle객체에 대한 참조변수 refc선언
	refc.setRadius(10);
	cout << refc.getArea() << '\t' << circle.getArea() << endl;
}
*/



/*
예제 5-5 참조 매개변수로 평균 리턴하기
참조 매개변수를 통해 평균을 리턴하고 리턴문을 통해서는 함수의 성공여부를
리턴하도록 average() 함수를 작성하라
*/

/*
#include <iostream>
using namespace std;

bool average(int a[], int size, double &avg) //참조매개변수 avg에 평균값 전달
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
		//avg에 평균이 넘어오고, average()는 true 리턴
		cout << "평균은 " << avg << endl;
	else
		cout << "매개변수 오류" << endl;
	
	if (average(x, -2, avg))
		//avg의 값은 의미없고, average()는 false리턴
		cout << "평균은 " << avg << endl;
	else
		cout << "매개변수 오류" << endl;
}
*/


//예제 5-6 참조에 의한 호출로 Circle객체에 참조 전달
/*
#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(); //생성자
	Circle(int r); //매개변수 있는 생성자
	~Circle(); //소멸자
	double getArea() { return 3.14*radius*radius; } //멤버함수
	int getRadius() { return radius; } //멤버함수
	void setRAdius(int radius) { //멤버함수
		this->radius = radius;
	}
};
Circle::Circle() {
	radius = 1;
	cout << "생성자 실행  radius = " << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << "생성자 실행  radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자 실행  radius = " << radius << endl;
}
void increase(Circle &c) //참조 매개변수 c
{
	int r = c.getRadius();
	c.setRAdius(r + 1);
}
int main()
{
	Circle waffle(30);
	increase(waffle); //참조에 의한 호출
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
	cout << "정수 값으로 반지름을 입력하세요 >> ";
	int radius;
	cin >> radius;
	c.setRadius(radius);
}
int main()
{
	Circle donut;
	readRadius(donut);
	cout << "donut의 면적 = " << donut.getArea() << endl;
}