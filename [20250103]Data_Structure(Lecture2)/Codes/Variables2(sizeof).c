#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
	printf("Size of int: %lu bytes\n", sizeof(int));
	// int 자료형의 크기
	int a = 0;
	printf("Size of variable a: %lu bytes\n", sizeof(a));
	// 변수 a의 크기
	
	return 0;
}