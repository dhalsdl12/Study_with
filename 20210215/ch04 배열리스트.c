#include <stdio.h>
#include <string.h>

//마지막 길이 반환 함수
int Endlen(int* arr)
{
	int len = 0, i = 0;
	while (arr[i] != '\n')
		i++;
	return i;
}
//데이터 출력 함수
void Output(int* arr)
{
	int len = Endlen(arr);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

}

//데이터 삽입 함수
void Insert(int * arr, int data)
{
	//1. 저장공간이 있는지 여부 (배열의 마지막 idx가 NULL인지 확인)
	//2. 저장할 위치 idx를 탐색(Endlen()함수를 이용해서 idx를 확인)
	//3. 해당 idx요소에 전달된 data값을 저장

	int len = (sizeof(arr) / sizeof(int)) - 1; //배열의 마지막 idx저장
	if (arr[len] == '\0') //여유가 있는 상태
	{
		int idx = Endlen(arr);
		arr[idx] = data;
	}
	else //꽉찬 상태
	{
		printf("저장공간 부족!, 삽입불가!\n");
	}
}


//데이터 조회 함수
int Search(int * arr, int target)
{
	return 0;
}

//데이터 중복 조회 함수
void DSearch(int * arr, int target)
{

}
//데이터 삭제 함수
int Remove(int * arr, int target)
{
	return 0;
}

void main() {

	//데이터 저장 배열 정의
	int Array[100] = { 0 };
	int n1 = 0;
	int rm = 0;

	//5개의 데이터 저장
	Insert(Array, 11); 	Insert(Array, 11);
	Insert(Array, 22); 	Insert(Array, 22);
	Insert(Array, 33);

	//저장된 데이터  출력
	Output(Array);

}
