#include <iostream>
using namespace std;

#include "circle.h"
//circle 클래스 구현, 모든 멤버 함수를 작성한다.
Circle::Circle() { 
	radius = 1; 
	cout << "r = " << radius << " circle ok\n";
}

Circle::Circle(int r) {
	radius = r;
	cout << "r = " << radius << " circle ok\n";
}

double Circle::getArea() {
	return 3.14*radius*radius;
}