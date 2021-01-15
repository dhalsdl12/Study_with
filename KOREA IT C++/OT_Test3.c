#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num1, num2;
	printf("2개의 정수를 입력하라 >> ");
	scanf("%d %d", &num1, &num2);
	printf("큰 수 = %d\n", num1 > num2 ? num1 : num2);
	return 0;
}