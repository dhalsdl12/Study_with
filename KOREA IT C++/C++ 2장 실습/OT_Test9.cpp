#include <iostream>
using namespace std;

int main()
{
	char name[50];
	char address[100];
	int age;

	cout << "이름은? ";
	cin.getline(name, 50);
	cout << "주소는? ";
	cin.getline(address, 100);
	cout << "나이는? ";
	cin >> age;

	cout << name << ", " << address << ", " << age << "세" << endl;
	return 0;
}