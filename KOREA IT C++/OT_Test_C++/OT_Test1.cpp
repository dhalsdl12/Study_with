#include <iostream>

int main()
{
	for (int i = 1; i < 101; i++)
	{
		std::cout << '\t' << i;
		if (i % 10 == 0)
			std::cout << '\n';
	}
}