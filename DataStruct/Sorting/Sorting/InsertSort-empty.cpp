#include <stdio.h>

void InsertSort()
{
	int arrData[] = {8,1,7,4,2,3,9,5,6};

	//-------------------------------
	//배열을 정렬되도록 로직을 짜기
	//
	//-------------------------------
	for (int i = 0; i < 8; ++i)
	{
		int min = arrData[i];
		int minIdx = i;
		for (int j = i + 1; j < 9; ++j)
		{
			if (arrData[j] < min)
			{
				min = arrData[j];
				minIdx = j;
			}
		}

		if (minIdx == i) continue;
		else
		{
			int nTemp = arrData[i];
			arrData[i] = arrData[minIdx];
			arrData[minIdx] = nTemp;
		}
	}

	//다음출력에서 1~9까지 순서대로 정렬되도록 만들기
	printf("Data:");
	for (int i = 0; i < 9; i++)
		printf("%d,", arrData[i]);
	printf("\n");
}

void main()
{
	InsertSort();
}