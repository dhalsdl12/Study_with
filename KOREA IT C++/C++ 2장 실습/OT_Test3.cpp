#include <iostream>
using namespace std;

int main()
{
	int n1, n2;
	cout << "두 개의 정수를 입력하라 >> ";
	cin >> n1 >> n2;
	if (n1 > n2)
		cout << "큰 수 = " << n1 << endl;
	else
		cout << "큰 수 = " << n2 << endl;

	return 0;
}