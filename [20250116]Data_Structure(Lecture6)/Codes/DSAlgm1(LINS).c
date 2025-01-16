#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int LinSearch(int* arr, int n, int target) 
{
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}// n 번 자료 탐색 -> 시간 복잡도 O(n)

int main(void) 
{
    int arr[] = { 1,2,3,5,7,8,9,10,11,13,14,15,17,18 };
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("%2d ", i);
    printf("\n");

    int target = 13;
    printf("Target: %d\n", target);
    printf("Index: %d\n", LinSearch(arr, n, target));
    return 0;
}