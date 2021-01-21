#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char name[50], address[100];
	int age = 0;

	printf("이름은? ");
	gets(name);
	printf("주소는? ");
	gets(address);
	printf("나이는? ");
	scanf("%d", &age);

	printf("%s, %s, %d\n", name, address, age);
}