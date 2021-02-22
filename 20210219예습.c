#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
}Node;

typedef struct CList
{
	Node* tail;		// ���� ��ġ ������
	int NodeCnt;	// ������ ���� Ȯ��
}List;


//�ʱ�ȭ�Լ�
void ListInit(List* plist)
{
	plist->tail = NULL;	// ���������� �ʱ�ȭ
	plist->NodeCnt = 0;	// ������ ���� �ʱ�ȭ
}


//����Ʈ ����Ʈ �Լ� 
void PrintList(List* plist)
{
	Node* head = plist->tail->next;
	if (plist->NodeCnt != 0)
	{
		for (int i = 0; i < plist->NodeCnt; i++)
		{
			printf("%d ", head->data);
			head = head->next;
		}
		printf("\n");
	}
}
//�������� ����
void LInsert(List* plist, int data)
{
	//1 ������
	Node* new = (Node*)malloc(sizeof(Node));
	if (new == NULL)
	{
		printf("�����Ҵ� ����!\n");
		exit(1);
	}
	new->data = data;	//2 ������ ���ֱ�
	new->next = NULL;	//3 ��ũ�� �ʱ�ȭ

	//4-1 ��尡 �ϳ��� ������
	if (plist->tail == NULL)
	{
		plist->tail = new;
		new->next = new;	 //plist->tail->next = new;
	}
	//4-2 ��尡 �ϳ��̻� ������
	else
	{
		new->next = plist->tail->next;
		plist->tail->next = new;
		plist->tail = new;
	}
	//5 ������ ���� ����
	plist->NodeCnt++;
}


//ó���� ����
void LInsertFront(List* plist, int data)
{
	//1. ������(NULL üũ) + �����Ͱ��ֱ� + ��ũNULL�ʱ�ȭ
	Node* new = (Node*)malloc(sizeof(Node));
	if (new == NULL)
	{
		printf("�����Ҵ� ����!\n");
		exit(1);
	}
	new->data = data;
	new->next = NULL;

	//2-1. ��尡 �ϳ��� ������
	if (plist->tail == NULL)
	{
		plist->tail = new;
		new->next = new;	 //plist->tail->next = new;
	}
	//2-2 ��尡 �ϳ��̻� ������
	else
	{
		new->next = plist->tail->next;
		plist->tail->next = new;
	}
	plist->NodeCnt++;
}


//��ȸ �Լ�
Node* SearchNode(List* plist, int target)
{
	//NodeCnt�� �̿��ؼ�(�ݺ��� ���) 
	//target�� ��ġ�ϴ� �����͸� ������ ����� �ּҸ� ��ȯ(����)
	//target�� ��ġ�ϴ� �����Ͱ� ������ NULL�� ��ȣ��(����)
	int num = plist->NodeCnt;
	Node* tmp = plist->tail->next;
	if (plist->NodeCnt == 0)
		return NULL;
	
	for (int i = 0; i < num; i++)
	{
		if (tmp->data == target)
			return tmp;
		else
		{
			tmp = tmp->next;
		}
	}
	return NULL;
}


//���� �Լ�
int LRemove(List* plist, int target)
{
	//1. ��ȸ
	//2. �������� ���
	//3. �������� �ƴ� ���
	Node *tmp = SearchNode(plist, target);
	if (tmp == NULL)
	{
		printf("������ ��尡 �����ϴ�.\n");
		return;
	}
	Node* pre = plist->tail->next;

	if (pre == NULL)
	{
		printf("����� ��尡 �����ϴ�.\n");
		return;
	}

	if (pre == tmp)
	{
		plist->tail->next = pre->next;
		free(tmp);
		plist->NodeCnt--;
		return;
	}

	else
	{
		while (pre->next != plist->tail)
		{
			if (pre->next == tmp)
			{
				pre->next = tmp->next;
				plist->NodeCnt--;
				return;
			}
			pre = pre->next;
		}
		pre->next = plist->tail->next;
		plist->tail = pre;
		plist->NodeCnt--;
		return;
	}
}


int main(void)
{
	//-----------------------------------
	// ���� ���� ����Ʈ�� ���� �� �ʱ�ȭ 
	//-----------------------------------
	List list;
	int data, i, nodeNum;
	ListInit(&list);
	int num;


	//-----------------------------------
	// ����忡 ����
	//-----------------------------------
	printf("\n--------(1) �� ��忡 ���� ---------\n");
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	PrintList(&list);


	//-----------------------------------
	// ù��忡 ���� /////// 
	//-----------------------------------
	printf("\n--------(2) ù ��忡 ���� ---------\n");
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	PrintList(&list);


	//-----------------------------------
	//����� ������ ��ȸ///////
	//-----------------------------------
	printf("\n--------(3) ������ ��ȸ ---------\n");
	printf("�� �Է�[��ȸ] : ");
	scanf_s("%d", &num);
	Node* cur = SearchNode(&list, num);
	if (cur == NULL)
		printf("�Է��� ���� ��ġ�ϴ� �����ʹ� �����ϴ�\n");
	else
		printf("�Է��� �� %d �� �����մϴ�\n", cur->data);


	//-----------------------------------
	//����///////
	//-----------------------------------
	printf("�� �Է�[����] : ");
	scanf_s("%d", &num);
	LRemove(&list, num);
	PrintList(&list);


	return 0;
}