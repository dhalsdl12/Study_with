#include <iostream>
#include <string>
using namespace std;

int main()
{
	char word[100];
	int cnt = 0;
	cout << "���ڵ��� �Է��϶�(100���̸�)" << endl;
	cin.getline(word, 100);

	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] == 120)
		{
			cnt++;
		}
	}
	cout << "x�� ������ " << cnt << endl;
}