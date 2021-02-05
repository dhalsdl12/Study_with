//--------------------------------------------
//1. 배열
//--------------------------------------------

//1) 배열 크기확인
/*
#include <stdio.h>

int main()
{
	char c; int i; short s; float f; long l;
	char c_array[100];
	int i_array[100];
	short s_array[100];
	float f_array[100];
	long l_array[100];

	printf("char  c 크기 : %d, char  c_array 크기 : %d\n", sizeof(c), sizeof(c_array));
	printf("int   i 크기 : %d, int   i_array 크기 : %d\n", sizeof(i), sizeof(i_array));
	printf("short s 크기 : %d, short s_array 크기 : %d\n", sizeof(s), sizeof(s_array));
	printf("float f 크기 : %d, float f_array 크기 : %d\n", sizeof(f), sizeof(f_array));
	printf("long  l 크기 : %d, long  l_array 크기 : %d\n", sizeof(l), sizeof(l_array));


	return 0;
}
*/

//2) 문자배열 vs 문자열
/*
#include <stdio.h>

int main()
{
	char str1[4] = "abc";  //문자열o, 문자배열o
	char str2[4] = "abcd"; //문자열x, 문자배열o

	printf("str1 = %s\n", str1); //정상출력
	printf("str2 = %s\n", str2); //비정상출력 (문자열의 끝, NULL의 위치를 파악하지 못함)

	return 0;
}
*/



//--------------------------------------------
//2. 흐름제어문
//--------------------------------------------

//1) 전체 구구단 수 출력
/*
2~9단
중첩 while문을 이용
*/
/*
#include <stdio.h>

int main()
{
	int dan = 2;
	int i = 1;
	while (i <= 9)
	{
		dan = 2;
		while (dan <= 9)
		{
			printf("%dX%d=%d\t", dan, i, dan*i);
			dan++;
		}
		printf("\n");
		i++;
	}
	return 0;
}
*/

//2) 별찍기
/*
			i    k(공백)     j(*)
   *		0    0-2(3)     0-0(1)
  ***		1    0-1(2)     0-2(3)
 *****      2    0-0(1)     0-4(5)
*******     3     x         0-6(7)
				 k <= 2-i   j <= 2*i
*/
/*
#include <stdio.h>

int main()
{
	int i = 0; //줄바꿈용
	int k = 0; //공백찍기
	int j = 0; //별찍기

	while (i<4)
	{
		//공백찍기
		k = 0;
		while (k <= 2 - i)
		{
			printf(" ");
			k++;
		}
		//별찍기
		j = 0;
		while (j <= 2 * i)
		{
			printf("*");
			j++;
		}

		printf("\n");
		i++;
	}
	return 0;
}
*/


//별찍기 연습
/*
			i    k(공백)     j(*)
*******     0    x			0-6(7)
 *****      1    0-0(1)     0-4(5)
  ***       2    0-1(2)     0-2(3)
   *        3    0-3(3)     0-0(1)
				 k < i		j <= 6-2*i
*/
/*
#include <stdio.h>

int main()
{
	int i = 0, k = 0, j = 0;
	while(i<4)
	{
		k = 0;
		while(k<i)
		{
			printf(" ");
			k++;
		}
		j = 0;
		while(j<=6-2*i)
		{
			printf("*");
			j++;
		}
		printf("\n");
		i++;
	}
	return 0;
}
*/

/*
정수값 하나를 입력받아 해당 수 만큼의 개행작업이 이뤄지면서
정삼각형 모양의 별을 만들어 보세요

[출력 예]
높이 입력 : 5
	   *
	  ***
	 *****
	*******
   *********
*/
/*
i     k(공백)          j(*)
0    0 - n-1(n)       0-0(1)
1    0 - n-2(n-1)     0-2(3)
2    0 - n-3(n-2)     0-4(5)
3    0 - n-4(n-3)     0-6(7)
...
n       x             0-2*n
	  k < n-i        j <= 2*n
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i = 0;
	int k = 0;
	int j = 0;
	int height;

	printf("높이 입력 : ");
	scanf("%d", &height);
	while (i < height)
	{
		k = 0;
		while (k < height - i)
		{
			printf(" ");
			k++;
		}
		j = 0;
		while (j <= 2 * i)
		{
			printf("*");
			j++;
		}
		printf("\n");
		i++;
	}
	return 0;
}
*/


//--------------------------------------------
//3. 포인터 
//--------------------------------------------
/*
Point : 점, 가리키다
Pointer : 가리키는 도구

특정 공간의 위치정보(메모리주소)를 담아 메모리공간을 제어(데이터 값 저장/변경)할 수 있는 특수변수

변수종류
1. 일반 변수
	- 데이터값을 저장
2. 포인터 변수
	- 메모리주소값을 저장

포인터 연산자
	* : 포인터연산자
	& : 참조연산자
*/
/*
#include <stdio.h>

int main()
{
	int num = 3;				//3값을 int 공간 num에 대입
	int *ptr = &num;			//num의 메모리 주소값을 int 크기를 가리키는 ptr포인터 변수에 초기화
	*ptr = 10;					//10값을 ptr포인터가 가리키는 공간에 대입

	int num2 = *ptr;			//ptr이 가리키는 곳의 값을 num2변수에 초기화
	printf("*ptr = %d", *ptr);	//ptr이 가리키는 곳의 값을 10진 정수 서직에 맞게 출력

	return 0;
}
*/

//1)포인터 복숩
//메모리맵 그리고 오른쪽에 주석으로 해석해봅니다.
/*
#include <stdio.h>

int main()
{
	int num = 10;			//10 상수값을 num 변수 공간에 초기화
	int *ptr1 = &num;		//num의 메모리 주소값을 int크기 정도를 가리키는 ptr1포인터에 초기화
	int *ptr2 = ptr1;		//ptr1안의 값(주소값)을 ptr2포인터에 초기화

	(*ptr1)++;				//ptr1이 가리키는 곳의 값을 1증가 - num = 11
	(*ptr2)++;				//ptr2가 가리키는 곳의 값을 1증가 - num = 12
	printf("%d\n", num);

	return 0;
}
*/

//2) 포인터와 배열
/*
#include <stdio.h>

int main()
{
	int arr[4] = { 10,20,30,40 };
	int *ptr = arr;

	printf("%d %d\n", *ptr, ptr[0]);
	printf("%d %d\n", *(ptr + 1), ptr[1]);
	printf("%d %d\n", *(ptr + 2), ptr[2]);
	printf("%d %d\n", *(ptr + 3), ptr[3]);

	//printf("%x\n", (ptr + 0));
	//printf("%x\n", (ptr + 1));
	//printf("%x\n", (ptr + 2));
	//printf("%x\n", (ptr + 3));

	return 0;
}
*/

//3) 포인터와 함수
/*
Call-by-value	: 함수를 실행할때 전달하는 인자가 데이터 값인 경우
Call-by-address : 함수를 실행할때 전달하는 인자가 메모리주소값인 경우
Call-by-Reference(C++) : 함수를 실행할때 전달하는 인자가 참조값인 경우
*/

//Call-by-value
/*
#include <stdio.h>

void Swap(int x, int y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
int main()
{
	int a = 10, b = 20;
	printf("Swap 전 a = %d,  b = %d\n", a, b);
	Swap(a, b); //Call-by-value
	printf("Swap 후 a = %d,  b = %d\n", a, b);

	return 0;
}
*/

//Call-by-address
/*
#include <stdio.h>

void Swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int main()
{
	int a = 10, b = 20;
	printf("Swap 전 a = %d,  b = %d\n", a, b);
	Swap(&a, &b); //Call-by-address
	printf("Swap 후 a = %d,  b = %d\n", a, b);

	return 0;
}
*/

//4) 포인터와 문자열
/*
#include <stdio.h>

int main()
{
	char arr[20] = "hello World"; //배열공간을 따로 만들어서 문자열 상수값을 저장
	char *ptr1 = "hello World";
	char *ptr2 = "hello World";

	printf("arr배열의 주소     : %x\n", arr); //배열의 이름은 배열의 시작주소를 담고있는 포인터 상수이다.
	printf("hello World의 주소 : %x\n", "hello World");
	printf("ptr1 안의 주소     : %x\n", ptr1); //"hello World"라는 문자열 상수르 가리킴 (ptr1 == ptr2)
	printf("ptr2 안의 주소     : %x\n", ptr2); //"hello World"라는 문자열 상수를 가리킴 (ptr1 == ptr2)

	return 0;
}
*/



//--------------------------------------------
//4. 동적할당
//--------------------------------------------

/*
코드 영역	: 컴파일된 데이터 저장
데이터 영역	: 공유메모리영역(전역변수, static변수)
			  프로그램 시작시 생성 -> 프로그램 종료시 소멸
스택 영역	: 중괄호({}) 내에서 선언되어지는 변수(지역변수)
			  중괄호에서 생성 -> 중괄호를 벗어나면 소멸
힙 영역		: 동적할당 영역
			  malloc함수로 공간 생성 -> free함수 사용 시 공간 소멸
*/

/*
동적할당 : 필요한 만큼 공간을 할당 받아 저장하기 위한 문법
	동적할당은 Heap 영역에 형성이 된다
	동적할당 함수 : malloc(★), realloc, calloc
	동적할당해제 함수 : free;
*/

//동적할당
/*
#include <stdio.h>

int main()
{
	int *pi;
	pi = (int *)malloc(sizeof(int)); //(int *) 생략 가능하기는 함. 하지만 해주는게 좋음
	
	//동적할당 되었는지 아닌지 확인하는거 중요!(실무에서)
	if (pi == NULL)
	{
		printf("동적할당 실패!");
		exit(1);
	}
	*pi = 10;
	printf("pi = %d \n", *pi);

	free(pi);
	return 0;
}
*/

//동적할당 배열
/*
#include <stdio.h>

int main()
{
	int *arr;
	arr = (int *)malloc(sizeof(int) * 7);

	if (arr == NULL)
	{
		printf("동적할당 실패!");
		exit(1);
	}

	//동적할당 배열에 값넣기
	for (int i = 0; i < 7; i++)
	{
		arr[i] = i + 10;	//포인터 배열의 시작주소를 담으면
							//포인터를 배열처럼 사용할 수 있다!!
	}
	//동적할당 배열의 값출력
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);

	return 0;
}
*/


/*
int 형 배열 10칸 배열을 동적할당해서
각각의 요서에 키보드로 입력한 정수값을 저장하세요
그리고 각 저정된 수의 합과 최소값/최대값을 구해보세요

[출력 예]
0 idx에 정수값 : 10
1 idx에 정수값 :5
2 idx에 정수값 :4
3 idx에 정수값 :22
4 idx에 정수값 :77
5 idx에 정수값 :123
6 idx에 정수값 :45
7 idx에 정수값 :33
8 idx에 정수값 :89
9 idx에 정수값 :122

총합 : ?, 최대값 : ?, 최소값 : ?
*/