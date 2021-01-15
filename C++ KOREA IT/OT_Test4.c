#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float num[5];
	float max;
	printf("5개의 실수를 입력하라 >> ");
	for (int i = 0; i < 5; i++)
	{
		scanf("%f", &num[i]);
	}
	max = num[1];
	for (int i = 0; i < 5; i++)
	{
		if (max < num[i])
			max = num[i];
	}
	printf("제일 큰 수 = %.3f\n", max);

	return 0;
}