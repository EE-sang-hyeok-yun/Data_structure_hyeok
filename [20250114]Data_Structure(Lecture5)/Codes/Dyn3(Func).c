#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int* ptr = (int*)malloc(3 * sizeof(int)); 
    // 초기 메모리 할당

    if (ptr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }// 예외 처리

    for (int i = 0; i < 3; i++) 
    {
        ptr[i] = i + 1;
    }// 메모리 초기화

    ptr = (int*)realloc(ptr, 5 * sizeof(int)); 
    // 메모리 크기 재조정

    if (ptr == NULL) 
    {
        printf("Memory reallocation failed!\n");
        return 1;
    }// 예외 처리

    for (int i = 3; i < 5; i++) 
    {
        ptr[i] = i + 1; 
    }// 새로운 메모리 공간 초기화

    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", ptr[i]);
    }// 출력

    free(ptr); // 메모리 해제
    return 0;
}