#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float num[5];
	float max;
	printf("5���� �Ǽ��� �Է��϶� >> ");
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
	printf("���� ū �� = %.3f\n", max);

	return 0;
}