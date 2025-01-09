#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void find_min_max(int* arr, int n, int* min, int* max) 
{
    *min = *arr;
    *max = *arr;

    for (int i = 1; i < n; i++) 
    {
        if (arr[i] < *min)
            *min = *(arr + i);
        if (arr[i] > *max) 
            *max = *(arr + i);
    }
    // min, max 값을 수정해가면서 값을 찾는다.
    return;
}

int main(void) 
{
    int arr[5] = { 10, 20, 5, 40, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    find_min_max(arr, n, &min, &max);
    printf("%d %d", min, max);

    return 0;
}