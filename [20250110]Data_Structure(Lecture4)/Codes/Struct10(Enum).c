#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum
{
    RED = 1,
    GREEN,
    BLUE
};

int main(void)
{
    printf("RED: %d\n", RED);   // 1
    printf("GREEN: %d\n", GREEN); // 2
    printf("BLUE: %d\n", BLUE); // 3

    return 0;
}