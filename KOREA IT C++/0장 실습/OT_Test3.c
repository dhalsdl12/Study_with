#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num1, num2;
	printf("2���� ������ �Է��϶� >> ");
	scanf("%d %d", &num1, &num2);
	printf("ū �� = %d\n", num1 > num2 ? num1 : num2);
	return 0;
}