#pragma once
#ifndef CIRCLE_H //이미 CIRCLE_H헤더파일이 정의되어 있으면,
				 //조건 컴파일문의 값이 false가 되어 #endif문으로 빠짐
#define CIRCLE_H 
//Circle 클래서 선언
class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	double getArea();
};
#endif