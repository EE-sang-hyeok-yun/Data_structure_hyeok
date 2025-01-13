#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int arr[3][4] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int* ptr = (int*)arr;
    // 배열의 주소를 가리키는 포인터
    // 포인터 형변환하여 대입

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 4; j++) 
            printf("%d ", *ptr++);
        printf("\n");
    }

    return 0;
}