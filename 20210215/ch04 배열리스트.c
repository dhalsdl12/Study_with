#include <stdio.h>
#include <string.h>

//������ ���� ��ȯ �Լ�
int Endlen(int* arr)
{
	int len = 0, i = 0;
	while (arr[i] != '\n')
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
	//1. ��������� �ִ��� ���� (�迭�� ������ idx�� NULL���� Ȯ��)
	//2. ������ ��ġ idx�� Ž��(Endlen()�Լ��� �̿��ؼ� idx�� Ȯ��)
	//3. �ش� idx��ҿ� ���޵� data���� ����

	int len = (sizeof(arr) / sizeof(int)) - 1; //�迭�� ������ idx����
	if (arr[len] == '\0') //������ �ִ� ����
	{
		int idx = Endlen(arr);
		arr[idx] = data;
	}
	else //���� ����
	{
		printf("������� ����!, ���ԺҰ�!\n");
	}
}


//������ ��ȸ �Լ�
int Search(int * arr, int target)
{
	return 0;
}

//������ �ߺ� ��ȸ �Լ�
void DSearch(int * arr, int target)
{

}
//������ ���� �Լ�
int Remove(int * arr, int target)
{
	return 0;
}

void main() {

	//������ ���� �迭 ����
	int Array[100] = { 0 };
	int n1 = 0;
	int rm = 0;

	//5���� ������ ����
	Insert(Array, 11); 	Insert(Array, 11);
	Insert(Array, 22); 	Insert(Array, 22);
	Insert(Array, 33);

	//����� ������  ���
	Output(Array);

}
