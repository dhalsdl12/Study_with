#include <iostream>
#include <string>
using namespace std;

int main()
{
	char word[50];
	cout << "���ڿ� �Է� >> ";
	cin >> word;

	for (int i = 0; i < strlen(word); i++)
	{
		for (int j = 0; j <= i; j++)
			cout << word[j];
		cout << endl;
	}
}