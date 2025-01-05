#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int max = INT_MAX; 
    // 정수 최대값: 2147483647
    printf("Max: %d\n", max);
    printf("Overflow: %d\n", max + 1); 
    // 오버플로우 발생

    unsigned int unsigned_max = UINT_MAX; 
    // 부호 없는 정수 최대값: 4294967295
    printf("Max Unsigned: %u\n", unsigned_max);
    printf("Overflow Unsigned: %u\n", unsigned_max + 1); 
    // 오버플로우 발생

    return 0;
}