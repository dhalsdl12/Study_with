#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int num = 0, p = 0;
	
	while(num != 4)
	{
		printf("«��:1, ¥��:2, ������:3, ����:4 >> ");
		scanf("%d", &num);
		switch (num) {
		case 1:
			printf("���κ�? ");
			scanf("%d", &p);
			printf("«�� %d�κ� ���Խ��ϴ�.\n", p);
			break;
		case 2:
			printf("���κ�? ");
			scanf("%d", &p);
			printf("¥�� %d�κ� ���Խ��ϴ�.\n", p);
			break;
		case 3:
			printf("���κ�? ");
			scanf("%d", &p);
			printf("������ %d�κ� ���Խ��ϴ�.\n", p);
			break;
		case 4:
			printf("���� ������ �������ϴ�.\n");
			break;
		default:
			printf("�ٽ� �ֹ��ϼ���.\n");
			break;
		}
	}
	return 0;
}