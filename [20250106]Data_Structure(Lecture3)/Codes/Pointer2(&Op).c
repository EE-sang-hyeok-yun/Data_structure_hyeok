#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
    int A = 10;
    int B = 20;

    int* ptrA = &A;
    // ptrA에 A의 주소 대입
    int* ptrB = &B;
    // ptrB에 B의 주소 대입

    printf("Address: %p, Value: %d\n", ptrA, A);
    printf("Address: %p, Value: %d\n", ptrB, B);

    return 0;
}