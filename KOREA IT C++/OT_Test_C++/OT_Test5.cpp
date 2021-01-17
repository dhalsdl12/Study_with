#include <iostream>
#include <string>
using namespace std;

int main()
{
	char pw1[50], pw2[50];

	cout << "새 암호를 입력하세요 >> ";
	cin.getline(pw1, 50, '\n');
	cout << "새 암호를 다시 한 번 입력하세요 >> ";
	cin.getline(pw2, 50, '\n');

	if (strcmp(pw1, pw2) == 0)
		cout << "같습니다.\n";
	else
		cout << "같지 않습니다.\n";
}