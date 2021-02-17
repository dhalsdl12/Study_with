#include <stdio.h>
#include <string.h>

//������ ���� ��ȯ �Լ�
int Endlen(int* arr)
{
	int len = 0, i = 0;
	while (arr[i] != '\0')
		i++;
	return i;
}


//������ ��� �Լ�
void Output(int* arr)
{
	int len = Endlen(arr);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

}


//������ ���� �Լ�
void Insert(int * arr, int data)
{
	//�������� ���� Ȯ��(�迭�� ������ �� idx(98)�� 0(NULL)���� Ȯ��)
	//->99 idx���� �����͸� ��ԵǸ� Endlen() ����Ҽ��� ����..
	//������ ��ġ idx�� Ž��(Endlen()�Լ��� �̿��ؼ� idx�� Ȯ��)
	//�ش� idx��ҿ� ���޵� data���� ����
	
	//int len = (sizeof(arr) / sizeof(int)) - 1;
				//sizeof()���� ������ ������ ���ڷ� ������ ����.
				//������ ������ ��ü�� ����� ���.	
				//len = 4/4-1 = 0
	if (arr[98] == 0) //���� ����x
	{
		int idx = Endlen(arr);	//������ġ �ε����� idx������ ����
		arr[idx] = data;		//������ data�� arr�迭�� idx��°�� ����
	}
	else //���� ����o
	{
		printf("�迭�� �����Ͱ� ���� �����Դϴ�. �� ������ �Ұ���...\n");
	}
}


//������ ��ȸ �Լ�
int Search(int * arr, int target)
{
	//����Ž��
	//0 idx���� ���ʷ� �˻�(Endlen()�� ���ؼ� ����� ���� ���̸� Ȯ���� �� �ݺ�)
	//idx��ҿ� target�� ���ؼ� ��ġ�ϸ� idx����
	//����ġ -1����
	int len = Endlen(arr);	//����� ���� ���� ��ȯ
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == target)
			return i;
	}

	return -1;
}


//������ �ߺ� ��ȸ �Լ�
void DSearch(int * arr, int target)
{
	//����Ž��
	//��ȸ �ߺ��Ǿ�����
	//�ߺ��� idx�� ����� �ִ����� ȭ�鿡 print
	//[��¿�]
	//11 11 22 22 33
	//��ȸ�� �Է� : 22
	//22�� 2,3 idx�� �� 2ȸ �ߺ��Ǿ��ֽ��ϴ�.

	int count = 0;	//�ߺ��� ȸ���� ������ �뵵
	int len = Endlen(arr);
	int a[100] = { 0 };
	for (int i = 0; i < len; i++)
	{
		if (target == arr[i])
		{
			a[count] = i;
			count++;
		}
	}
	if (count != 0)
	{
		printf("%d�� ", target);
		for (int i = 0; i < Endlen(a); i++)
		{
			if (a[i] != 0)
				printf("%d ", a[i]);
		}
		printf("idx�� �� %dȸ �ߺ��Ǿ��ֽ��ϴ�.\n", count);
	}
	else
		printf("%d�� �����ϴ�.", target);
}
void sDSearch(int * arr, int target)
{
	int cnt = 0;

	printf("%d�� ", target);
	for (int i = 0; i < Endlen(arr); i++)
	{
		if (arr[i] == target)
		{
			cnt++;
			printf("%d,", i);
		}
	}
	//cnt == 0 -> target�� ��ġ�ϴ� ������ 1�̻�
	if (cnt != 0)
	{
		printf("\b idx�� �� %d�� �ݺ��Ǿ����ϴ�\n", cnt);
	}
	//cnt == 0 -> target�� ��ġ�ϴ� ������x
	else
	{
		printf("�ش簪�� ��ȸ���� �ʽ��ϴ�\n");
	}
}


//������ ���� �Լ�
void Remove(int * arr, int target)
{
	//1. ������ �����͸� ��ȸ�� �����Ͱ� �ִٸ�
	//2. �ش� �迭 ��ġ�� ��� �ڿ� �ִ� ��� ������ ������ġ�� ��ĭ�� �̵��ؼ� ����� ���·� ����
	//3. ������ �����Ͱ� ���ٸ� "�ش� �����ʹ� ����\n" ���
	int result = Search(arr, target);	//1. ��ȸ�� ������ x or ���� �ش�Ǵ� idx�� ��ȯ
	int len = Endlen(arr);			//�� ���� ������ ����
	
	if (result != -1)	//���� ������ o
	{
		for (int i = result; i < len; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
	else			//���� ������ x
		printf("�ش� �����ʹ� �����ϴ�.\n");
}


//�ߺ��� ������ ���� �Լ�
void DRemove(int* arr, int target)
{
	//���� ���� �ִٸ� ��ü ��� ��(������)
	//�Ǵٽ� ����۾��� �ؾ���
	//��ø while�����
	int result = Search(arr, target);
	int len = Endlen(arr);

	if (result != -1)
	{
		while (result != -1)
		{
			for (int i = result; i < len; i++)
			{
				arr[i] = arr[i + 1];
			}
			result = Search(arr, target);
			len = Endlen(arr);
		}
	}
	else
		printf("�ش� �����ʹ� �����ϴ�.\n");
}
void sDRemove(int* arr, int target)
{
	//���� ���� �ִٸ� ��ü ��� ��(������)
	//�Ǵٽ� ����۾��� �ؾ���
	//��ø while�����
	int result = Search(arr, target);
	int len = Endlen(arr);

	if (result != -1)
	{
		for(int k = result; k < len; k++)
		{
			for (int i = k; i < len; i++)
			{
				arr[i] = arr[i + 1];
			}
			if (arr[k] == target) //����� k idx�� ��Ұ��� target�� ������ ��Ȳ
			{
				k--;	//k 1���� -> �ݺ����ǽ����� �ö󰡸� 1���� �Ǳ� ������ �ش� �ڸ�����
						//�ڿ��ִ� ��ҵ��� ������ ��������
				len = Endlen(arr);	//len�� ����� �ѱ��� �ٽ� ���� -> ������ ��ŭ �ݺ� Ƚ�� ����
			}
		}
	}
	else
		printf("�ش� �����ʹ� �����ϴ�.\n");
}
void main()
{
	//������ ���� �迭 ����
	int Array[100] = { 0 };
	int rm = 0;


	//5���� ������ ����
	Insert(Array, 11); 	Insert(Array, 11);
	Insert(Array, 22); 	Insert(Array, 22);
	Insert(Array, 33);	Insert(Array, 22);


	//����� ������  ���
	Output(Array);


	//����� ������  ��ȸ
	int n1 = 0;
	printf("��ȸ�� �Է� : ");
	scanf_s("%d", &n1);
	int result = Search(Array, n1);

	if (result != -1)
		printf("Ž���Ϸ� idx : %d\n", result);
	else
		printf("�ش� ���� ����Ǿ����� �ʽ��ϴ�\n");


	//�ߺ� ������  ��ȸ
	sDSearch(Array, n1);
	printf("\n");


	//������  ����
	printf("������ �Է� : ");
	scanf_s("%d", &rm);
	Remove(Array, rm);
	Output(Array);


	// �ߺ��� ������ ����
	printf("������ �Է�(�ߺ������� ��� ����) : ");
	scanf_s("%d", &rm);
	sDRemove(Array, rm);
	Output(Array);

}