#include <iostream>
#include <string>
using namespace std;

int main()
{
	char word[100];
	int cnt = 0;
	cout << "문자들을 입력하라(100개미만)" << endl;
	cin.getline(word, 100);

	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] == 120)
		{
			cnt++;
		}
	}
	cout << "x의 개수는 " << cnt << endl;
}