#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char name[50], address[100];
	int age = 0;

	printf("�̸���? ");
	gets(name);
	printf("�ּҴ�? ");
	gets(address);
	printf("���̴�? ");
	scanf("%d", &age);

	printf("%s, %s, %d\n", name, address, age);
}