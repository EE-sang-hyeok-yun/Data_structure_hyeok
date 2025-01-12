#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printRow(int (*arrays)[4])
{
    // int (*)[4] 형태의 주소를 받고 출력하는 함수
    // 하나의 행을 출력한다
    for (int i = 0; i < 4; i++)
        printf("%d ", (*arrays)[i]);
    return;
}

int main(void) 
{
    // 2차원 배열 선언
    int arr[3][4] = 
    { 
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 } 
    };

    // 배열 포인터를 순회하며 배열 처리
    for (int i = 0; i < 3; i++) 
    {
        printRow((int (*)[4])arr[i]);
        printf("\n");
    }
    return 0;
}