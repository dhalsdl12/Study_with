#include <iostream>
#include <string>
using namespace std;

int main()
{
	char pw1[50], pw2[50];

	cout << "�� ��ȣ�� �Է��ϼ��� >> ";
	cin.getline(pw1, 50, '\n');
	cout << "�� ��ȣ�� �ٽ� �� �� �Է��ϼ��� >> ";
	cin.getline(pw2, 50, '\n');

	if (strcmp(pw1, pw2) == 0)
		cout << "�����ϴ�.\n";
	else
		cout << "���� �ʽ��ϴ�.\n";
}