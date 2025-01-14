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