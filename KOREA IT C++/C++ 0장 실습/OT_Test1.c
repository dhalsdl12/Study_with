#include <stdio.h>

int main()
{
	for (int i = 1; i < 101; i++)
	{
		printf("\t%d", i);
		if (i % 10 == 0)
			printf("\n");
	}
	return 0;
}