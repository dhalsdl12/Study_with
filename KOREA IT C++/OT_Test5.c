#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char pw1[50], pw2[50];

	printf("�� ��ȣ�� �Է��ϼ��� >> ");
	scanf("%s", pw1);
	printf("�� ��ȣ�� �ٽ� �� �� �Է��ϼ��� >> ");
	scanf("%s", pw2);

	if (strcmp(pw1, pw2) == 0)
		printf("�����ϴ�.\n");
	else
		printf("���� �ʽ��ϴ�.\n");
	return 0;
}