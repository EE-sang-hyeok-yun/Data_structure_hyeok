#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b) // int 형 포인터로 형 변환 후 역참조 한다
        return 1; // a 가 더 크면 값을 바꾼다.
    else if (*(int*)a < *(int*)b) // int 형 포인터로 형 변환 후 역참조 한다
        return -1; // a 가 더 작으면 유지한다.
    else
        return 0;
}

int main(void)
{
    int arr[] = { 40, 10, 100, 90, 20, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // 배열의 크기 계산

    void* ptrarr = arr;
    // 배열의 주소

    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    // 배열의 값 출력

    // qsort 호출
    qsort(ptrarr, n, sizeof(int), comp);
    // 배열의 주소
    // 값의 개수
    // 자료형의 크기
    // 함수 포인터


    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    // 정렬된 배열의 값 출력

    return 0;
}