#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
    int A = 10;
    int B = 20;

    printf("Address: %p, Value: %d\n", &A, A);
    // A의 주소를 참조 후 값을 출력
    printf("Address: %p, Value: %d\n", &B, B);
    // B의 주소를 참조 후 값을 출력
    
    return 0;
}