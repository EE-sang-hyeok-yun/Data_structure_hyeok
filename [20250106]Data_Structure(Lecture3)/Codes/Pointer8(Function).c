#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) 
{
    // 인수로 주소를 받음
    int temp = *a;
    // 주소를 통해 역참조하여 값 대입
    *a = *b;
    *b = temp;
    // 값을 서로 바꿈
    // 주소를 통해 값에 접근했으므로 
    // 실제로 main 함수의 값을 변경
    return;
}

int main(void) 
{
    int x = 5, y = 10;
    printf("x: %d, y: %d\n", x, y);
    // 변경 전 출력
    swap(&x, &y);
    // 변수의 주소를 전달
    printf("x: %d, y: %d\n", x, y);
    // 변경된 값 출력
    return 0;
}