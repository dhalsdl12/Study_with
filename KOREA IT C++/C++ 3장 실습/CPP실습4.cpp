#include <iostream>
using namespace std;

#include "CPP실습4_Box.h"

int main()
{
	Box b(10, 2);
	b.draw();  //박스를 그린다.
	cout << endl;
	b.setSize(7, 4); //박스크기를 변경한다.
	b.setFill('^'); //박스내부를 채울 문자를 변경한다.
	b.draw(); //박스를 그린다
}