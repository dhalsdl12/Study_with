#include <iostream>
using namespace std;

#include "circle.h"
//circle Ŭ���� ����, ��� ��� �Լ��� �ۼ��Ѵ�.
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