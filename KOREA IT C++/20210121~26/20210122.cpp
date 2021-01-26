/*
new를 이용하여 동적으로 배열을 생성할 때, 매개변수 있는 생성자를 직접 호출할 수 없다.
컴파일 오류 발생.
대신 중괄호를 이용하여 각 원소 객체로 초기화 할 수 있다.
Circle *pArray = new Circle[3]{ Circle(1), Circle(2), Circle(3) };
*/


/*
<참고>
동적으로 할당받은 메모리는 반드시 반환해야 하는가?
힙(heap)은 프로그램 실행중에 new를 이용하여 동적으로 할당받아 사용할 수 있는 메모리이다.
대부분의 운영체제에서 프로그램마다 힙이 따로 주어지기 때문에,
한 프로그램이 동적으로 많은 메모리를 할당받는 것이,
다른 프로그램의 힘에 전혀 영향을 주지 않는다.
다만, 할당받은 후 필요없게된 메모리를 힙에 반환하지 않고나 코딩 잘못으로
프로그램 종료 시, 힙 전체가 운영체제의 의해 반환되므로
누수 메모리에 대한 걱정은 하지 않아도 된다.
*/



//예제 4-9 Cuircle배열의 동적 생성 및 반환
/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() :Circle(1) {};
	Circle(int r) {
		radius = r;
		cout << "생성자 실행 radius = " << radius << endl;
	};
	~Circle() { cout << "생성자 소멸 radius = " << radius << endl; };
	void setRadius(int r) { radius = r; };
	double getArea() { return 3.14*radius*radius; };
};

int main()
{
	Circle *pArray = new Circle[3]; //객체 배열 생성
									//각 원소 객체의 기본 생성자 Circle()생성
	for (int i = 0; i < 3; i++)
	{
		pArray[i].setRadius((i + 1) * 10);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << (pArray + i)->getArea() << endl;
	}
	Circle *p = pArray; //포인터 p에 배열의 주소값으로 설정
	for (int i = 0; i < 3; i++)
	{
		cout << p->getArea() << endl;
		p++; //다음 원소의 주소로 증가
	}

	delete[] pArray;
}
*/


/*
예제 4-10 객체 뱌열의 동적 생성과 반환 응용
원의 개수를 입력받고 Circle 배열을 동적생성하라.
반지름 값을 입력받아 Circle 배열에 저장하고,
면적이 100에서 200사이인 원의 개수를 출력하라.
*/
/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();

	void setRadius(int r) { radius = r; };
	double getArea() { return 3.14*radius*radius; };
};
Circle::Circle() { radius = 1; }


int main()
{
	cout << "생성하고자 하는 원의 개수? ";
	int n, radius;
	cin >> n;
	Circle *pArray = new Circle[n];
	for (int i = 0; i < n; i++)
	{
		cout << "원" << i + 1 << ": "; //프롬프트 출력
		cin >> radius;
		pArray[i].setRadius(radius); //각 Circle 객체를 반지름으로 초기화
	}
	int count = 0;
	Circle *p = pArray;
	for (int i = 0; i < n; i++)
	{
		cout << p->getArea() << ' ';
		if (p->getArea() >= 100 && p->getArea() <= 200)
			count++;
		p++;
	}
	cout << endl << "면적이 100에서 200사이인 원의 개수는 ";
	cout << count << endl;
	
	delete[] pArray;
}
*/


/*
<TIP>
동적 메모리 할당과 메모리 누수(memory leak)
동적으로 할당받은 메모리의 주소를 잃어버려 힙에 반환할 수 없게 되면
메모리 누수가 발생한다.
메모리 누수가 계속 발생하여 힙의 크기가 줄어들게 되면.
실행 중에 메모리를 할당받을 수 없는 심각한 상황이 발생할 수 있다.
*/


/*
this의 기본개념 :
this는 객체 멤버 함수가 호출될때, 검파일러에 의해 보이지 않게 전달되는 객체에 대한 주소이다.
- this는 객체 자신을 가리키는 포인터
- 객체마다 있다.
- 클래스의 멤버함수에서만 사용할 수 있다.
- 멤버함수에 컴파일러 몰래 삽입한 매개변수이다.
- static 멤버 함수에서는 사용할 수 없다.
*/

/*
this가 필요한 경우
1. 멤버 변수의 이름과 동일한 이름으로 매개변수 이름을 짓고자 하는 경우
-매개 변수의 이름은 소스 프로그램의 강력한 주석역할을 한다.
예를들어 매개변수 이름을 radius로 한 Circle(int radius)의 선언은
매개변수에 반지름이 전달된다는 강력한 메세지를 담고있다.

2. 객체의 멤버함수에서는 객체 자신의 주소를 리턴할 때가 있다.
이때 this는 반드시 필요하다.
연산자 중복을 구현할때, 이런 경우가 많이 발생하며,
this없이는 연산자를 중복할 수 없는 경우도 있다.

this의 제약조건
1. this는 클래스의 멤버함수에서만 사용할 수 있다.
2. 멤버함수라도 정적멤버함수는 this를 사용할 수 없다.
*/


