#include <iostream>
using namespace std;

class Circle { //circle class 생성
public:		   //class 선언부
	int radius;
	double getArea();
};
/*
class 선언부:
class 키워드와 클래스 이름으로 선언
맴버변수와 함수의 원형을 선언
{} 중괄호를 이용하여 감싸고, 마지막은 세미콜론(;)
*/

/*
접근 지정자
public: class외부로 부터 점근을 허용
private: 접근지정의 디폴트값, 외부에서 접근 불가능
protected: 상속관계에서 적용
*/
double Circle::getArea() { //class 구현부(멤버함수의 코드구현)
	return 3.14*radius*radius;
}
/*
함수의 리턴타입
클래스이름
범위지정연산자
멤버함수명과 매개변수
*/

int main()
{
	Circle donut; //donut객체 생성
	donut.radius = 1; //donut 객체의 반지름을 1로 설정
	double area = donut.getArea(); //donut 객체의 면적 알아내기 
	cout << "donut 면적은 " << area << endl;

	Circle pizza; //pizza객체 생성
	pizza.radius = 30;
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}