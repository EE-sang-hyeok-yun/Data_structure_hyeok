#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
    int a[5] = { 10,20,30,40,50 };
    int* ptr = a;
    // a를 int 형 포인터에 대입

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *ptr++);
        // 차례로 주소를 증가하면서 역참조한다
    };
    return 0;
}