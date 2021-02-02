//예제 9-6 추상 클래스 구현 연습
//다음 추상클래스 Calsuclator를 상속받아 GoodCalc 클래스를 구현하라
/*
#include <iostream>
using namespace std;

class Calculator {
public:
	virtual int add(int a, int b) = 0; //두 정수의 합 리턴
	virtual int subtract(int a, int b) = 0; //두 정수의 차 리턴
	virtual double avg(int a[], int size) = 0; //평균 리턴
};
class GoodCalc : public Calculator {
	int add(int a, int b) { return a + b; }
	int subtract(int a, int b) { return a - b; }
	double avg(int a[], int size) {
		double sum = 0;
		for (int i = 0; i < size; i++)
			sum += a[i];
		return sum / size;
	}
};
int main()
{
	int a[] = { 1,2,3,4,5 };
	Calculator *p = new GoodCalc();
	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3)<<endl;
	cout << p->avg(a, 5) << endl;
	delete p;
}
*/


//예제 9-7실습
/*
#include <iostream>
using namespace std;

class Calc {
	void input() {
		cout << "정수 2개를 입력하세요>> ";
		cin >> a >> b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0;
public:
	void run() {
		input();
		cout << "계산된 값은 " << calc(a, b) << endl;
	}
};
class Add : public Calc {
protected:
	int calc(int a, int b) { return a + b; }
};
class Sub : public Calc {
protected:
	int calc(int a, int b) { return a - b; }
};
int main()
{
	Add add;
	Sub sub;
	add.run();
	sub.run();
}
*/


//----------------------------------------------
//예제 10-1 제네릭 myswap함수 만들기
/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};
template <class T>
void myswap(T &a, T &b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 4, b = 5;
	myswap(a, b);
	cout << "a = " << a << ", b = " << b << endl;
	
	double c = 0.3, d = 12.5;
	myswap(c, d);
	cout << "c=" << c << ", d=" << d << endl;

	Circle donut(5), pizza(20);
	myswap(donut, pizza);
	cout << "donut반지름 = " << donut.getRadius() << endl;
	cout << "pizza반지름 = " << pizza.getRadius() << endl;
}
*/


/*
[구체화 과정]
1. 컴파일러는 myswap(a,b); 호출문을 컴파일할때 myswap()함수를 찾는다.
2. 템플릿으로 선언된 myswap()함수를 발견한다.
3. 구체화한다.
myswap(a,b);의 함수 호출문에서 실인지 a,b가 모두 int타입이므로,
템플릿의 제네릭 타입 T에 int를 대입시켜 구체화된 버전의
myswap(int &a, int &b);의 소스코드를 만들어낸다.
4. 구체화된 함수의 소스코드를 컴파일하고, 이 함수를 호출하도록 컴파일한다.
*/


//10-4 배열을 복사하는 제데릭 함수 mcopy()함수 만들기
//두 개의 배열을 매개변수로 받아 배열을 복사하는 제네릭 함수를 작성하라
/*
#include <iostream>
using namespace std;

template <class T1, class T2>
void mcopy(T1 src[], T2 dest[], int n)
{
	for (int i = 0; i < n; i++)
		dest[i] = (T2)src[i];
}
int main()
{
	int x[] = { 1,2,3,4,5 };
	double d[5];
	char c[5] = { 'H','E','L','L','O' }, e[5];

	mcopy(x, d, 5);
	mcopy(c, e, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << d[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
		{
			cout << e[i] << ' ';
		}
	cout << endl;
}
*/


//배열을 출력하는 프린터 템플릿 함수의 문제점
#include <iostream>
using namespace std;

template <class T>
void print(T array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << '\t';
	cout << endl;
}
void print(char array[], int n) //char배열을 출력하기 위한 함수 중복
{
	for (int i = 0; i < n; i++)
		cout << (int)array[i] << '\t';
		//array[i]를 int타입으로 변환하여 정수 출력
	cout << endl;
}
int main()
{
	int x[] = { 1,2,3,4,5 };
	double d[5] = { 1.1,2.2,3.3,4.4,5.5 };
	print(x, 5); //템플릿 print()함수로부터 구채화
	print(d, 5); //템플릿 print()함수로부터 구채화

	char c[5] = { 1,2,3,4,5 };
	print(c, 5); //중복된 print()함수가 우선 바인딩된다.
}