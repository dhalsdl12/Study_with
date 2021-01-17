#include <iostream>
using namespace std;

int main()
{
	cout << "이름을 입력하세요>> ";

	char name[11]; //한글은 5개글자, 영문은 10개까지 저장할 수 있다.
	cin >> name;

	cout << "이름은 " << name << "입니다\n"; //print name
}