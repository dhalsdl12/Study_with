#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char word[50];
	printf("문자열 입력 >> ");
	scanf("%s", word);

	for (int i = 0; i < strlen(word); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%c", word[j]);
		}
		printf("\n");
	}
	return 0;
}