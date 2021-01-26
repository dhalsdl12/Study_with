/*
call by value

void SwapByValue(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = num1;
}
값을 전달하면서 호출하게 되는 함수이므로 이 함수는 call by value이다.
이 경우 함수 외에 선언된 변수에는 접근이 불가능 하다.


call by reference

void SwapByRef(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = *ptr1;
}
값은 값이되, 주소값을 전달하면서 호출하게 되는 함수이므로 이 함수는 call by reference이다.
이 경우 인자로 전달된 주소의 메모리공간에 접군이 가능하다


int *SimpleFunc(int *ptr)
{
	return ptr+1;
}
포인터 ptr에 전달된 주소값의 관점에서 보면 이는 call by value이다.


int *SimpleFunc(int *ptr)
{
	if(ptr == NULL)
		return NULL;
	*ptr = 20;
	return ptr;
}
주소값을 전달받아서 외부에 있는 메모리 공간에 접근 했으니 이는 call by reference이다.
c++에는 두가지 형태의 call by reference가 존재한다.
하나는 주소값을 이용하는 형태이며, 다른 하나는 참조자를 이용하는 형태이다.
*/


//참조자를 이용한 call by reference

/*#include <iostream>
using namespace std;
void SwapByRef2(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}
int main()
{
	int val1 = 10;
	int val2 = 20;
	SwapByRef2(val1, val2);
	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;
	return 0;
}*/


/*
매개변수는 함수가 호출될 때 선언이 되는 변수 이므로,
함수 호출의 과정에서 선언과 동시에 전달되는 대상으로 초기화 된다.
즉, 매개변수에 선언된 참조자는 여전히 선언과 동시에 초기화된다.
*/

//참조를 대상으로 값을 반환하는 경우
/*
#include <iostream>
using namespace std;
int RefRetFuncTwo(int &ref)
{
	ref++;
	return ref;
}
int main()
{
	int val1 = 10;
	int val2 = RefRetFuncTwo(val1);
	val1 += 1;
	val2 += 100;
	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;
	return 0;
}
*/
/*
참조자를 반환하건, 변수에 저장된 값을 반환하건, 반환형이 참조형이 아니라면 차이는 없다!
어차피 참조자가 참조하는 값이나 변수에 저장된 값이 반환되므로
int val2 = RefRetFuncTwo(val1); //O
int &val2 = RefRetFuncTwo(val1); //O

반환형이 참조형인 경우에는 반환되는 대상을 참조자로 그리고 변수로 받을 수 있다.
그러나 반환형이 값의 형태라면, 참조자는 그 값을 받을 수 없다!
int val2 = RefRetFuncTwo(val1); //O
int &val2 = RefRetFuncTwo(val1); //X
*/



/*
얕은 복사 : 주소값을 하나더 만든다
깊은 복사 : 완전히 다른 객체를 만든다. 별도로 동적할당

객체의 얕은 복사 문제점
- 원본과 사본이 각각 name포인터로 문자 배열을 공유하고 있기 때문에
사본 객체에서 name문자열을 변경하면 원본 객체의 name문자열이 변경되는 문제가 발생한다.
이러한 문제는 많은 경우 개발자가 인지하지 못한 상태에서 발생하기 때문에
오류를 찾아내고 수정하는데 많은 시간이 걸리기도 한다.
가능한 얕은 복사가 일어나지 않도록 해야한다.


복사생성자(copy constructor) : 복사생성시 실행된다.
선언방법
class classname{
	classname(const classname& c); //복사생성자 classname& 자기클래스에 대한 참조매개변수
};
특징
- 복사생성자의 매개변수는 오직 하나이다.
- 자기 클래스에 대한 참조로 선언된다.
- 복사생성자는 클래스에 오직 한개만 선언할 수 있다.
*/

//5-9 Circle의 복사 생성자와 객체 복사
/*
#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(const Circle &c); //복사 생성자 선언
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};
Circle::Circle(const Circle &c) //복 사생성자 구현
{
	this->radius = c.radius;
	cout << "복사 생성자 실행 radius = " << this->radius << endl;
}
int main()
{
	Circle src(30); //src객체의 보통 생성자 호출
	Circle dest(src); //dest 객체의 복사 생성자 호출
	
	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "사본의 면적 = " << dest.getArea() << endl;
}
*/


/*
복사 생성자가 선언되어 있지 않는 클래스에서 컴파일러는 디폴트 복사생성자를 묵시적으로 삽입하고
이 생성자를 호출하도록 컴파일 한다.
컴파일러가 삽입하는 디폴트 복사 생성자 코드는 소위 얕은 복사를 실행하도록 만들어진 코드이다.
컴파일러가 삽입한 복사 생성자는 원본 객체의 모든 멤버를 일대일로 사본(this)에 복사하도록
구성된다. 앞의 Circle클래스는 멤버 변수가 radius하나 뿐이므로
radius값만 복사하는 코드로 되어있다.
*/

//5-10 얕은 복사 생성자를 사용하여 프로그램이 비정상 종료되는 경우
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char *name;
	int id;
public:
	Person(int id, const char* name);
	~Person();
	//컴파일러에 의해서 디폴트 복사 생성자 삽입
	//Person::Person(const Person &p)
	//{
	//this->id = p.id;
	//this->name = p.name;
	//}
	
	void changeName(const char *name);
	void show() { cout << id << ',' << name << endl; }
};
Person::Person(int id, const char* name) //생성자
{
	this->id = id;
	int len = strlen(name); //name의 문자개수
	this->name = new char[len + 1]; //name 문자열 공간 할당
	strcpy(this->name, name); //name에 문자열 복사
}
Person::~Person()
{
	if (name) //만일 name에 동적할당된 배열이 있으면
		delete[] name; //동적할당 메모리 소멸
}
void Person::changeName(const char* name) //이름변경
{
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

int main()
{
	Person father(1, "Kitae"); //1 father 객체 생성
	Person daughter(father); //2 daughter 객체복사 생성. 복사생성자 호출

	cout << "daughter 객체 생성 직후 --- " << endl;
	father.show(); //3 father 객체 출력
	daughter.show(); //4 daughter 객체 출력

	daughter.changeName("Grace"); //4 daughter이름 병경
	cout << "daughter 이름 변경 이 후 --- " << endl;
	father.show(); //5 father 객체 출력
	daughter.show(); //6 daughter 객체출력
	
	return 0; //6,7 daughter father 객체 소멸
}
*/


//5-11 깊은 복사 생성자를 가진 정상적인 person클래스
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char *name;
	int id;
public:
	Person(int id, const char* name);
	Person(const Person& person); //복사생성자
	~Person();

	void changeName(const char *name);
	void show() { cout << id << ',' << name << endl; }
};
Person::Person(int id, const char* name) //생성자
{
	this->id = id;
	int len = strlen(name); //name의 문자개수
	this->name = new char[len + 1]; //name 문자열 공간 할당
	strcpy(this->name, name); //name에 문자열 복사
}
Person::Person(const Person &person)
{
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << endl;
}
Person::~Person()
{
	if (name) //만일 name에 동적할당된 배열이 있으면
		delete[] name; //동적할당 메모리 소멸
}
void Person::changeName(const char* name) //이름변경
{
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

int main()
{
	Person father(1, "Kitae"); //1 father 객체 생성
	Person daughter(father); //2 daughter 객체복사 생성. 복사생성자 호출

	cout << "daughter 객체 생성 직후 --- " << endl;
	father.show(); //3 father 객체 출력
	daughter.show(); //4 daughter 객체 출력

	daughter.changeName("Grace"); //4 daughter이름 병경
	cout << "daughter 이름 변경 이 후 --- " << endl;
	father.show(); //5 father 객체 출력
	daughter.show(); //6 daughter 객체출력

	return 0; //6,7 daughter father 객체 소멸
}
*/


/*
묵시적 복사 생성
명시적으로 father을 원본으로 daughter를 복사 생성하기 때문에,
복사 생성자가 호출될것을 인지할 가능성이 높다.
그러나 개발자도 모르게 복사 생성자가 호출되는 다른 경우들이 있다.
이런 경우를 대비하여 가능하면 깊은 복사 생성자를 구현해 놓아야한다.

묵시적 복사 생성의 3가지 경우(컴파일러가 복사생성자를 자동으로 호출하는 경우)
1. 객체로 초기화하여 객체가 생성될때
2. '값에의한 호출'로 객체가 전달될 때
3. 함수가 객체를 리턴할 때
*/