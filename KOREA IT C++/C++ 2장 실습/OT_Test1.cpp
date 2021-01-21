#include <iostream>
using namespace std;

int main()
{
	for (int i = 1; i < 101; i++)
	{
		cout << '\t' << i;
		if (i % 10 == 0)
			cout << endl;
	}
	return 0;
}