#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
    int x = 42;
    int* ptrx = &x;
    printf("Address of x (%%p): %p\n", ptrx);
    // 포인터 형식 출력
    printf("Address of x (%%llX): %llX\n", (unsigned long long)ptrx);
    // 16진수 출력
    printf("Address of x (%%llu): %llu\n", (unsigned long long)ptrx);
    // 무부호 정수 출력
    return 0;
}