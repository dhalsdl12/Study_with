#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

// 리스트의 시작
listNode* L;	//전역변수


// 연결 리스트의 전체 메모리를 해제하는 연산
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


// 연결 리스트를 순서대로 출력하는 연산
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


// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(char* x) {

	//1 new 노드 생성(구조체+동적할당+포인터)-> Null체크 
	listNode *new = (listNode*)malloc(sizeof(listNode));
	if (new == NULL)
	{
		printf("동적할당 실패!\n");
		exit(1);
	}
	//2 데이터 부분 값삽입
	strcpy_s(new->data, sizeof(new->data), x);
	//3 링크 Null 삽입
	new->link = NULL;

	//4-1 노드가 하나이상 있는경우 -> 처음위치에 연결
	if (L != NULL)
	{
		new->link = L;
		L = new;
	}

	//4-2 노드가 하나도 없는경우 -> 전역L포인터에 노드 바로연결 
	else
	{
		L = new;
	}

}


// 마지막 노드로 삽입하는 연산
void insertLastNode(char* x) {
	//1 new 노드 생성(구조체+동적할당+포인터)-> Null체크 
	listNode *new = (listNode*)malloc(sizeof(listNode));
	if (new == NULL)
	{
		printf("동적할당 실패!\n");
		exit(1);
	}
	//2 데이터 부분 값삽입
	strcpy_s(new->data, sizeof(new->data), x);
	//3 링크 Null 삽입
	new->link = NULL;

	//4-1 노드가 하나이상 있는경우 -> 마지막 위치에 연결 코드 작성 
	if (L != NULL)
	{
		listNode *tmp = L;
		//5 tmp 포인터를 만들어서 각 노드를 순회(tmp=tmp->link)하면서 마지막위치(link가 NULL) 인지 확인
		while (tmp->link != NULL)
		{
			tmp = tmp->link;
		}
		//6 마지막위치에서 새노드를 연결
		tmp->link = new;
	}
	//4-2 노드가 하나도 없는경우 -> 전역L포인터에 노드 바로연결 
	else
	{
		L = new;
	}
}


// 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(char* x) {
	//1 탐색용 구조체 포인터(tmp) 생성
	//2 노드의 시작주소를 tmp포인터에 저장
	listNode *tmp = L;

	if (L == NULL)
		return NULL;

	//3 각노드를 순회(tmp=tmp->link)하면서 찾을 문자열과 일치하는 문자열 확인(strcmp(주소1,주소2))
	while (tmp != NULL)
	{
		//4-1 찾으면 해당 노드의 주소를 리턴 
		if (strcmp(tmp->data, x) == 0)	//데이터 일치
		{
			return tmp;
		}
		tmp = tmp->link;
	}
	//4-2 tmp==NULL(tmp가 전체노드를 순회) 이라면 NULL을 리턴
	return NULL;
}


listNode* ssearchNode(char* x) {
	listNode *tmp = L;

	//1) 노드가 하나도 없는 경우
	if (L == NULL)
		return NULL;

	//노드가 있을때
	while (tmp != NULL)
	{
		if (strcmp(tmp->data, x) == 0)	//데이터 일치
		{
			break;
		}
		tmp = tmp->link;
	}
	//2) 노드가 하나이상 있는 경우(동일한 데이터값의 주소가 tmp에 담겨서 break경우)
	//3) 노드의 마지막까지 이동한 경우(일치하는 데이터가 없다)
	return tmp;
}


// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(listNode* pre, char* x) {

}


// 리스트에서 노드 p를 삭제하는 연산
void deleteNode(listNode* p) {

}


int main() {
	listNode* p;
	L = NULL;               //공백 리스트 생성


	// 데이터 삽입(첫노드)
	printf("----------(1) 첫노드에 삽입 [월][수] ----------\n");
	insertFirstNode("수");
	insertFirstNode("월");
	printList();


	// 데이터 삽입(끝노드)
	printf("\n----------(2) 마지막 노드에 삽입 [목][토][일] ----------\n");
	insertLastNode("목");
	insertLastNode("토");
	insertLastNode("일");
	printList();


	// 데이터 탐색

//	printf("\n----------(4) 리스트에서 [금] 노드 탐색하기!----------\n");
//	char s[4];
//	scanf_s("%s", s, sizeof(s));
//	p = searchNode(s);
//	if (p == NULL)
//		printf("찾는 데이터가 없습니다.\n");
//	else
//		printf("[%s]를 찾았습니다.\n", p->data);
//
//	printf("\n----------(3) 리스트에서 [목] 노드 탐색하기! ----------\n");
//	p = searchNode("목");
//	if (p == NULL)
//		printf("찾는 데이터가 없습니다.\n");
//	else
//		printf("[%s]를 찾았습니다.\n", p->data);
	printf("\n----------(3) 리스트에서 노드 탐색하기!----------\n");
	for (int i = 0; i < 3; i++)
	{
		printf("노드 입력 : ");
		char s[4];
		scanf_s("%s", s, sizeof(s));
		p = searchNode(s);
		if (p == NULL)
			printf("[%s] 데이터가 없습니다.\n", s);
		else
			printf("[%s]를 찾았습니다.\n", p->data);
		printf("\n");
	}

	freeLinkedList();               //리스트 메모리 해제
	return 0;
}