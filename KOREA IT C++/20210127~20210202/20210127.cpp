/*
<참고> 함수 중복과 실행시간
c++컴파일러는 함수 중복이 성공적인지 판별하고, 중복된 함수의 호출이 옳은지 확인한다.
함수 중복은 컴파일시에 이루어지기 때문에, 함수 중복으로 인한 실행시간 저하는 없다.
*/


//예제 6-1 big() 함수 중복 연습
//큰 수를 리턴하는 다음 두 개의 big 함수를 중복 구현하라.
/*
#include <iostream>
using namespace std;

int big(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int big(int a[], int size)
{
	int res = a[0];
	for (int i = 1; i < size; i++)
		if (res < a[i]) res = a[i];
	return res;
}
int main()
{
	int array[5] = { 1,9,-2,8,6 };
	cout << big(2, 3) << endl;
	cout << big(array, 5) << endl;
	return 0;
}
*/

//예제 6-2 sum() 함수 중복 연습
//함수 sum()을 호출하는 경우가 다음과 같을때, 함수 sum()을 중복 구현하라.
//sum()의 첫번째 매개변수는 두번째 매개변수보다 작은 정수 값으로 호출된다고 가정한다.
/*
#include <iostream>
using namespace std;
int sum(int a, int b)
{
	int s = 0;
	for (int i = a; i <= b; i++) s += i;
	return s;
}
int sum(int a)
{
	int s = 0;
	for (int i = 0; i < a; i++) s += i;
	return s;
}
int main()
{
	cout << sum(3,5) << endl << sum(3) << endl << sum(100) << endl;
	return 0;
}
*/


/*
디폴트 매개변수는 보통 매개변수 앞에 선언될 수 없다.
디폴트 매개변수는 맨끝에 몰려서 선언되어야 한다.
*/

//6-3 디폴트 매개변수를 가진 함수 선언 및 호출
/*
#include <iostream>
using namespace std;
#include <string>

void star(int a = 5);
void msg(int id, string text = " ");

void star(int a)
{
	for (int i = 0; i < a; i++)
		cout << '*';
	cout << endl;
}
void msg(int id, string text)
{
	cout << id << ' ' << text << endl; ;
}
int main()
{
	star();
	star(10);
	msg(10);
	msg(10, "hello");
	return 0;
}
*/


// 6-4  디폴트 매개변수를 가진 함수 만들기 연습
//함수 f()를 호출하는 경우가 다음과 같을때 f()를 디폴트 매개변수를 가진 함수로 작성하라.
/*
f(); //한 줄에 빈칸을 10개 출력한다.
f('%'); // 한줄에 '%'를 10개 출력한다.
f('@', 5); //다섯줄에 '@'를 10개 출력한다
*/
/*
#include <iostream>
using namespace std;
void f(char c = ' ', int line = 1);
void f(char c, int line)
{
	for (int m = 0; m < line; m++)
	{
		for (int n = 0; n < 10; n++)
			cout << c;
		cout << endl;
	}
}
int main()
{
	f();
	f('%');
	f('@', 5);
	return 0;
}
*/


//중복 함수들과 디폴트 매개변수를 가진 함수를 함께 사용 불가

//예제 6-5 디폴트 매개변수를 이용하여 중복 함수 간소화 연습
/*
#include <iostream>
using namespace std;

void fillLine(int n = 25, char c = '*') //n개의 c문자를 한 라인에 출력
{
	for (int i = 0; i < n; i++)
		cout << c;
	cout << endl;
}
int main()
{
	fillLine(); //25개의 *을 한라인에 출력
	fillLine(10, '%'); //10개의 %를 한 라인에 출력
}
*/

/*
#include <iostream>
using namespace std;

class MyVector
{
	int *p;
	int size;
public:
	MyVector(int n = 100)
	{
		p = new int[n];
		size = n;
	}
	~MyVector() { delete[] p; }
};
int main()
{
	MyVector *v1, *v2;
	v1 = new MyVector();
	v2 = new MyVector(1024);

	delete v1;
	delete v2;
}
*/



/*
static은 변수 와 함수의 생성주기(life cycle)와 사용범위(scope)를 지정하는 방식중 하나로서
static으로 선언된 변수와 함수의 생명주기와 사용범위는 다음과 같은 특징을 가진다.
생명주기 - 프로그램이 시작할 때 생성되고 프로그램이 종료할 때 소멸
사용범위 - 변수나 함수가 선언된 범위 내에서 사용. 전역 혹은 지역으로 구분한다.

외부 선언이 없으면 오류가 난다.........
*/
/*
static변수 : 선언한 순간부터 프로그램 종료시까지 사용가능
static함수 : 해당 파일 내에서만 사용가능     
*/


#include <iostream>
using namespace std;

class Person {
public:
	int money; //개인 소유의 돈
	void addMoney(int money)
	{
		this->money += money;
	}
	static int sharedMoney; //공금
	static void addShared(int n)
	{
		sharedMoney += n;
	}
};
//static 변수 생성. 전역 공간에 생성
int Person::sharedMoney = 10; //10으로 초기화

int main()
{
	Person han;
	han.money = 100; //개인돈 100
	han.sharedMoney = 200; //static 멤버 공금 200

	Person lee;
	lee.money = 150;
	lee.addMoney(200); //lee의 개인돈 = 350
	lee.addShared(200); //static멤버 접근 , 공금 = 400

	cout << han.money << ' ' << lee.money << endl;
	cout << han.sharedMoney << ' ' << lee.sharedMoney << endl;
}