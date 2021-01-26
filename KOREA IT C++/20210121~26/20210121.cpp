/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; };
	Circle(int r) { radius = r; };
	void setRadius(int r) { radius = r; };
	double getArea();
};
double Circle::getArea() {
	return 3.14*radius*radius;
}

int main()
{
	Circle circles[2][3];
	
	//초기값으로 배로 만들기
	//Circle circles[2][3] = {{Circle(1),Circle(2),Circle(3)},{Circle(4),Circle(5),Circle(6)}};
	//이렇게 바로 초기값으로 설정 가능!!
	
	int cnt = 1;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//circles[i][j].setRadius(cnt);
			//tRadius를 사용하는 이유는 초기값으로 바로 하지 않았기 때문에
			//radius에 접근하기 위해서 class안에 있는 함수를 이용하여 넣는다.
			cnt++;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Circle [" << i << "," << j << "]의 면적은 ";
			cout << circles[i][j].getArea() << endl;
		}
	}
	return 0;
}
*/


/*
문서 편집기나 그래픽편집기를 개발하는 경우, 몇줄의 텍스트를 입력할 것인지,
몇 개의 도형을 그릴것인지는 사용자의 마음에 달려있기 때문에,
필요한 메모리를 프로그램을 작성하는 단계에서 모두 선언하는 것은 불가능하다.
이런 유형의 응용프로그램을 위해, 실행중에 필요한 만큼 메모리를 할당받고
필요 없을때 반환하는 '동적 메모리 할당/반환 메커니즘'이 필요하다.
*/

/*
C++에서는 new, delete 연산자를 이용한다.
new연산자는 heap(힙)이라는 시스템 공간으로부터 메모리를 할당받고,
delete 연산자는 할당받은 메모리를 힙으로 반환한다.
*/

/*
new연산자는 '데이터타입'의 크기만큼 힙으로부터 메모리를 할당받고 주소를 리턴한다.
그 결과 '포인터 변수'는 할당받은 메모리의 주소를 가진다.
delete연산자는 '포인터변수'가 가리키는 메모리를 힙으로 반환한다.
'데이터타입'은 int, char, double 등 기본 타입뿐 아니라 구조체(struct),
클래스(class)도 포함한다.
*/

/*
힙 메모리가 부족하면 new NULL을 리턴하므로,
new의 리턴값이 NULL인지 검사하는 것이 좋다.
*/


/*
#include <iostream>
using namespace std;
int main()
{
	int *p;
	p = new int;
	if (!p) // p==NULL과 같음
	{		//힙 메모리가 부족하면 null을 리턴하므로, 리턴값이 null인지 검사
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}
	*p = 5; //할당 받은 정수 공간에 5삽입
	int n = *p; //p가 가리키고 있는 곳의 값을 n변수에 넣엇다
	cout << "*p = " << *p << endl;
	cout << "n = " << n << endl;
	delete p;
}
*/


/*
new & delete
malloc()을 대신하는 메모리의 동적할당 방법!
크기를 바이트 단위로 계산하는 일을 거치지 않아도 된다!
int 형 변수의 소멸 : int *ptr1 = new int;
double 형 변수의 소멸 : double *ptr2 = new double;
길이가 3인 int 형 배열의 할당 : int *arr1 = new int[3];
길이가 7인 double 형 배열의 할당 : double *arr2 = new double[7];
*/

/*
free()를 대신하는 메모리의 해제 방법!
할당한 int 형 변수의 소멸 : delete ptr1;
할당한 double 형 변수의 소멸 : delete ptr2;
할당한 int 형 변수의 소멸 : delete [] arr1;
할당한 double 형 변수의 소멸 : delete [] arr2;
*/

/*
new 연산자로 할당된 메모리 공간은 반드시 delete 함수 호출을 통해서 소멸 해야한다.
특히 호출하게 되는 new & delete 연산자의 연산 특성은
malloc & free와 큰 차이가 있다!
*/


/*
new연산자는 '배열의 크기'만한 배열을 할당받아서 주소를 리턴한다.
delete는 '포인터 변수'가 가리키는 배열 메모리를 반환한다.
new를 이용하면 int, char 등 기본 타입과 구조체, 클래스 등 사용자가 정의한 타입의
배열을 할당받을 수 있다.
동적으로 할당받은 배열은 []를 이용해서 보통 배열과 동일한 방법으로 사용한다.
p[i] = i //p가 배열에 대한 포인터 이므로, *(p+1) = 1 와 같다
*/


/*
예제>
사용자로부터 입력할 정수의 개수를 입력 받아 배열을 동적 할당 받고,
하나씩 정수를 입력 받은 후 합을 출력하는 프로그램을 작성하라.
*/
/*
#include <iostream>
using namespace std;

int main()
{
	cout << "입력할 정수의 개수는? ";
	int n;
	cin >> n;
	if (n <= 0) return 0;
	int *p = new int[n]; //n개의 정수 배열 동적 할당
	if (!p)
	{
		cout << "메모리를 할당할 수 없습니다." << endl;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "번째 정수 입력 : "; //프롬프트 출력
		cin >> p[i]; //키보드로부터 정수 입력
		sum += p[i];
	}
	cout << "평균 = " << sum / n << endl;
	delete[] p; //배열 메모리 반환
}
*/


/*
배열 동적할당시 초기화 방법
int *pArry = new int[] {1,2,3,4};
	//1,2,3,4로 초기화된 정수 배열 생성, 중괄호 사용하여 초깃값 지정가능
*/


/*
<참고>
C언어의 메모리 동적 할당과 반환 함수인 malloc()과 free()를
C++프로그램에서도 사용할 수 있다.
예를들어 int *p = (int*)malloc(5*sizeof(int)); //5개의 정수 배열의 동적할당
1. malloc()은 할당받은 크기 (5*sizeof(int))를 지정해야되고,
리턴되는 포인터를 형변환(int*) 해야하는 불편함이 있지만,
new는 이러한 불편함이 없다.

2. malloc()이나 free()를 사용하기 위해서 <cstdlib>를 include해야하지만.
new와 delete는 기본 C++연산자로서 어떠한 헤더파일도 include 할 필요가 없다.
c++ 개발자로써 malloc(), free()는 잊어버리는 것이 좋다.
*/


//객체동적생성 및 반환 예제
/*#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() :Circle(1) {}; //위임 생성자
	Circle(int r) { //타겟 생성자
		radius = r;
		cout << "생성자 실행 radius = " << radius << endl;
	};
	~Circle() { //소멸자
		cout << "소멸자 실행 radius = " << radius << endl;
	};
	void setRadius(int r) { radius = r; }; //멤버함수
	double getArea() { return 3.14*radius*radius; }; //멤버함수
};

int main()
{
	Circle *p, *q; //포인터 변수 생성
	p = new Circle; //동적메모리할당(생성자실행)
	q = new Circle(30); //동적메모리할당(매개변수있는 생성자실행)
	cout << p->getArea() << endl << q->getArea() << endl;
	delete p; //동적메모리 반환 - 생성한 순서에 관계없이 원하는 순서대로 delete가능
	delete q; //동적메모리 반환
}
*/


/*
<참고>
매개변수 없는 생성자를 호출할 때
Circle waffle; 라고 작성해야한다
Circle waffle(); 이와 같이 작성하면 오류를 발생시키지는 않지만
함수로 인지하기 때문에 경고를 발생시키기도 한다.
그러나
Circle *p = new Circle;
Circle *p = new Circle(); 는 문제 없다.
*/

#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle() :Circle(1) {}; //위임 생성자
	Circle(int r) { //타겟 생성자
		radius = r;
		cout << "생성자 실행 radius = " << radius << endl;
	};
	~Circle() { //소멸자
		cout << "소멸자 실행 radius = " << radius << endl;
	};
	void setRadius(int r) { radius = r; }; //멤버함수
	double getArea() { return 3.14*radius*radius; }; //멤버함수
};

int main()
{
	int radius;
	while (true)
	{
		cout << "정수 반지름 입력(음수이면 종료)>> ";
		cin >> radius;
		if (radius < 0) break;
		Circle *p = new Circle(radius); //동적 객체 생성
		cout << "원의 면적은 " << p->getArea() << endl;
		delete p; //객체 반환
	}
}