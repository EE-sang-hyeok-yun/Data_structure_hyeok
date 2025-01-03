#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number = 100; 
	// 정수형 변수 num 선언
	// 100 으로 초기화
	int* numAddress = &number; 
	// 정수형 포인터 변수 numAddress 선언
	// number의 주소로 초기화

	printf("%d\n", number);
	printf("%p\n", numAddress);
	return 0;
}