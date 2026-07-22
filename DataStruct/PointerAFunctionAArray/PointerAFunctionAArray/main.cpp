#include <stdio.h>
#include <string.h>

//선언: 있는것을 알리는 것
//정의: 실제로 구현하는 것
//초기화: 선언과 동시에 값을 넣는 것
//함수: 특정 작업을 수행하는 코드 블럭
//식별자: 무엇인가 구별하기위해 정해진 것, 변수나 함수의 이름.

void OperatorTestMain()
{
	int nDataA = 10;
	int nDataB = nDataA;
	printf("nDataA: %d, nDataB: %d\n", nDataA, nDataB);

	nDataB = nDataA++;
	printf("nDataA: %d, nDataB: %d\n", nDataA, nDataB);

	nDataB = --nDataA;
	printf("nDataA: %d, nDataB: %d\n", nDataA, nDataB);
}


//포인터값을 저장하고, 변수에서 할 수 있는 모든 연산을 구현하고, 어떤 값이 나오는지 확인하여라.
//포인터: 변수의 주소값을 저장하는 변수. 예) int* pData = &nData;
//변수에 할 수 있는 연산: &: 변수의 주소값을 가져오는 연산자, *: 포인터가 가르키는 변수의 값을 가져오는 연산자
//데이터: 포인터변수 pData, 포인터가 가르킬 변수 nData
//알고리즘: nData에 값을 넣고, nData의 주소값을 pData에 넣는다.
//nData, pData에서 할 수 있는 연산을 모두 출력하라.
void PointerTestMain()
{
	int nData = 10;
	int* pData = &nData;

	printf("nData[%d, %p]\n", nData, &nData);
	printf("pData[%p, %d]\n", pData, *pData);

	float fData = 3.14f;
	float* pFData = &fData;

	printf("fData[%f, %p]\n", fData, &fData);
	printf("pData[%p, %f]\n", pFData, *pFData);
}

void SwapByValue(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SwapByPointer(int* pA, int* pB)
{
	int temp = *pA;
	*pA = *pB;
	*pB = temp;
}

void SwapByReference(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void FunctionAndPointerMain()
{
	int nDataA = 10;
	int nDataB = 20;
	printf("Origin[%p]%d<->[%p]%d\n", &nDataA, nDataA, &nDataB, nDataB);

	SwapByValue(nDataA, nDataB);
	printf("SwapByValue[%p]%d<->[%p]%d\n", &nDataA, nDataA, &nDataB, nDataB);

	SwapByPointer(&nDataA, &nDataB);
	printf("SwapByPointer[%p]%d<->[%p]%d\n", &nDataA, nDataA, &nDataB, nDataB);

	SwapByReference(nDataA, nDataB);
	printf("SwapByReference[%p]%d<->[%p]%d\n", &nDataA, nDataA, &nDataB, nDataB);
}

void ArrayMain()
{
	const int nSize = 3;
	int arrA[nSize];
	int arrSize = sizeof(arrA) / sizeof(arrA[0]);

	for (int i = 0; i < nSize; ++i)
	{
		arrA[i] = 10 * i;
	}
	printf("arrA[%p]:%p\n", &arrA, arrA);

	for (int i = 0; i < nSize; ++i)
	{
		printf("[%p/%d]%d, ", &arrA[i], i, arrA[i]);
	}
	printf("\n");

	for (int i = 0; i < nSize; ++i)
	{
		printf("[%p/%d]%d, ", (arrA + i), i, *(arrA + i));
	}
	printf("\n");

	int* pA = arrA;
	printf("Pointer[%p]:%d\n", pA, *pA);
	for (int i = 0; i < nSize; ++i)
	{
		printf("[%p/%d]%d, ", pA, i, *pA);
		pA++;
	}

	int arrACopy[nSize];
	for (int i = 0; i < nSize; ++i)
	{
		arrACopy[i] = arrA[i];
	}
	memcpy(arrACopy, arrA, nSize);
}

int main()
{
	//함수의호출: 함수를 부른다. (실제로는 간다는 개념에 가까움)
	OperatorTestMain();
	printf("\n");
	PointerTestMain();
	printf("\n");
	FunctionAndPointerMain();
	printf("\n");
	ArrayMain();
	printf("\n");

	return 0;
}

// 배열의 크기를 지정할때 컴파일러는 크기를 알아야 할당이 가능하기 때문에, 상수만 사용이 가능하다.
// 포인터연산: 포인터의 값을 증가시키는 연산. 변수의 크기만큼 주소값이 증가한다.