//--------------------------------------------
//����Լ�
//--------------------------------------------

//�����θ� �ݺ������� ȣ���ϴ� ������ �ڵ带 �����ϴ� �Լ�

//1) ����Լ� �⺻

/*
#include <stdio.h>

void Recursive(int num)
{	
	if (num > 0)
	{
		printf("Recursive call!! : %d\n", num);
		Recursive(num - 1); //�ڽ��� ȣ��
	}
}

int main()
{
	Recursive(3);

	return 0;
}
*/


//2) ����Լ� �⺻

/*
#include <stdio.h>

void Recursive(int num)
{
	if (num > 0)
	{
		Recursive(num - 1); //�ڽ��� ȣ��
		printf("Recursive call!! : %d\n", num);
	}
}

int main()
{
	Recursive(3);

	return 0;
}
*/


//3) ����Լ� �⺻

/*
#include <stdio.h>

void Recursive(int num)
{
	if (num > 0)
	{
		printf("Recursive call!! : %d\n", num); //3 -> 2 -> 1
		Recursive(num - 1); //�ڽ��� ȣ��
		printf("Recursive call!! : %d\n", num); //1 -> 2 -> 3
	}
}

int main()
{
	Recursive(3);

	return 0;
}
*/


//4) ����Լ��� �̿��ؼ� 1���� 10������ �� ���ϱ�

/*
#include <stdio.h>

int recursive(int num)
{
	int total = 0;
	if (num > 0)
	{
		total = recursive(num - 1) + num; //����Լ� ȣ�� ����
		printf("num %d�� ���� total : %d\n", num, total);

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


//5) 1���� 10������ ������ 3�� ����� ���� ���� ���

//�� Ǯ��
/*#include <stdio.h>

int recursive(int num)
{
	int total = 0;
	if (num > 0)
	{
		if (num % 3 == 0)
		{
			total = recursive(num - 1) + num;
			printf("num %d�� ���� total : %d\n", num, total);

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

//�� Ǯ��
/*
#include <stdio.h>

int recursive(int num)
{
	int total = 0;
	//���޹��� ���ڰ� 3�� ����� �ɶ����� num�� ����
	while (num % 3 == 0)
	{
		num--;
	}
	//while�� �������ö� 9.6.3.0

	if (num > 0)
	{
	
		total = recursive(num - 1) + num;
		printf("num %d�� ���� total : %d\n", num, total);

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



//6) ����Լ��� �����

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



//����1
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
		//ó���Ǵ� �κ�
		star(n - 1, h);

		//������� �ݺ�
		for (int i = 0; i < h - n; i++)
		{
			printf(" ");	//���� ����(n==1:3��, 2:2��, 3:1��, 4:0��)
		}

		//����� �ݺ�
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


//����2
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




//8) �Ǻ���ġ ����
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



//9) ����Ž�� �˰����� ����Լ� ���·� �����ϱ�

/*
#include <stdio.h>

int BSearch(int *ar, int First, int Last, int target)
{
	int mid = 0;

	if (First <= Last)				//!!!! - ����Լ��� Ż������ if������ ����
	{
		mid = (First + Last) / 2;	//<--�ڵ��Է�(hint : Mid Index ����)

		if (target == ar[mid])		//�迭�� mid��° ��Ұ��� target�� ��ġ�Ѵٸ�
			return mid;				//mid�� ����

		else if (ar[mid] > target)						//�迭�� mid��° ��Ұ��� target���� ũ�ٸ�
			return BSearch(ar, First, mid - 1, target);	//!!!! - ����Լ�ȣ��! last�� mid-1�� ���� ���ڷ� ����

		else if (ar[mid] < target)						//�迭�� mid��° ��Ұ��� target���� �۴ٸ�
			return BSearch(ar, mid + 1, Last, target);	//!!!! - ����Լ�ȣ��! first�� mid+1�� ���� ���ڷ� ����
	}
	return -1;						//�ݺ����� ��� ������ first>last ���� Ŀ�����
									//target�� �迭�� �����Ƿ� -1�� ����
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;
	int num;

	for (int i = 0; i < 5; i++)
	{
		printf("���� �Է� : ");
		scanf_s("%d", &num);

		idx = BSearch(arr, 0, (sizeof(arr) / sizeof(int))-1, num);
		if (idx == -1)
			printf("Ž�� ���� \n");
		else
			printf("Ÿ�� ���� �ε���: %d \n", idx);
		printf("\n");
	}

	return 0;
}
*/



//10) �ϳ��� Ÿ��

/*
#include <stdio.h>

void Hanoi(int num, char from, char by, char to) //���ݰ���, ������, �������, �ű���
{
	if (num > 0)
	{
		Hanoi(num - 1, from, to, by);								//Hanoi ���ȣ�� num-1�� a->b �̵�
		printf("%c�� �ִ� %d��° ������ %c�� �ű�\n", from, num, to);	//printf ������ ������ c�� �̵�
		Hanoi(num - 1, by, from, to);								//hanoi ���ȣ�� num-1�� b->c �̵�

	}
}


int main(void)
{
	// ����A�� ���� 3���� ����B�� �����Ͽ� ����C�� �ű��
	Hanoi(2, 'A', 'B', 'C');
	return 0;
}
*/