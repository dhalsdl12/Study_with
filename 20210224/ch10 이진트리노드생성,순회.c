#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {	// ���� �ڷᱸ���� �����ϱ� ���� Ʈ���� ��� ����
	char data;
	struct treeNode* left;  // ���� ���� Ʈ���� ���� ��ũ �ʵ�
	struct treeNode* right; // ������ ���� Ʈ���� ���� ��ũ �ʵ�
} TreeNode;

TreeNode* makeRootNode(char data, TreeNode* leftNode, TreeNode* rightNode) {
	//1. �� ��� ����
	//2. ������ ��
	//3. ��ũ�� �ʱ�ȭ(left = leftNode, right = rightNode)
	TreeNode *new = (TreeNode*)malloc(sizeof(TreeNode));
	if (new == NULL)
	{
		printf("�����Ҵ� ����!\n");
		exit(1);
	}

	new->data = data;

}


// ���� Ʈ���� ���� ���� ��ȸ ����
void preorder(TreeNode* root) {

}


// ���� Ʈ���� ���� ���� ��ȸ ����
void inorder(TreeNode* root) {
}


// ���� Ʈ���� ���� ���� ��ȸ ����
void postorder(TreeNode* root) {
}


int main()
{
	TreeNode* n7 = makeRootNode('D', NULL, NULL);
	TreeNode* n6 = makeRootNode('C', NULL, NULL);
	TreeNode* n5 = makeRootNode('B', NULL, NULL);
	TreeNode* n4 = makeRootNode('A', NULL, NULL);
	TreeNode* n3 = makeRootNode('/', n6, n7);
	TreeNode* n2 = makeRootNode('*', n4, n5);
	TreeNode* n1 = makeRootNode('-', n2, n3);


	printf("preorder : ");
	preorder(n1);
	printf("\n");
	printf("\ninorder : ");
	inorder(n1);
	printf("\n");
	printf("\npostorder : ");
	postorder(n1);
	printf("\n");

	return 0;

}