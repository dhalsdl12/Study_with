#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
	char key;				// 데이터 필드
	struct treeNode* left;	// 왼쪽 서브 트리 링크 필드
	struct treeNode* right;	// 오른쪽 서브 트리 링크 필드
} treeNode;

treeNode* root = NULL;


//탐색 함수
treeNode* search(char x)
{

	// 1 시작노드 주소 *p 로 받음
	treeNode *p = root;
	if (p == NULL)
		return NULL;

	// 2 p가 NULL일때까지 계속 반복
	while (p != NULL)
	{
		// 3 p->key와 x 를 비교 
		// 3-1 p->key == x		-> 노드주소 return
		// 3-1 p->key > x		-> p->left로 이동
		// 3-1 p->key < x		-> p->right로 이동
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

	//동일한 키가 없다
	//printf("해당 키가 존재하지 않습니다.\n"); -> 메인함수에서 출력함
	return NULL;
}


// 노드 삽입 함수 
void insertNode(char x) {
	//0. 중복키 존재 여부
	if (search(x) != NULL)
		return;

	//1. 노드생성
	//2. 데이터값 넣기
	//3. 링크 NULL 초기화
	treeNode *new = (treeNode*)malloc(sizeof(treeNode));
	if (new == NULL)
	{
		printf("동적할당 실패!\n");
		exit(1);
	}
	new->key = x;
	new->left = NULL;
	new->right = NULL;


	//4. 노드x
	if (root == NULL)
	{
		root = new;
	}

	//5. 노드 1이상 존재
	else
	{
		treeNode *cur = root;	//삽입위치 탐색
		treeNode *par = NULL;	//삽입위치의 부모노드 탐색
		
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

		//par의 위치 탐색
		//cur == NULL
		if (par->key > x)
			par->left = new;
		else
			par->right = new;
	}
}


// 노드 삭제 함수 
//(자식x, 자식1, 자식2) -> 상당히 어려움
void mydeleteNode(char key)
{
	//00. 노드가 하나도 없는 경우
	if (root == NULL)
	{
		printf("노드가 없습니다.\n");
		return;
	}

	//01. 조회(노드 없으면 return, 있으면 02진행)
	if (search(key) == NULL)
	{
		printf("삭제할 노드가 없습니다.\n");
		return;
	}

	//02. 삭제노드주소(Node *cur)와 삭제 부모노드주소(Node *par) 탐색
	treeNode *cur = search(key);
	treeNode *par = root;
	while (par->left != cur && par->right != cur)
	{
		if (par->key > key)
			par = par->left;
		else
			par = par->right;
	}
	printf("삭제노드 확인 : %c\n", cur->key);
	printf("삭제노드 부모 확인 : %c\n", par->key);
	//03. 삭제노드의 자식노드의 수를 화깅ㄴ
	//03-1. 삭제노드의 자식노드 x
	//03-2. 삭제노드의 자식노드 1
	//03-3. 삭제노드의 자식노드 2
}
void deleteNode(char key)
{
	//00. 노드가 하나도 없는 경우
	if (root == NULL)
	{
		printf("노드가 없습니다.\n");
		return;
	}

	//01. 조회(노드 없으면 return, 있으면 02진행)
	if (search(key) == NULL)
	{
		printf("삭제할 노드가 없습니다.\n");
		return;
	}

	//02. 삭제노드주소(Node *cur)와 삭제 부모노드주소(Node *par) 탐색
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
	//cur위치 탐색완료
	//par위치 탐색완료(par가 NULL로 저장되어있다면 삭제 노드는 root 노드가 된다)

	//03. 삭제노드의 자식노드의 수를 확인
	if (cur->left == NULL && cur->right == NULL)		//03-1. 삭제노드의 자식노드 x
	{
		if (par == NULL)	//삭제 노드가 rootNode인 경우
		{
			root = NULL;	//root 포인터에 NULL(노드 연결이 없음)
			free(cur);		//노드제거
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
	else if(cur->left == NULL || cur->right == NULL)	//03-2. 삭제노드의 자식노드 1
	{
		if (par == NULL)	//삭제 노드가 root 노드인 경우
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
		else				//삭제 노드가 root노드가 아닌경우
		{
			//자식노드 주소를 담을 포인터
			treeNode *son = NULL;
			//son의 위치를 확인해서 저장
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
	else if (cur->left != NULL && cur->right == NULL)	//03-3. 삭제노드의 자식노드 2
	{
		if (par == NULL)	//삭제노드가 rootNode인 경우
		{

		}
		else				//삭제노드가 rootNode가 아닌경우
		{
			treeNode *succ_par = cur;
			treeNode *succ = cur->left;

			while (succ->right != NULL)
			{
				succ_par = succ;
				succ = succ->right;
			}
			//succ의 위치 succ->right==NULL 노드를 가리킨다
			//succ_par 위치 succ의 상위노드 가리킨다.

			//succ_par->left == succ ==> 위 반복작업을 한번도 수행하지 않은 상태
			//succ_par->left != succ ==> 위 반복작업을 수행해서 오른쪽 끝노드를 탐색한 상태

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

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode* cur) {
	if (cur) {
		displayInorder(cur->left);
		printf("%c_", cur->key);
		displayInorder(cur->right);
	}
}


void menu() {
	printf("\n*---------------------------*");
	printf("\n\t1 : 트리 출력");
	printf("\n\t2 : 문자 삽입");
	printf("\n\t3 : 문자 삭제");
	printf("\n\t4 : 문자 검색");
	printf("\n\t5 : 종료");
	printf("\n*---------------------------*");
	printf("\n메뉴입력 >> ");
}


int main() {
	treeNode* foundedNode = NULL;
	char choice, key;

	// [그림 7-38]과 같은 초기 이진 탐색 트리를 구성하고
	// 노드 G를 루트 노드 포인터 root로 지정
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
			//			printf("\t[이진 트리 출력]  ");
			displayInorder(root);  printf("\n");
			break;

		case 2:
			printf("삽입할 문자를 입력하세요 : ");
			fflush(stdout);
			scanf_s(" %c", &key, sizeof(key));
			insertNode(key);
			displayInorder(root);  printf("\n");
			break;

		case 3:
			printf("삭제할 문자를 입력하세요 : ");
			fflush(stdout);
			scanf_s(" %c", &key, sizeof(key));
			deleteNode(key);
			displayInorder(root);  printf("\n");
			break;

		case 4:
			printf("찾을 문자를 입력하세요 : ");
			fflush(stdout);
			scanf_s(" %c", &key, sizeof(key));
			foundedNode = search(key);
			if (foundedNode != NULL)
				printf("\n %c를 찾았습니다! \n", foundedNode->key);
			else
				printf("\n 문자를 찾지 못했습니다. \n");
			break;

		case 5:
			return 0;

		default:
			printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
			break;
		}
	}


	return 0;
}
