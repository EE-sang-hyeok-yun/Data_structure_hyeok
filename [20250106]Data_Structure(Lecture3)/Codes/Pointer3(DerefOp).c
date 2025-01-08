#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
    int x = 10;
    // 변수 x 선언
    // 10 대입
    int* ptrx = &x;
    // 포인터 변수 선언
    // x의 주소 참조 후 대입

    printf("Address: %p\n", ptrx);
    // x의 주소 출력
    printf("Value: %d\n", *ptrx);
    // 포인터 변수를 역참조
    // int* 형 변수이므로 주소를 통해 값을 역참조하여 int 형으로 읽음

    *ptrx = 20;
    // 포인터 변수를 역참조하여 값을 주소에 대입
    // int 형으로 값을 대입
    printf("Updated Value: %d\n", x);
    // 변경된 값 출력

    return 0;
}