#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>

int main(void)
{
    float large = FLT_MAX; 
    // float 최대값
    printf("Max float: %e\n", large);
    printf("Overflow: %e\n", large * (float)2.0); 
    // 오버플로우 발생
    return 0;
}