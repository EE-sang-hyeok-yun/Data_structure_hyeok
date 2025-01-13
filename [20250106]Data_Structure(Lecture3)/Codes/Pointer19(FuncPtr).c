#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void add(int a, int b)
{
    printf("%d\n", a + b);
}

void sub(int a, int b)
{
    printf("%d\n", a - b);
}

int main(void)
{
    void (*operation)(int, int);

    operation = &add;
    operation(10, 5);  
    // add 함수 호출

    operation = &sub;
    operation(10, 5);  
    // sub 함수 호출

    return 0;
}