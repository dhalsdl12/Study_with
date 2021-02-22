#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
}Node;

typedef struct CList
{
	Node* tail;		// 꼬리 위치 포인터
	int NodeCnt;	// 데이터 개수 확인
}List;


//초기화함수
void ListInit(List* plist)
{
	plist->tail = NULL;	// 꼬리포인터 초기화
	plist->NodeCnt = 0;	// 데이터 개수 초기화
}


//리스트 프린트 함수 
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
//마지막에 삽입
void LInsert(List* plist, int data)
{
	//1 노드생성
	Node* new = (Node*)malloc(sizeof(Node));
	if (new == NULL)
	{
		printf("동적할당 실패!\n");
		exit(1);
	}
	new->data = data;	//2 데이터 값넣기
	new->next = NULL;	//3 링크부 초기화

	//4-1 노드가 하나도 없을때
	if (plist->tail == NULL)
	{
		plist->tail = new;
		new->next = new;	 //plist->tail->next = new;
	}
	//4-2 노드가 하나이상 있을때
	else
	{
		new->next = plist->tail->next;
		plist->tail->next = new;
		plist->tail = new;
	}
	//5 데이터 개수 증가
	plist->NodeCnt++;
}


//처음에 삽입
void LInsertFront(List* plist, int data)
{
	//1. 노드생성(NULL 체크) + 데이터값넣기 + 링크NULL초기화
	Node* new = (Node*)malloc(sizeof(Node));
	if (new == NULL)
	{
		printf("동적할당 실패!\n");
		exit(1);
	}
	new->data = data;
	new->next = NULL;

	//2-1. 노드가 하나도 없을때
	if (plist->tail == NULL)
	{
		plist->tail = new;
		new->next = new;	 //plist->tail->next = new;
	}
	//2-2 노드가 하나이상 있을때
	else
	{
		new->next = plist->tail->next;
		plist->tail->next = new;
	}
	plist->NodeCnt++;
}


//조회 함수
Node* SearchNode(List* plist, int target)
{
	//NodeCnt를 이용해서(반복문 사용) 
	//target과 일치하는 데이터를 가지는 노드의 주소를 반환(리턴)
	//target과 일치하는 데이터가 없으면 NULL를 반호나(리턴)
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


//삭제 함수
int LRemove(List* plist, int target)
{
	//1. 조회
	//2. 마지막인 경우
	//3. 마지막이 아닌 경우
	Node *tmp = SearchNode(plist, target);
	if (tmp == NULL)
	{
		printf("삭제할 노드가 없습니다.\n");
		return;
	}
	Node* pre = plist->tail->next;

	if (pre == NULL)
	{
		printf("저장된 노드가 없습니다.\n");
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
	// 원형 연결 리스트의 생성 및 초기화 
	//-----------------------------------
	List list;
	int data, i, nodeNum;
	ListInit(&list);
	int num;


	//-----------------------------------
	// 끝노드에 연결
	//-----------------------------------
	printf("\n--------(1) 끝 노드에 연결 ---------\n");
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	PrintList(&list);


	//-----------------------------------
	// 첫노드에 연결 /////// 
	//-----------------------------------
	printf("\n--------(2) 첫 노드에 연결 ---------\n");
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	PrintList(&list);


	//-----------------------------------
	//저장된 데이터 조회///////
	//-----------------------------------
	printf("\n--------(3) 데이터 조회 ---------\n");
	printf("값 입력[조회] : ");
	scanf_s("%d", &num);
	Node* cur = SearchNode(&list, num);
	if (cur == NULL)
		printf("입력한 값과 일치하는 데이터는 없습니다\n");
	else
		printf("입력한 값 %d 가 존재합니다\n", cur->data);


	//-----------------------------------
	//삭제///////
	//-----------------------------------
	printf("값 입력[삭제] : ");
	scanf_s("%d", &num);
	LRemove(&list, num);
	PrintList(&list);


	return 0;
}