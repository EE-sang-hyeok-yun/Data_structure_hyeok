#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Point
{
    int x;
    int y;
    int z;
};

int main(void)
{
    struct Point P = { 10,20,30 };
    struct Point* ptrP = &P;

    printf("%p\n", ptrP);
    // 포인터가 위치하는 주소
    printf("%p %p %p\n", &(P.x), &(P.y), &(P.z));
    // 각 멤버의 주소

    printf("%ld\n", (unsigned long)ptrP);
    // 포인터가 위치하는 주소
    // 10진수 표현
    printf("%ld %ld %ld\n", (unsigned long)&(P.x), (unsigned long)&(P.y), (unsigned long)&(P.z));
    // 각 멤버의 주소
    // 10진수 표현
    // 4 Byte 씩 증가

    return 0;
}