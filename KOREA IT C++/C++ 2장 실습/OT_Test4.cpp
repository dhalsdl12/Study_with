#include <iostream>
using namespace std;

int main()
{
	float num[5];

	cout << "5���� �Ǽ��� �Է��϶� >> ";
	
	for (int i = 0; i < 5; i++)
	{
		cin >> num[i];
	}
	float max = num[0];
	for (int i = 1; i < 5; i++)
	{
		if (num[i] > max)
			max = num[i];
	}
	cout << "���� ū �� = " << max << endl;

	return 0;
}