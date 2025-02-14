# 동적 메모리 활용

## 구조체 동적 할당

```c
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
```

```
3
1 2 3
4 5 6
7 8 9
12 15 18
```

## 2차원 배열 동적 할당

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int n, m;
    scanf("%d %d", &n, &m);

    int** ptr = (int**)malloc(n * sizeof(int*));
    if (ptr == NULL)
        return 1;

    for (int i = 0; i < n; i++) 
    {
        ptr[i] = (int*)malloc(m * sizeof(int));

        if (ptr[i] == NULL) 
        {
            for (int j = 0; j < i; j++)
                free(ptr[j]);
            
            free(ptr);
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &ptr[i][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", ptr[i][j]);
        printf("\n");
    }

    for (int i = 0; i < n; i++)
        free(ptr[i]);
    free(ptr);
    return 0;
}
```

```
3 3
1 2 3
2 3 4
3 4 5
1 2 3
2 3 4
3 4 5
```