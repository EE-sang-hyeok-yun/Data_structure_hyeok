#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Morning(void) 
{
    printf("Good Morning!\n");
}

void Afternoon(void)
{
    printf("Good Afternoon!\n");
}

void Evening(void)
{
    printf("Good Evening!\n");
}

int main(void) 
{
    void (*greet[3])(void) = { Morning, Afternoon, Evening };

    for (int i = 0; i < 3; i++) 
    {
        greet[i]();
    }
    return 0;
}