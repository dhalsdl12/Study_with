#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
	char key;				// ������ �ʵ�
	struct treeNode* left;	// ���� ���� Ʈ�� ��ũ �ʵ�
	struct treeNode* right;	// ������ ���� Ʈ�� ��ũ �ʵ�
} treeNode;

treeNode* root = NULL;


//Ž�� �Լ�
treeNode* search(char x)
{

	// 1 ���۳�� �ּ� *p �� ����
	treeNode *p = root;
	if (p == NULL)
		return NULL;

	// 2 p�� NULL�϶����� ��� �ݺ�
	while (p != NULL)
	{
		// 3 p->key�� x �� �� 
		// 3-1 p->key == x		-> ����ּ� return
		// 3-1 p->key > x		-> p->left�� �̵�
		// 3-1 p->key < x		-> p->right�� �̵�
		if (p->key == x)
		{
			return p;
		}
		else if (p->key > x)
		{
			p = p->left;
		}
		else if (p->key < x)
		{
			p = p->right;
		}
	}

	//������ Ű�� ����
	//printf("�ش� Ű�� �������� �ʽ��ϴ�.\n"); -> �����Լ����� �����
	return NULL;
}


// ��� ���� �Լ� 
void insertNode(char x) {
	//0. �ߺ�Ű ���� ����
	if (search(x) != NULL)
		return;

	//1. ������
	//2. �����Ͱ� �ֱ�
	//3. ��ũ NULL �ʱ�ȭ
	treeNode *new = (treeNode*)malloc(sizeof(treeNode));
	if (new == NULL)
	{
		printf("�����Ҵ� ����!\n");
		exit(1);
	}
	new->key = x;
	new->left = NULL;
	new->right = NULL;


	//4. ���x
	if (root == NULL)
	{
		root = new;
	}

	//5. ��� 1�̻� ����
	else
	{
		treeNode *cur = root;	//������ġ Ž��
		treeNode *par = NULL;	//������ġ�� �θ��� Ž��
		
		while (cur != NULL)
		{
			par = cur;
			if (par->key > x)
			{
				cur = cur->left;
			}
			else if (par->key < x)
			{
				cur = cur->right;
			}
		}

		//par�� ��ġ Ž��
		//cur == NULL
		if (par->key > x)
			par->left = new;
		else
			par->right = new;
	}
}


// ��� ���� �Լ� 
//(�ڽ�x, �ڽ�1, �ڽ�2) -> ����� �����
void mydeleteNode(char key)
{
	//00. ��尡 �ϳ��� ���� ���
	if (root == NULL)
	{
		printf("��尡 �����ϴ�.\n");
		return;
	}

	//01. ��ȸ(��� ������ return, ������ 02����)
	if (search(key) == NULL)
	{
		printf("������ ��尡 �����ϴ�.\n");
		return;
	}

	//02. ��������ּ�(Node *cur)�� ���� �θ����ּ�(Node *par) Ž��
	treeNode *cur = search(key);
	treeNode *par = root;
	while (par->left != cur && par->right != cur)
	{
		if (par->key > key)
			par = par->left;
		else
			par = par->right;
	}
	printf("������� Ȯ�� : %c\n", cur->key);
	printf("������� �θ� Ȯ�� : %c\n", par->key);
	//03. ��������� �ڽĳ���� ���� ȭ�뤤
	//03-1. ��������� �ڽĳ�� x
	//03-2. ��������� �ڽĳ�� 1
	//03-3. ��������� �ڽĳ�� 2
}
void deleteNode(char key)
{
	//00. ��尡 �ϳ��� ���� ���
	if (root == NULL)
	{
		printf("��尡 �����ϴ�.\n");
		return;
	}

	//01. ��ȸ(��� ������ return, ������ 02����)
	if (search(key) == NULL)
	{
		printf("������ ��尡 �����ϴ�.\n");
		return;
	}

	//02. ��������ּ�(Node *cur)�� ���� �θ����ּ�(Node *par) Ž��
	treeNode *cur = root;
	treeNode *par = NULL;
	while (cur->key != key)
	{
		par = cur;
		if (cur->key > key)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}
	//cur��ġ Ž���Ϸ�
	//par��ġ Ž���Ϸ�(par�� NULL�� ����Ǿ��ִٸ� ���� ���� root ��尡 �ȴ�)

	//03. ��������� �ڽĳ���� ���� Ȯ��
	if (cur->left == NULL && cur->right == NULL)		//03-1. ��������� �ڽĳ�� x
	{
		if (par == NULL)	//���� ��尡 rootNode�� ���
		{
			root = NULL;	//root �����Ϳ� NULL(��� ������ ����)
			free(cur);		//�������
		}
		else
		{
			if (par->left == cur)
				par->left = NULL;
			else
				par->right = NULL;
			free(cur);
		}
	}
	else if(cur->left == NULL || cur->right == NULL)	//03-2. ��������� �ڽĳ�� 1
	{
		if (par == NULL)	//���� ��尡 root ����� ���
		{
			if (cur->left != NULL)
			{
				root = cur->left;
			}
			else
			{
				root = cur->right;
			}
		}
		else				//���� ��尡 root��尡 �ƴѰ��
		{
			//�ڽĳ�� �ּҸ� ���� ������
			treeNode *son = NULL;
			//son�� ��ġ�� Ȯ���ؼ� ����
			if (cur->left != NULL)
				son = cur->left;
			else
				son = cur->right;

			if (par->left == cur)
			{
				par->left = son;
			}
			else
			{
				par->right = son;
			}
		}
		free(cur);
	}
	else if (cur->left != NULL && cur->right == NULL)	//03-3. ��������� �ڽĳ�� 2
	{
		if (par == NULL)	//������尡 rootNode�� ���
		{

		}
		else				//������尡 rootNode�� �ƴѰ��
		{
			treeNode *succ_par = cur;
			treeNode *succ = cur->left;

			while (succ->right != NULL)
			{
				succ_par = succ;
				succ = succ->right;
			}
			//succ�� ��ġ succ->right==NULL ��带 ����Ų��
			//succ_par ��ġ succ�� ������� ����Ų��.

			//succ_par->left == succ ==> �� �ݺ��۾��� �ѹ��� �������� ���� ����
			//succ_par->left != succ ==> �� �ݺ��۾��� �����ؼ� ������ ����带 Ž���� ����

			if (succ_par->left == succ)
			{
				cur->key = succ->key;
				succ_par->left = succ->left;
			}
			else
			{
				succ_par->right = succ->left;
				cur->key = succ->key;
			}
			free(succ);
		}
	}
}

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ����
void displayInorder(treeNode* cur) {
	if (cur) {
		displayInorder(cur->left);
		printf("%c_", cur->key);
		displayInorder(cur->right);
	}
}


void menu() {
	printf("\n*---------------------------*");
	printf("\n\t1 : Ʈ�� ���");
	printf("\n\t2 : ���� ����");
	printf("\n\t3 : ���� ����");
	printf("\n\t4 : ���� �˻�");
	printf("\n\t5 : ����");
	printf("\n*---------------------------*");
	printf("\n�޴��Է� >> ");
}


int main() {
	treeNode* foundedNode = NULL;
	char choice, key;

	// [�׸� 7-38]�� ���� �ʱ� ���� Ž�� Ʈ���� �����ϰ�
	// ��� G�� ��Ʈ ��� ������ root�� ����
	insertNode('G');
	insertNode('I');
	insertNode('H');
	insertNode('C');
	insertNode('B');
	insertNode('M');
	insertNode('N');
	insertNode('A');
	insertNode('J');
	insertNode('E');
	insertNode('D');
	insertNode('Q');

	while (1) {
		menu();
		fflush(stdout);
		scanf_s(" %c", &choice, sizeof(choice));

		switch (choice - '0') {
		case 1:
			//			printf("\t[���� Ʈ�� ���]  ");
			displayInorder(root);  printf("\n");
			break;

		case 2:
			printf("������ ���ڸ� �Է��ϼ��� : ");
			fflush(stdout);
			scanf_s(" %c", &key, sizeof(key));
			insertNode(key);
			displayInorder(root);  printf("\n");
			break;

		case 3:
			printf("������ ���ڸ� �Է��ϼ��� : ");
			fflush(stdout);
			scanf_s(" %c", &key, sizeof(key));
			deleteNode(key);
			displayInorder(root);  printf("\n");
			break;

		case 4:
			printf("ã�� ���ڸ� �Է��ϼ��� : ");
			fflush(stdout);
			scanf_s(" %c", &key, sizeof(key));
			foundedNode = search(key);
			if (foundedNode != NULL)
				printf("\n %c�� ã�ҽ��ϴ�! \n", foundedNode->key);
			else
				printf("\n ���ڸ� ã�� ���߽��ϴ�. \n");
			break;

		case 5:
			return 0;

		default:
			printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n");
			break;
		}
	}


	return 0;
}
