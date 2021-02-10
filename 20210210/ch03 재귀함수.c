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


/*
   *
  ***
 *****
*******
*/