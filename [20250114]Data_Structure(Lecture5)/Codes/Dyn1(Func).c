#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int n;
    scanf("%d", &n);

    int* ptr = (int*)malloc(n * sizeof(int)); 
    // 정수 n개 크기의 메모리 할당
    // (void*)형 반환
    // (int*)형으로 형 변환

    for (int i = 0; i < n; i++) 
        ptr[i] = i;
    // 초기화

    for (int i = 0; i < n; i++)
        printf("%d ", ptr[i]);
    // 출력

    free(ptr);
    // 메모리 해제

    return 0;
}