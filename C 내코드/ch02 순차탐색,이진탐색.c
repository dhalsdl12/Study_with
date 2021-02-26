//--------------------------------------------
//순차 탐색
//--------------------------------------------

/*
#include <stdio.h>

//순차탐색 함수
int LSearch(int *ar, int len, int target)	//ar : main함수 arr을 가리키는 포인터
{											//len : 배열의 길이
											//target : 찾을 데이터

	//배열의 0번째에서 마지막 요소까지 차례로 이동하면서
	//target과 일치하는 데이터가 있는지 확인 후 존재한다면
	//해당요소의 idx값을 return합니다.
	//target과 일치하는 데이터가 없을땐 -1을 return 합니다.
	for (int i = 0; i < len; i++)
	{
		if (ar[i] == target)	//ar[i]번째 요소 값이  target과 일치하다면
			return i;			//값이 있는 idx를 리턴
	}
	return -1; //반복문을 벗어나게된다면 (배열 요소에 target이 없음) -1리턴
}

int main()
{
	int arr[] = { 3,5,2,4,9 };
	int idx;
	int num = 0;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), num);

	for(int i = 0; i < 5; i++)
	{
		printf("숫자 입력 : ");
		scanf_s("%d", &num);
		idx = LSearch(arr, sizeof(arr) / sizeof(int), num);
		if (idx == -1)
			printf("해당 숫자는 존재하지 않습니다.\n");
		else
			printf("타겟 저장 idx : %d번째\n", idx);
		printf("\n");
	}
	return 0;
}
*/



//--------------------------------------------
//이진 탐색
//--------------------------------------------

/*
#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int First = 0;
	int Last = len - 1;
	int mid = 0;
	//탐색에 사용되는 반복문
	while (First <= Last)
	{
		mid = (First + Last) / 2;		//<--코드입력 (hint : Mid Index 저장)

		if (target == ar[mid])			//배열의 mid번째 요소값이 target과 일치한다면
			return mid;					//해당 위치 idx를 return 

		else if (ar[mid] > target)		//배열의 mid번째 요소값이 target보다 크다면 
			Last = mid - 1;				//Last를 mid보다 1 작은 위치로 idx값 지정

		else if (ar[mid] < target)		//배열의 mid번째 요소값이 target보다 작다면 
			First = mid + 1;			//First를 mid보다 1 큰 위치로 idx값 지정
	}

	return -1;	//반복문을 벗어난 리턴은 First>Last 보다 커진경우
				//target이 배열에 없으므로 -1을 리턴 

}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;
	int num;

	for (int i = 0; i < 5; i++)
	{
		printf("숫자 입력 : ");
		scanf_s("%d", &num);

		idx = BSearch(arr, sizeof(arr) / sizeof(int), num);
		if (idx == -1)
			printf("탐색 실패 \n");
		else
			printf("타겟 저장 인덱스: %d \n", idx); 
		printf("\n");
	}

	return 0;
}
*/