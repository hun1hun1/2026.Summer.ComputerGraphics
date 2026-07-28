#include <stdio.h>

void InsertSort()
{
	int arrData[] = {8,1,7,4,2,3,9,5,6};

	//-------------------------------
	//배열을 정렬되도록 로직을 짜기
	//
	//-------------------------------

	//다음출력에서 1~9까지 순서대로 정렬되도록 만들기
	printf("Data:");
	for (int i = 0; i < 9; i++)
		printf("%d,");
	printf("\n");
}

void main()
{
	InsertSort();
}