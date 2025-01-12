#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
    int a = 10;
    int b = 20;
    int c = 30;

    int* arr[3] = { 0 };

    // 포인터 배열 초기화
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    // 출력
    for (int i = 0; i < 3; i++) 
    {
        printf("arr[%d] = %p\n", i, arr[i]);
        printf("*(arr + %d) = %p\n", i, *(arr + i));
        printf("*arr[%d] = %d\n", i, *arr[i]);
        printf("**(arr + %d) = %d\n\n", i, **(arr + i));
    }

    return 0;
}