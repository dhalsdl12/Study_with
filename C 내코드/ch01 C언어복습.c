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


//����
/*
int �� �迭 10ĭ �迭�� �����Ҵ��ؼ�
������ �伭�� Ű����� �Է��� �������� �����ϼ���.
�׸��� �� ������ ���� �հ� �ּҰ�/�ִ밪�� ���غ�����.

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
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *arr = (int *)malloc(sizeof(int) * 10); //�����Ҵ�
	int sum = 0;	//���� ������
	int max = 0;	//�ִ밪
	int min = 0;	//�ּҰ�

	if (arr == NULL)
	{
		printf("�����Ҵ� ����!");
		exit(1);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d Idx��ҿ� �� �Է� : ", i);
		scanf_s("%d", &arr[i]); //scanf���� ���ȼ��� ���ݴ� ����
		sum += arr[i];
	}
	//�ּҰ� �ִ밪
	max = arr[0];
	min = arr[0];
	for (int i = 1; i < 10; i++)
	{
		if (max < arr[i]) //�� ��ҿ� max�� �� �� ū �� ����
			max = arr[i];
		if (min > arr[i]) //�� ��ҿ� min�� �� �� ���� �� ����
			min = arr[i];
	}
	//����� �� ���
	printf("sum = %d,  min = %d,  max = %d\n", sum, min, max);

	return 0;
}
*/


//2) �����Ҵ� ����Ȯ��(_msize())
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr1 = (int*)malloc(123);
	int len1 = sizeof(ptr1); //������ ������ ũ�⸦ ��ϴ�
	int len2 = _msize(ptr1); //�����Ҵ絵�� ������ ũ�⸦ ��ϴ�

	printf("sizeof�Լ��� �̿���  sizeȮ�� : %d\n", len1); //4
	printf("_msize�Լ��� �̿���  sizeȮ�� : %d\n", len2); //123

	return 0;
}
*/


//3) �迭�� �̸�
//�迭�� �̸��� �迭�� ���� �ּҸ� ����ִ� ������ ����̴�.
/*
#include <stdio.h>

int main()
{
	int arr[3] = { 11,22,33 };
	
	printf("ù��° ��� �� : %d\n", *arr);		//�迭�� ������ġ�� �� %d�� ���
	printf("�ι�° ��� �� : %d\n", *(arr+1));	//�迭�� ������ġ���� int * 1 ũ�� ���� ������ ���� �� %d�� ���
	printf("����° ��� �� : %d\n", *(arr+2));	//�迭�� ������ġ���� int * 2 ũ�� ���� ������ ���� �� %d�� ���

	//int num2 = 10;
	//arr = &num2; //arr�� ������ ���, �ٸ� �ּҸ� ���� ���� ����.

	return 0;
}
*/



//--------------------------------------------
//5. ���ڿ� ó�� �Լ�
//--------------------------------------------


//���� 1
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[20];
	char *ptr = "Hello World!";
	//--------------------------------------------
	//���ڿ� ����(strcpy_s(�������ּ�, ������ũ��, ���������ּ�)) - strcpy���� ���ȼ��� ����
	//--------------------------------------------
	strcpy_s(str1, sizeof(str1), ptr);
	printf("%s\n", str1);

	//--------------------------------------------
	//���ڿ� ����(strlen(���ڿ��� ����� ���� �ּ�))
	//--------------------------------------------
	printf("str1 �迭�� �� ���� : %d\n", sizeof(str1));
	printf("str1 ���� ���ڿ��� ���� : %d\n", strlen(str1));

	//--------------------------------------------
	//���鹮�ڸ� �����ϴ� �� �Է� (fgets(������ ���� �ּ�, ������� ũ��, stdin or FileStream))
	//--------------------------------------------
	char str2[20];
	char str3[20];

	printf("���ڿ� �Է�(scanf_s) : ");
	scanf_s("%s", str2, sizeof(str2)); //Ű����� ���ڿ��� �Է¹޾� str2�� ũ�⿡ �°� �����ϰڴ�
	rewind(stdin); //���� ���� �ʱ�ȭ

	printf("���ڿ� �Է�(fgets)   : ");
	fgets(str3, sizeof(str3), stdin); //strin(ǥ���Է½�Ʈ��, Ű����)�κ��� ���ڿ��� �޾� str3�� �����ϰڴ�.

	printf("str2 : %s\n", str2);
	printf("str3 : %s\n", str3);

	//--------------------------------------------
	//fgets�� �������� \n�����ϱ�
	//--------------------------------------------
	//\n���ڸ� �����ؼ� ���� ���� -> \n �����ϴ� �۾� ���ݵǾ�� �Ѵ�.

	//\n ���� �Է� Ȯ��
	printf("%s", str3); //%s�� \n�� �������� �ʾҴµ� str3�� ���� \n�� ����Ǿ��ֱ� ������ �ڵ����� �˴ϴ�.
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", str3[i]);
	}
	printf("\n");

	//--------------------------------------------
	//���๮�� �����ϱ�
	//--------------------------------------------
	int len = strlen(str3) - 1; // \n�� ����� ��ġ�� idx
	str3[len] = '\0';
	printf("%s\n", str3);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", str3[i]);
	}
	printf("\n");

	//--------------------------------------------
	//���ڿ� �� (strcmp(�����ּ�1, �����ּ�2))
	//--------------------------------------------
	if (strcmp(str1, str3) == 0) //�� ���ڿ� ������ 0��ȯ / �ٸ��� 0�ƴ� ���� ��ȯ
	{
		printf("�� ���ڿ��� �����ϴ�.\n");
	}
	else
	{
		printf("�� ���ڿ��� �ٸ��ϴ�.\n"); 
	}

	return 0;
}
*/



//--------------------------------------------
//6. �ԷµǴ� �������� ũ�⸸ŭ ���� �Ҵ�
//--------------------------------------------
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char buff[1024] = { 0 };	//�Էµ� ���ڿ� �ӽ� ���� �迭
	int len = 0;				//\n�� �����ϱ� ���� �뵵 idx ����
	char *name;					//�̸��� ����� �������� ���ε��� ������ ����
	char *addr;					//�ּҰ� ����� �������� ���ε��� ������ ����

	printf("�̸� : ");
	fgets(buff, sizeof(buff), stdin);	//Ű����κ��� �Էµ� ���ڿ��� buffũ�⸸ŭ buff�迭�� ����

	//\n ����
	len = strlen(buff) - 1;				//buff�ȿ� \n�� ��ġ idx�� len ����
	buff[len] = '\0';					//len idx(\n�� ��ġ)�� \0�� ����

	//�Էµ� �̸� ũ�⸸ŭ �����Ҵ�
	name = (char*)malloc(sizeof(char)*(len+1)); //len + 1�� 1�� \0�� ����� ������ �߰��ϴ� �۾�
												//char�� �迭 ��� ũ��� �ؼ� len+1 ������ �迭�� �����Ҵ�
												//�����ּҸ� name������ ������ ����
	//�����Ҵ� ���� ���� üũ
	if (name == NULL)
	{
		printf("�����Ҵ� ����!");
		exit(1);
	}
	//���ڿ� ����
	strcpy_s(name, _msize(name), buff);
	printf("�̸� : %s\n", name);
	printf("�̸��� ����� ������ ũ�� : %d\n", _msize(name));


	//�ּ��Է� �ް� ����ϱ�
	printf("�ּ� : ");
	fgets(buff, sizeof(buff), stdin);
	len = strlen(buff) - 1;
	buff[len] = '\0';


	addr = (char*)malloc(sizeof(char)*(len + 1));
	if (addr == NULL)
	{
		printf("�����Ҵ� ����!");
		exit(1);
	}

	strcpy_s(addr, _msize(addr), buff);
	printf("�ּ� : %s\n", addr);
	printf("�ּ��� ����� ������ ũ�� : %d\n", _msize(addr));

	return 0;
}
*/



//--------------------------------------------
//����ü �⺻
//--------------------------------------------

//1) ����ü �⺻ ����
/*
#include <stdio.h>

typedef struct person {
	char name[30];
	int age;
	float weight;
	double height;
}Person;
int main()
{
	//����ü �⺻
	struct person Lee = { "������", 35, 67.5f, 177.5 };
	printf("%s %d %f %lf\n", Lee.name, Lee.age, Lee.weight, Lee.height);

	//typedef ���
	Person Kim = { "�����", 40, 77.7f, 177.5 };
	printf("%s %d %f %lf\n", Kim.name, Kim.age, Kim.weight, Kim.height);
	printf("\n");

	//����ü �迭
	Person empolyee[3] = {
		{"ȫ�浿", 50, 56.6f, 188.7},
		{"���浿", 60, 60.6f, 188.8},
		{"������", 70, 65.6f, 180.2}
	};
	for (int i = 0; i < 3; i++)
	{
		printf("%s %d %f %lf\n", empolyee[i].name, empolyee[i].age, empolyee[i].weight, empolyee[i].height);
	}
	printf("\n");

	//����ü ������
	Person *ptr = &Kim;		//�����ͷ� ����ü ������ ����
	printf("%s\n",  ptr->name);	//kim�� name����� ����
	printf("%d\n",  ptr->age);		//kim�� age����� ����
	printf("%f\n",  ptr->weight);	//kim�� weight����� ����
	printf("%lf\n", ptr->height);	//kim�� height����� ����
					// '->'�� �����Ͱ� �ƴϸ� ����Ҽ� ����
	printf("\n");

	return 0;
}
*/

//2) ����ü ���� ������ ��
/*
#include <stdio.h>
#include <string.h>

typedef struct person
{
	char name[30];
	int age;
}Person;

int main()
{
	Person Lee = { "������", 29 }; //����ü ���� ������ ���ÿ� �ʱ�ȭ

	Person Kim;			//����ü ������ ����(��������)...�ʱⰪ�� ������

	Kim.age = 50;
//	Kim.name = "�����";		//[����] �̺κп��� ������ ������ �ߴ� ������??? -> �迭�� �̸��� ������ ����̴�.
							//������� ���� �ٸ������� ���� �Ұ�
							//strcpy_s()�� ���ڿ� ���縦 ���ؼ� �� �����Ѵ�.
	strcpy_s(Kim.name, sizeof(Kim.name), "�����");
	printf("%s %d\n", Kim.name, Kim.age);


	return 0;
}
*/

//3) �ڱ����� ����ü
/*
#include <stdio.h>

typedef struct person {
	char name[30];			//�̸������ �迭
	struct person *next;	//�ڱ����� ������

}Person;

int main()
{
	//����ü�� ����
	Person Jung = { "�����", NULL };
	Person Lee = { "������", &Jung };
	Person Kim = { "�����", &Lee };
	Person *L = &Kim;

	//L�����ͷ� �� ����ü ���� ����� �̸��� ����
	printf("%s\n", L->name);				//�����
	printf("%s\n", L->next->name);			//������
	printf("%s\n", L->next->next->name);	//�����
	printf("\n");

	//�ݺ����� ���� ����� ����ü�� ����(�ڡڡ�)
	Person *cur = L;
	while (cur != NULL)
	{
		printf("%s\n", cur->name);	//cur�����Ͱ� ����Ű�� ���� name ���
		cur = cur->next;			//���� ����ü ���� �̵� �ڵ�
	}

	return 0;
}
*/



//--------------------------------------------
//�����Ҵ� + ������ + ����ü
//--------------------------------------------
/*
#include <stdio.h>

typedef struct person {
	char name[20];	//����ü ��� ������ name ����
	char *addr;		//��� pool�� ����� ���ڿ��� �ּҸ� ��� ������
	struct person *next;
}Person;

int main()
{
	Person *node = (Person *)malloc(sizeof(Person));
	
	if (node == NULL)
	{
		printf("�����Ҵ� ����!");
		exit(1);
	}

	//node->name = "�����"; X		//node->name�� �迭�̸�, �迭�̸��� ������ ����̹Ƿ� �ٸ��ּҸ�
									//���� �� ����!!
	struct_s(node->name, sizeof(node->name), "�����");
	node->addr = "�뱸������ �޼��� ���糲��~";		//O addr�� node����ü�� ���������'����!!'�̴�
													//���� ���� �����ϹǷ� ���ڿ� ����� �ּҸ� ���� �� �ִ�!
	node->next = NULL;

	node->next = (Person *)malloc(sizeof(Person));

	strcpy(node->next->name, sizeof(node->next->name), "�����");
	node->next->addr = "����Ư����~";
	node->next->next = NULL;

	return 0;
}
*/

/*
����
���� ���� ����ü�� �����Ͽ� �� �����͸� ��� ����ü�� �����Ҵ��Ͽ� ������ ��
�� �����Ҵ�� ����ü ������ ���� ������ ������ �����غ��ϴ�
�׸��� ����� ����ü ������ �ݺ����� ���ؼ� ���ʴ�� ����غ��ϴ�
*/
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bookinfo {
	int bookCode;
	char bookName[30];
	struct bookinfo *next;
}BookInfo;

int main()
{
	BookInfo *L = (BookInfo *)malloc(sizeof(BookInfo));
	if (L == NULL)
	{
		printf("�����Ҵ� ����!");
		exit(1);
	}
	L->bookCode = 1010;
	strcpy_s(L->bookName, sizeof(L->bookName), "�������ǿ���C");
	L->next = NULL;


	L->next = (BookInfo*)malloc(sizeof(BookInfo));
	if (L->next == NULL)
	{
		printf("�����Ҵ� ����!");
		exit(1);
	}
	L->next->bookCode = 2020;
	strcpy_s(L->next->bookName, sizeof(L->next->bookName), "�̰��̸�������");
	L->next->next = NULL;

	while (L != NULL)
	{
		printf("code: %d,  name: %s\n", L->bookCode, L->bookName);
		L = L->next;
	}
	printf("\n");
	
	
	return 0;

}
*/
/*
	ù ��忡 �����Ҵ��� ����ü ������ �����ּҸ� ����
	ù ��忡 ���� bookCode = 1010, bookName �迭�� "�������ǿ���C"�� ����
	ù ��� next�����Ϳ� �ΰ� �ʱ�ȭ
	�ι�° ��� �����Ҵ� �ϸ鼭 �� �ּҸ� ù ����� next�� ����
	�ι�° ����� bookcode = 2020, bookname�迭�� "�̰��̸�������"�� ����
	�ι�° ����� next�����Ϳ���NULL�� ����
*/
