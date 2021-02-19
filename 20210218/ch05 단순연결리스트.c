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
	//1 new 노드 생성(구조체+동적할당+포인터)-> Null체크 
	listNode *new = (listNode*)malloc(sizeof(listNode));
	if (new == NULL)
	{
		printf("동적할당 실패!\n");
		exit(1);
	}
	strcpy_s(new->data, sizeof(new->data), x);	//2 데이터 부분 값삽입
	new->link = NULL;							//3 링크 Null 삽입

	//4-1 pre 가 NULL 인 경우
	if (pre == NULL)	//연결하려고 하는 노드가 존재하지 않는 상태
	{
		printf("노드 탐색 실패.\n");
		free(new);
	}

	//4-2 pre 가 NULL 이 아닌경우(pre->link 값을 new->link 에저장 // pre->link에 new노드주소를 저장)
	else				//노드탐색 완료상태, pre뒤에 new노드를 연결함
	{
		new->link = pre->link;
		pre->link = new;
	}
}


// 함수 내에서 직접검색 후에 연결하기
void insertMiddleNode2(char *search, char *x)
{
	listNode *pre = searchNode(search);
	
	listNode *new = (listNode *)malloc(sizeof(listNode));
	if (new == NULL)
		exit(1);

	strcpy_s(new->data, sizeof(new->data), x);
	new->link = NULL;
	
	
	if (pre == NULL)
	{
		printf("노드 탐색 실패.\n");	//pre 노드 미존재,, 연결불가
		free(new);
	}
	else									//뒤에 연결
	{
		new->link = pre->link;
		pre->link = new;
	}
}



// 리스트에서 노드 p를 삭제하는 연산
void deleteNode(listNode* p) {
	//1 삭제전 해당 데이터 존재유무 조회
	if (p == NULL)
	{
		printf("삭제할 노드가 없습니다.\n");
		return;
	}

	//2 삭제 전노드의 위치 탐색 
	listNode *pre = L;
	if (pre == NULL)
	{
		printf("현재 저장된 노드가 없습니다\n");
		return;
	}

	if (pre == p)	//3 삭제 위치가 처음인경우
	{
		L = p->link;
		free(p);
	}

	else			//4 삭제 위치가 처음이아닌경우(마지막이거나 중간노드인경우)
	{
		while (pre != NULL)
		{
			if (pre->link == p)
				break;
			pre = pre->link;
		}
			//1) 노드의 끝에 다다른 경우(pre안에 NULL) - 생략 가능(앞에서 예외를 다 처리했음!!)
			//2) pre->link == p 같아지는 경우.. 전노드를 찾음!!
		
		pre->link = p->link;
		free(p);
		//4-1 삭제 위치가 마지막인경우(삭제 이전노드의 link에 NULL 대입 후 삭제노드 free)
		//4-2 삭제 위치가 중간노드인경우(삭제 이전노드의 link에 삭제할 노드의 link값 저장 후 삭제노드 free)
	}
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
	printf("\n----------(4) 리스트에서 [금] 노드 탐색하기!----------\n");
	p = searchNode("금");
	if (p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("[%s]를 찾았습니다.\n", p->data);

	printf("\n----------(3) 리스트에서 [목] 노드 탐색하기! ----------\n");
	p = searchNode("목");
	if (p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("[%s]를 찾았습니다.\n", p->data);


	// 데이터 삽입 (중간 노드)
	printf("\n----------(5) 리스트의 [목] 뒤에 [금] 노드 삽입하기!----------\n");
	insertMiddleNode(p, "금");
	printList();


	// 데이터 삽입2 (중간 노드) - 찾을 값 직접 입력
	printf("\n----------(6) 리스트에서 검색한 노드 뒤에 새노드 연결하기!----------\n");
	char search[4];
	char x[4];
	
	printf("입력(검색 요일) : ");
	scanf_s("%s", search, sizeof(search));
	
	printf("입력(추가 데이터) : ");
	scanf_s("%s", x, sizeof(x));

	insertMiddleNode2(search, x);
	printList();


	// 데이터 삭제
	printf("\n----------(7) 리스트에서 [일]노드 삭제하기!----------\n");
	p = searchNode("일");		// 삭제할 노드 위치 p를 찾음
	deleteNode(p);				// 포인터 p 노드 삭제
	printList();

	printf("\n----------(8) 리스트에서 [월]노드 삭제하기!----------\n");
	p = searchNode("월");
	deleteNode(p);
	printList();

	printf("\n----------(9) 리스트에서 [목]노드 삭제하기!----------\n");
	p = searchNode("목");
	deleteNode(p);
	printList();





	freeLinkedList();               //리스트 메모리 해제
	return 0;
}