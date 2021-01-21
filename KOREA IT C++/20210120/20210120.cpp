/*
참조자의 이해
int num1 = 2020; //변수의 선언으로 인해 num1이라는 이름으로 메모리 공간이 할당된다.
int &num2 = num1; //참조자의 선언으로 인해서 num1의 메모리 공간에 num2라는 이름이 추가로 붙게된다.
참조자는 기존에 선언된 변수에 붙이는 '별칭'이다.
그리고 이렇게 참조자가 만들어지면 이는 변수의 이름과 사실상 차이가 있다.
*/


//참조자 관련 예제 및 선언
/*
#include <iostream>
using namespace std;
int main()
{
	int num1 = 2020;
	int &num2 = num1; //num2는 num1의 참조자이다. 따라서 이후부터는 num1로 하는
					  //모든 연산은 num2로 하는것과 동일한 결과를 보인다.
	cout << "VAL : " << num1 << endl;
	cout << "REF : " << num2 << endl;
	cout << "VAL : " << &num1 << endl;
	cout << "REF : " << &num2 << endl;
	
	return 0;
}
*/


/*
참조자의 수에는 제한이 없으며, 참조자를 대상으로 참조자를 선언하는것도 가능하다.
int num1 = 1234;
int &num2 = num1;
int &num3 = num1;
int &num4 = num1;
*/


/*
참조자 선언 가능범위 : 불가능한 참조자 선언의 예
int &ref = 20; //상수 대상으로는 참조자 선언은 불가능하다.
int &ref; //참조자는 생성과 동시에 누군가를 참조해야한다.
int &ref = NULL; //포인터처럼 NULL로 초기화하는 것은 불가능하다.
참조자는 선언과 동시에 누군가를 참조해야하는데 그 참조의 대상은 기본적으로 변수가 되어야한다.
그리고 참조자는 참조의 대상을 변경할 수 없다.
*/


//참조자 선언 예제)
/*
#include <iostream>
using namespace std;

int main()
{
	int arr[3] = { 1,2,3 };
	int &ref1 = arr[0]; //변수의 성향을 가지는 대상이라면 참조자 선언이 가능하다.
	int &ref2 = arr[1]; //배열의 요소 역시 변수의 성향을 지니기 때문에
	int &ref3 = arr[2]; //참조자 선언이 가능하다.

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;

	return 0;
}
*/


//포인터 변수 대상의 참조자 선언
/*
#include <iostream>
using namespace std;

int main()
{
	int num1 = 20;
	int *ptr = &num1;
	int **dptr = &ptr;

	int &ref = num1;
	int *(&pref) = ptr; //ptr과 dptr역시 변수이다. 다만 주소값을 저장하는 포인터 변수이다.
	int **(&dpref) = dptr; //따라서 참조자 선언이 가능하다.

	cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;

	return 0;
};
*/ 


/*
<참고>
초기화 되지 않은 객체 포인터를 이용하면 오류 발생
Circle *p;
p->getArea() //오류발생
포인터 변수 p가 어떤 Circle타입의 객체도 가리키지 않은 상태에서
getArea() 함수를 호출하기 때문에, 실행중 'null pointer assignment' 오류가 발생한다.
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

	//객체이름으로 접근
	cout << donut.getArea() << endl;

	//객체 포인터로 접근
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
	Circle circleArray[3]; //객체 배열 생성

	for (int i = 0; i < 3; i++)
	{
		int r;
		cin >> r;
		circleArray[i].setRadius(r);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "의 면적 " << circleArray[i].getArea() << endl;
	}
	Circle *p = circleArray;
	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "의 면적 " << p->getArea() << endl;
		p++;
	}
}
*/


/*
배열 소멸과 소멸자
함수가 종료하면 함수 내에 선언된 배열도 소멸된다.
배열이 소멸되면 모든 원소 객체가 소멸되며 각 원소 객체마다 소멸자가 호출된다.
main() 함수가 종료되면 circleArray 배열이 소멸되며, 높은 인덱스에서부터 원소 객체가 소멸되고,
각 객체마다 ~Circle() 소멸자가 실행된다.
circleArray[2] 소멸자 실행 -> circleArray[1] 소멸자 실행 -> circleArray[0] 소멸자 실행

<참고> 객체 포인터를 사용하여 객체 배열을 다루는 다양한 사례
객체 포인터를 이용하여 circleArray의 각 Circle 객체의 면적을 출력하는 코드를
다양하게 작성할수 있다

1) 포인터 p를 이용하여 객체처럼 접근
Circle *p = circleArray;
for(int i = 0l i < 3; i++)
	cout << (*p++).getArea() << endl;

2) 배열의 이름 circleArray를 포인터로 사용
for(int i = 0; i < 3; i++)
	cout << (circleArray + i)->getArea() << endl;

3) 포인터 p의 정수연산 이용
Circle *p = circleArray;
for(int i = 0; i < 3; i++)
	cout << (p+i)->getArea() << endl;
*/


//예제! 객체배열 초기화
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
	//circleArray[0] 객체가 생성될때, 생성자 Circle(10)
	//circleArray[1] 객체가 생성될때, 생성자 Circle(20)
	//circleArray[2] 객체가 생성될때, 생성자 Circle()
	//이 호출된다
	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
	}
	return 0;
}