#include <iostream>
using namespace std;
int main()
{
	float num[5], max;
	int i;

	cout << "5���� �Ǽ��� �Է��϶� >> ";
	for (i = 0; i < 5; i++)
		cin >> num[i];

	max = num[0];
	for (i = 1; i < 5; i++)
	{
		if (num[i] > max)
			max = num[i];
	}
	cout << "���� ū �� = " << max << endl;;
}