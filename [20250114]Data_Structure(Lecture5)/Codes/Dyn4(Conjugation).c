#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
    int z;
} Point;

int main(void) 
{
    int n;
    scanf("%d", &n);
    Point* ptr = (Point*)malloc(n * sizeof(Point));
    if (ptr == NULL)
        return 1;
    Point sum = { 0,0,0 };
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &ptr[i].x, &ptr[i].y, &ptr[i].z);
        sum.x += ptr[i].x;
        sum.y += ptr[i].y;
        sum.z += ptr[i].z;
    }
    printf("%d %d %d", sum.x, sum.y, sum.z);

    free(ptr);
    return 0;
}