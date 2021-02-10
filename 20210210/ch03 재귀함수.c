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