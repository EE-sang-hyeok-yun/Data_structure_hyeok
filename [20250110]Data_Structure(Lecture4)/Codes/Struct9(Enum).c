#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum Day 
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main(void) 
{
    enum Day today = Monday;

    if (today == Monday)
        printf("Today is Monday! %d\n", today);

    return 0;
}