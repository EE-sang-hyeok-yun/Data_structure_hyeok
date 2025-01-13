#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printMessage()
{
    printf("Hello, Function Pointer!\n");
}

int main(void)
{
    void (*funcPtr)() = &printMessage;
    // 함수 포인터에 함수 주소 저장
    funcPtr();
    // 함수 호출
    return 0;
}