#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

int main(void)
{
    int arr[] = { 40, 10, 100, 90, 20, 25 };
    int n = sizeof(arr) / sizeof(int);

    void* ptrarr = arr;
    int (*func)(const void* a, const void* b) = comp;
    // 함수의 주소를 대입

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    qsort(ptrarr, n, sizeof(int), func);
    // 함수의 주소를 전달

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    // 정렬된 배열의 값 출력

    return 0;
}