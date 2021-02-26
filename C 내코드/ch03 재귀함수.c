//--------------------------------------------
//재귀함수
//--------------------------------------------

//스스로를 반복적으로 호출하는 형태의 코드를 포함하는 함수

//1) 재귀함수 기본

/*
#include <stdio.h>

void Recursive(int num)
{	
	if (num > 0)
	{
		printf("Recursive call!! : %d\n", num);
		Recursive(num - 1); //자신을 호출
	}
}

int main()
{
	Recursive(3);

	return 0;
}
*/


//2) 재귀함수 기본

/*
#include <stdio.h>

void Recursive(int num)
{
	if (num > 0)
	{
		Recursive(num - 1); //자신을 호출
		printf("Recursive call!! : %d\n", num);
	}
}

int main()
{
	Recursive(3);

	return 0;
}
*/


//3) 재귀함수 기본

/*
#include <stdio.h>

void Recursive(int num)
{
	if (num > 0)
	{
		printf("Recursive call!! : %d\n", num); //3 -> 2 -> 1
		Recursive(num - 1); //자신을 호출
		printf("Recursive call!! : %d\n", num); //1 -> 2 -> 3
	}
}

int main()
{
	Recursive(3);

	return 0;
}
*/


//4) 재귀함수를 이용해서 1부터 10까지의 합 구하기

/*
#include <stdio.h>

int recursive(int num)
{
	int total = 0;
	if (num > 0)
	{
		total = recursive(num - 1) + num; //재귀함수 호출 시점
		printf("num %d를 더한 total : %d\n", num, total);

		return total;
	}
	return 0;
}

int main()
{
	int total = recursive(10);
	printf("total = %d\n", total);
	
	return 0;
}
*/


//5) 1부터 10까지의 수중의 3의 배수만 더한 값을 출력

//내 풀이
/*#include <stdio.h>

int recursive(int num)
{
	int total = 0;
	if (num > 0)
	{
		if (num % 3 == 0)
		{
			total = recursive(num - 1) + num;
			printf("num %d를 더한 total : %d\n", num, total);

			return total;
		}
		else
		{
			total = recursive(num - 1);
			return total;
		}
	}
	return 0;
}

int main()
{
	int total = recursive(10);
	printf("total = %d\n", total);

	return 0;
}*/

//쌤 풀이
/*
#include <stdio.h>

int recursive(int num)
{
	int total = 0;
	//전달받은 인자가 3의 배수가 될때까지 num값 감소
	while (num % 3 == 0)
	{
		num--;
	}
	//while을 빠져나올때 9.6.3.0

	if (num > 0)
	{
	
		total = recursive(num - 1) + num;
		printf("num %d를 더한 total : %d\n", num, total);

		return total;
	}
	return 0;
}

int main()
{
	int total = recursive(10);
	printf("total = %d\n", total);

	return 0;
}
*/



//6) 재귀함수로 별찍기

//*
//**
//***
//****
/*
#include <stdio.h>

void star(int n)
{
	if (n > 0)
	{
		star(n - 1);
		for (int i = 0; i < n; i++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	int num;
	printf("num : ");
	scanf_s("%d", &num);
	star(num);

	return 0;
}
*/


//****
//***
//**
//*
/*
#include <stdio.h>

void star(int n)
{
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			printf("*");
		}
		printf("\n");
		star(n - 1);
	}
}

int main()
{
	int num;
	printf("num : ");
	scanf_s("%d", &num);
	star(num);

	return 0;
}
*/



//문제1
/*
   *		3		1
  ***		2		3
 *****		1		5
*******		0		7
*/
/*
i	j		k
0	0-2		0-0	
1	0-1		0-2
2	0-0		0-4
3	x		0-6
*/
/*
#include <stdio.h>

void star(n, h)
{
	if (n > 0)
	{
		//처리되는 부분
		star(n - 1, h);

		//공백찍기 반복
		for (int i = 0; i < h - n; i++)
		{
			printf(" ");	//공백 순서(n==1:3개, 2:2개, 3:1개, 4:0개)
		}

		//별찍기 반복
		for (int j = 0; j < 2 * n - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	int num = 10;
	int height = num;
	star(num, height);

	return 0;
}
*/


//문제2
/*
*******
 *****
  ***
   *
*/
/*
#include <stdio.h>

void r(num)
{
	if (num > 0)
	{
		for (int i = 0; i < 4 - num; i++)
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * num - 1; j++)
		{
			printf("*");
		}
		printf("\n");
		r(num - 1);
	}
}

int main()
{
	int num = 4;
	r(num);

	return 0;
}
*/




//8) 피보나치 수열
	//0 1 1 2 3 5 8 13 21 ...

/*
#include <stdio.h>

int Fibo(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return Fibo(n - 2) + Fibo(n - 1);
}

int main()
{
	for (int i = 1; i < 15; i++)
	{
		printf("%d ", Fibo(i));
	}
	return 0;
}
*/



//9) 이진탐색 알고리즘을 재귀함수 형태로 구현하기

/*
#include <stdio.h>

int BSearch(int *ar, int First, int Last, int target)
{
	int mid = 0;

	if (First <= Last)				//!!!! - 재귀함수의 탈출조건 if문으로 변경
	{
		mid = (First + Last) / 2;	//<--코드입력(hint : Mid Index 저장)

		if (target == ar[mid])		//배열의 mid번째 요소값이 target과 일치한다면
			return mid;				//mid를 리턴

		else if (ar[mid] > target)						//배열이 mid번째 요소값이 target보다 크다면
			return BSearch(ar, First, mid - 1, target);	//!!!! - 재귀함수호출! last에 mid-1한 값을 인자로 전달

		else if (ar[mid] < target)						//배열이 mid번째 요소값이 target보다 작다면
			return BSearch(ar, mid + 1, Last, target);	//!!!! - 재귀함수호출! first에 mid+1한 값을 인자로 전달
	}
	return -1;						//반복문을 벗어난 리턴은 first>last 보다 커진경우
									//target이 배열에 없으므로 -1을 리턴
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;
	int num;

	for (int i = 0; i < 5; i++)
	{
		printf("숫자 입력 : ");
		scanf_s("%d", &num);

		idx = BSearch(arr, 0, (sizeof(arr) / sizeof(int))-1, num);
		if (idx == -1)
			printf("탐색 실패 \n");
		else
			printf("타겟 저장 인덱스: %d \n", idx);
		printf("\n");
	}

	return 0;
}
*/



//10) 하노이 타워

/*
#include <stdio.h>

void Hanoi(int num, char from, char by, char to) //원반개수, 현재기둥, 경유기둥, 옮길기둥
{
	if (num > 0)
	{
		Hanoi(num - 1, from, to, by);								//Hanoi 재귀호출 num-1를 a->b 이동
		printf("%c에 있는 %d번째 원반을 %c로 옮김\n", from, num, to);	//printf 마지막 원반을 c로 이동
		Hanoi(num - 1, by, from, to);								//hanoi 재귀호출 num-1를 b->c 이동

	}
}


int main(void)
{
	// 막대A의 원반 3개를 막대B를 경유하여 막대C로 옮기기
	Hanoi(2, 'A', 'B', 'C');
	return 0;
}
*/