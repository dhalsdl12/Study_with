#include <iostream>
#include <string>
using namespace std;

int main()
{
	char pw1[50], pw2[50];

	cout << "�� ��ȣ�� �Է��ϼ��� >> ";
	cin.getline(pw1, 50);

	cout << "�� ��ȣ�� �ٽ� �� �� �Է��ϼ��� >> ";
	cin.getline(pw2, 50);

	if (strcmp(pw1, pw2) == 0)
	{
		cout << "�����ϴ�." << endl;
	}
	else
	{
		cout << "���� �ʽ��ϴ�." << endl;
	}
	return 0;
}