#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int num = 0, p = 0;
	
	while(num != 4)
	{
		printf("짬뽕:1, 짜장:2, 군만두:3, 종료:4 >> ");
		scanf("%d", &num);
		switch (num) {
		case 1:
			printf("몇인분? ");
			scanf("%d", &p);
			printf("짬뽕 %d인분 나왔습니다.\n", p);
			break;
		case 2:
			printf("몇인분? ");
			scanf("%d", &p);
			printf("짜장 %d인분 나왔습니다.\n", p);
			break;
		case 3:
			printf("몇인분? ");
			scanf("%d", &p);
			printf("군만두 %d인분 나왔습니다.\n", p);
			break;
		case 4:
			printf("오늘 영업은 끝났습니다.\n");
			break;
		default:
			printf("다시 주문하세요.\n");
			break;
		}
	}
	return 0;
}