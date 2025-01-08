#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    int* ptr = arr;  
    // 배열의 첫 번째 요소를 가리킴
    printf("First ptr: %p Value: %d\n", ptr, *ptr);

    ptr++;  
    // 포인터를 한 칸 증가시킴
    // 4 Byte 증가시킴
    // 두 번째 요소를 가리킴
    printf("ptr++    : %p Value: %d\n", ptr, *ptr);

    ptr += 2;  
    // 포인터를 두 칸 이동
    // 8 Byte 증가시킴
    // 네 번째 요소를 가리킴
    printf("ptr += 2 : %p Value: %d\n\n", ptr, *ptr);


    int* ptr1 = &arr[3];  // 배열의 네 번째 요소를 가리킴
    int* ptr2 = &arr[0];  // 배열의 첫 번째 요소를 가리킴

    printf("First ptr1: %p Value1: %d\n", ptr1, *ptr1);
    printf("First ptr2: %p Value2: %d\n", ptr2, *ptr2);

    ptr1--;  
    // 포인터를 한 칸 뒤로 이동
    // 4 Byte 감소시킴
    // 두 번째 요소를 가리킴
    printf("ptr1--    : %p Value1: %d\n", ptr1, *ptr1);

    int diff = ptr1 - ptr2;  // 두 포인터 간의 거리 계산
    printf("ptr1-ptr2 : %d (Distance, int (%d * 4 Byte))\n", diff, diff);

    return 0;
}