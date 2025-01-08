#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
    int x = 10;
    void* ptr = &x;  
    // void* 로 저장
    printf("%d\n", *(int*)ptr);  
    // int 형으로 변환해야 한다

    return 0;
}