#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    float small = 1.0e-45; 
    // 매우 작은 값
    printf("Small value: %e\n", small);
    printf("Underflow: %e\n", small / (float)10);
    // 언더플로우 발생
    return 0;
}