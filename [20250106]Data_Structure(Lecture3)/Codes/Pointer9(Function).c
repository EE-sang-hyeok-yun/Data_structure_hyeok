#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int a, int b) 
{
    // 인수로 값을 받음
    int temp = a;
    a = b;
    b = temp;
    // 값을 서로 바꿈
    // 함수 내부에서 변수의 값들이 바뀜
    // 소멸되는 변수의 값이므로 반환하지 않으면 의미 없는 작동이다
    return;
}

int main(void) 
{
    int x = 5, y = 10;
    printf("x: %d, y: %d\n", x, y);
    // 변경 전 출력
    swap(x, y);
    // 변수의 값을 전달
    printf("x: %d, y: %d\n", x, y);
    // 변경되지 않음
    return 0;
}