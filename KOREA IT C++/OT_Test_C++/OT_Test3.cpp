#include <iostream>
using namespace std;

int main()
{
	cout << "2개의 실수를 입력하라 >> ";
	
	int n1, n2;
	cin >> n1 >> n2;

	if (n1 >= n2)
		cout << "큰 수 = " << n1;
	else
	cout << "큰 수 = " << n2;
}