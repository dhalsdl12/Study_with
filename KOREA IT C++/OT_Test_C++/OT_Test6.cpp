#include <iostream>
using namespace std;

int main()
{
	char name[50], address[100];
	int age;
	cout << "�̸���? ";
	cin.getline(name, 50);
	cout << "�ּҴ�? ";
	cin.getline(address, 50);
	cout << "���̴�? ";
	cin >> age;

	cout << name << ", " << address << ", " << age << "��\n";
}