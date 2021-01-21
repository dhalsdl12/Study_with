#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char pw1[50], pw2[50];

	printf("새 암호를 입력하세요 >> ");
	scanf("%s", pw1);
	printf("새 암호를 다시 한 번 입력하세요 >> ");
	scanf("%s", pw2);

	if (strcmp(pw1, pw2) == 0)
		printf("같습니다.\n");
	else
		printf("같지 않습니다.\n");
	return 0;
}