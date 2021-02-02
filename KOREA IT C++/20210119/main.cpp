#include <iostream>
using namespace std;

#include "circle.h"

int main()
{
	Circle donut;
	double area = donut.getArea();
	cout << " donut's area = " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << " pizza's area = " << area << endl;
}