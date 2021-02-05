//--------------------------------------------
//1. �迭
//--------------------------------------------

//1) �迭 ũ��Ȯ��
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

	printf("char  c ũ�� : %d, char  c_array ũ�� : %d\n", sizeof(c), sizeof(c_array));
	printf("int   i ũ�� : %d, int   i_array ũ�� : %d\n", sizeof(i), sizeof(i_array));
	printf("short s ũ�� : %d, short s_array ũ�� : %d\n", sizeof(s), sizeof(s_array));
	printf("float f ũ�� : %d, float f_array ũ�� : %d\n", sizeof(f), sizeof(f_array));
	printf("long  l ũ�� : %d, long  l_array ũ�� : %d\n", sizeof(l), sizeof(l_array));


	return 0;
}
*/

//2) ���ڹ迭 vs ���ڿ�
/*
#include <stdio.h>

int main()
{
	char str1[4] = "abc";  //���ڿ�o, ���ڹ迭o
	char str2[4] = "abcd"; //���ڿ�x, ���ڹ迭o

	printf("str1 = %s\n", str1); //�������
	printf("str2 = %s\n", str2); //��������� (���ڿ��� ��, NULL�� ��ġ�� �ľ����� ����)

	return 0;
}
*/



//--------------------------------------------
//2. �帧���
//--------------------------------------------

//1) ��ü ������ �� ���
/*
2~9��
��ø while���� �̿�
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

//2) �����
/*
			i    k(����)     j(*)
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
	int i = 0; //�ٹٲ޿�
	int k = 0; //�������
	int j = 0; //�����

	while (i<4)
	{
		//�������
		k = 0;
		while (k <= 2 - i)
		{
			printf(" ");
			k++;
		}
		//�����
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


//����� ����
/*
			i    k(����)     j(*)
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
������ �ϳ��� �Է¹޾� �ش� �� ��ŭ�� �����۾��� �̷����鼭
���ﰢ�� ����� ���� ����� ������

[��� ��]
���� �Է� : 5
	   *
	  ***
	 *****
	*******
   *********
*/
/*
i     k(����)          j(*)
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

	printf("���� �Է� : ");
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
//3. ������ 
//--------------------------------------------
/*
Point : ��, ����Ű��
Pointer : ����Ű�� ����

Ư�� ������ ��ġ����(�޸��ּ�)�� ��� �޸𸮰����� ����(������ �� ����/����)�� �� �ִ� Ư������

��������
1. �Ϲ� ����
	- �����Ͱ��� ����
2. ������ ����
	- �޸��ּҰ��� ����

������ ������
	* : �����Ϳ�����
	& : ����������
*/
/*
#include <stdio.h>

int main()
{
	int num = 3;				//3���� int ���� num�� ����
	int *ptr = &num;			//num�� �޸� �ּҰ��� int ũ�⸦ ����Ű�� ptr������ ������ �ʱ�ȭ
	*ptr = 10;					//10���� ptr�����Ͱ� ����Ű�� ������ ����

	int num2 = *ptr;			//ptr�� ����Ű�� ���� ���� num2������ �ʱ�ȭ
	printf("*ptr = %d", *ptr);	//ptr�� ����Ű�� ���� ���� 10�� ���� ������ �°� ���

	return 0;
}
*/

//1)������ ����
//�޸𸮸� �׸��� �����ʿ� �ּ����� �ؼ��غ��ϴ�.
/*
#include <stdio.h>

int main()
{
	int num = 10;			//10 ������� num ���� ������ �ʱ�ȭ
	int *ptr1 = &num;		//num�� �޸� �ּҰ��� intũ�� ������ ����Ű�� ptr1�����Ϳ� �ʱ�ȭ
	int *ptr2 = ptr1;		//ptr1���� ��(�ּҰ�)�� ptr2�����Ϳ� �ʱ�ȭ

	(*ptr1)++;				//ptr1�� ����Ű�� ���� ���� 1���� - num = 11
	(*ptr2)++;				//ptr2�� ����Ű�� ���� ���� 1���� - num = 12
	printf("%d\n", num);

	return 0;
}
*/

//2) �����Ϳ� �迭
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

//3) �����Ϳ� �Լ�
/*
Call-by-value	: �Լ��� �����Ҷ� �����ϴ� ���ڰ� ������ ���� ���
Call-by-address : �Լ��� �����Ҷ� �����ϴ� ���ڰ� �޸��ּҰ��� ���
Call-by-Reference(C++) : �Լ��� �����Ҷ� �����ϴ� ���ڰ� �������� ���
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
	printf("Swap �� a = %d,  b = %d\n", a, b);
	Swap(a, b); //Call-by-value
	printf("Swap �� a = %d,  b = %d\n", a, b);

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
	printf("Swap �� a = %d,  b = %d\n", a, b);
	Swap(&a, &b); //Call-by-address
	printf("Swap �� a = %d,  b = %d\n", a, b);

	return 0;
}
*/

//4) �����Ϳ� ���ڿ�
/*
#include <stdio.h>

int main()
{
	char arr[20] = "hello World"; //�迭������ ���� ���� ���ڿ� ������� ����
	char *ptr1 = "hello World";
	char *ptr2 = "hello World";

	printf("arr�迭�� �ּ�     : %x\n", arr); //�迭�� �̸��� �迭�� �����ּҸ� ����ִ� ������ ����̴�.
	printf("hello World�� �ּ� : %x\n", "hello World");
	printf("ptr1 ���� �ּ�     : %x\n", ptr1); //"hello World"��� ���ڿ� ����� ����Ŵ (ptr1 == ptr2)
	printf("ptr2 ���� �ּ�     : %x\n", ptr2); //"hello World"��� ���ڿ� ����� ����Ŵ (ptr1 == ptr2)

	return 0;
}
*/



//--------------------------------------------
//4. �����Ҵ�
//--------------------------------------------

/*
�ڵ� ����	: �����ϵ� ������ ����
������ ����	: �����޸𸮿���(��������, static����)
			  ���α׷� ���۽� ���� -> ���α׷� ����� �Ҹ�
���� ����	: �߰�ȣ({}) ������ ����Ǿ����� ����(��������)
			  �߰�ȣ���� ���� -> �߰�ȣ�� ����� �Ҹ�
�� ����		: �����Ҵ� ����
			  malloc�Լ��� ���� ���� -> free�Լ� ��� �� ���� �Ҹ�
*/

/*
�����Ҵ� : �ʿ��� ��ŭ ������ �Ҵ� �޾� �����ϱ� ���� ����
	�����Ҵ��� Heap ������ ������ �ȴ�
	�����Ҵ� �Լ� : malloc(��), realloc, calloc
	�����Ҵ����� �Լ� : free;
*/

//�����Ҵ�
/*
#include <stdio.h>

int main()
{
	int *pi;
	pi = (int *)malloc(sizeof(int)); //(int *) ���� �����ϱ�� ��. ������ ���ִ°� ����
	
	//�����Ҵ� �Ǿ����� �ƴ��� Ȯ���ϴ°� �߿�!(�ǹ�����)
	if (pi == NULL)
	{
		printf("�����Ҵ� ����!");
		exit(1);
	}
	*pi = 10;
	printf("pi = %d \n", *pi);

	free(pi);
	return 0;
}
*/

//�����Ҵ� �迭
/*
#include <stdio.h>

int main()
{
	int *arr;
	arr = (int *)malloc(sizeof(int) * 7);

	if (arr == NULL)
	{
		printf("�����Ҵ� ����!");
		exit(1);
	}

	//�����Ҵ� �迭�� ���ֱ�
	for (int i = 0; i < 7; i++)
	{
		arr[i] = i + 10;	//������ �迭�� �����ּҸ� ������
							//�����͸� �迭ó�� ����� �� �ִ�!!
	}
	//�����Ҵ� �迭�� �����
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
int �� �迭 10ĭ �迭�� �����Ҵ��ؼ�
������ �伭�� Ű����� �Է��� �������� �����ϼ���
�׸��� �� ������ ���� �հ� �ּҰ�/�ִ밪�� ���غ�����

[��� ��]
0 idx�� ������ : 10
1 idx�� ������ :5
2 idx�� ������ :4
3 idx�� ������ :22
4 idx�� ������ :77
5 idx�� ������ :123
6 idx�� ������ :45
7 idx�� ������ :33
8 idx�� ������ :89
9 idx�� ������ :122

���� : ?, �ִ밪 : ?, �ּҰ� : ?
*/