#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

// ����Ʈ�� ����
listNode* L;	//��������


// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList() {
	listNode* p;
	listNode* cur = L;

	while (cur != NULL) {
		p = cur;
		cur = cur->link;
		free(p);
	}

	L = NULL;
}


// ���� ����Ʈ�� ������� ����ϴ� ����
void printList() {
	listNode* cur = L;

	printf("L = (");
	while (cur != NULL) {
		printf("%s", cur->data);
		cur = cur->link;
		if (cur != NULL)
			printf(", ");
	}
	printf(") \n");
}


// ù ��° ���� �����ϴ� ����
void insertFirstNode(char* x) {

	//1 new ��� ����(����ü+�����Ҵ�+������)-> Nullüũ 
	listNode *new = (listNode*)malloc(sizeof(listNode));
	if (new == NULL)
	{
		printf("�����Ҵ� ����!\n");
		exit(1);
	}
	//2 ������ �κ� ������
	strcpy_s(new->data, sizeof(new->data), x);
	//3 ��ũ Null ����
	new->link = NULL;

	//4-1 ��尡 �ϳ��̻� �ִ°�� -> ó����ġ�� ����
	if (L != NULL)
	{
		new->link = L;
		L = new;
	}

	//4-2 ��尡 �ϳ��� ���°�� -> ����L�����Ϳ� ��� �ٷο��� 
	else
	{
		L = new;
	}

}


// ������ ���� �����ϴ� ����
void insertLastNode(char* x) {
	//1 new ��� ����(����ü+�����Ҵ�+������)-> Nullüũ 
	listNode *new = (listNode*)malloc(sizeof(listNode));
	if (new == NULL)
	{
		printf("�����Ҵ� ����!\n");
		exit(1);
	}
	//2 ������ �κ� ������
	strcpy_s(new->data, sizeof(new->data), x);
	//3 ��ũ Null ����
	new->link = NULL;

	//4-1 ��尡 �ϳ��̻� �ִ°�� -> ������ ��ġ�� ���� �ڵ� �ۼ� 
	if (L != NULL)
	{
		listNode *tmp = L;
		//5 tmp �����͸� ���� �� ��带 ��ȸ(tmp=tmp->link)�ϸ鼭 ��������ġ(link�� NULL) ���� Ȯ��
		while (tmp->link != NULL)
		{
			tmp = tmp->link;
		}
		//6 ��������ġ���� ����带 ����
		tmp->link = new;
	}
	//4-2 ��尡 �ϳ��� ���°�� -> ����L�����Ϳ� ��� �ٷο��� 
	else
	{
		L = new;
	}
}


// ����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(char* x) {
	//1 Ž���� ����ü ������(tmp) ����
	//2 ����� �����ּҸ� tmp�����Ϳ� ����
	listNode *tmp = L;

	if (L == NULL)
		return NULL;

	//3 ����带 ��ȸ(tmp=tmp->link)�ϸ鼭 ã�� ���ڿ��� ��ġ�ϴ� ���ڿ� Ȯ��(strcmp(�ּ�1,�ּ�2))
	while (tmp != NULL)
	{
		//4-1 ã���� �ش� ����� �ּҸ� ���� 
		if (strcmp(tmp->data, x) == 0)	//������ ��ġ
		{
			return tmp;
		}
		tmp = tmp->link;
	}
	//4-2 tmp==NULL(tmp�� ��ü��带 ��ȸ) �̶�� NULL�� ����
	return NULL;
}


listNode* ssearchNode(char* x) {
	listNode *tmp = L;

	//1) ��尡 �ϳ��� ���� ���
	if (L == NULL)
		return NULL;

	//��尡 ������
	while (tmp != NULL)
	{
		if (strcmp(tmp->data, x) == 0)	//������ ��ġ
		{
			break;
		}
		tmp = tmp->link;
	}
	//2) ��尡 �ϳ��̻� �ִ� ���(������ �����Ͱ��� �ּҰ� tmp�� ��ܼ� break���)
	//3) ����� ���������� �̵��� ���(��ġ�ϴ� �����Ͱ� ����)
	return tmp;
}


// ��带 pre �ڿ� �����ϴ� ����
void insertMiddleNode(listNode* pre, char* x) {

}


// ����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(listNode* p) {

}


int main() {
	listNode* p;
	L = NULL;               //���� ����Ʈ ����


	// ������ ����(ù���)
	printf("----------(1) ù��忡 ���� [��][��] ----------\n");
	insertFirstNode("��");
	insertFirstNode("��");
	printList();


	// ������ ����(�����)
	printf("\n----------(2) ������ ��忡 ���� [��][��][��] ----------\n");
	insertLastNode("��");
	insertLastNode("��");
	insertLastNode("��");
	printList();


	// ������ Ž��

//	printf("\n----------(4) ����Ʈ���� [��] ��� Ž���ϱ�!----------\n");
//	char s[4];
//	scanf_s("%s", s, sizeof(s));
//	p = searchNode(s);
//	if (p == NULL)
//		printf("ã�� �����Ͱ� �����ϴ�.\n");
//	else
//		printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);
//
//	printf("\n----------(3) ����Ʈ���� [��] ��� Ž���ϱ�! ----------\n");
//	p = searchNode("��");
//	if (p == NULL)
//		printf("ã�� �����Ͱ� �����ϴ�.\n");
//	else
//		printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);
	printf("\n----------(3) ����Ʈ���� ��� Ž���ϱ�!----------\n");
	for (int i = 0; i < 3; i++)
	{
		printf("��� �Է� : ");
		char s[4];
		scanf_s("%s", s, sizeof(s));
		p = searchNode(s);
		if (p == NULL)
			printf("[%s] �����Ͱ� �����ϴ�.\n", s);
		else
			printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);
		printf("\n");
	}

	freeLinkedList();               //����Ʈ �޸� ����
	return 0;
}