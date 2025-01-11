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

    printf("%d %d %d\n", (*ptrP).x, (*ptrP).y, (*ptrP).z);
    printf("%d %d %d\n", ptrP->x, ptrP->y, ptrP->z);
    return 0;
}