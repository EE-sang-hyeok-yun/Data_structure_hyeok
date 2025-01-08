#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    int* ptr = arr; 
    // 배열의 첫 번째 요소를 가리킴

    printf("First ptr: %p Value: %d\n", ptr, *ptr);

    // 1. *ptr++
    printf("\n*ptr++\n");
    printf("Before: %p Value: %d\n", ptr, *ptr);
    int tmp = *ptr++;
    printf("After : %p Value: %d\n", ptr, *ptr);

    // 2. (*ptr)++
    printf("\n(*ptr)++\n");
    printf("Before: %p Value: %d\n", ptr, *ptr);
    (*ptr)++;
    printf("After : %p Value: %d\n", ptr, *ptr);

    // 3. ++*ptr
    printf("\n++*ptr\n");
    printf("Before: %p Value: %d\n", ptr, *ptr);
    ++(*ptr);
    printf("After : %p Value: %d\n", ptr, *ptr);

    // 4. ++(*ptr)
    printf("\n++(*ptr)\n");
    printf("Before: %p Value: %d\n", ptr, *ptr);
    ++(*ptr);
    printf("After : %p Value: %d\n", ptr, *ptr);

    // 5. *ptr--
    printf("\n*ptr--\n");
    printf("Before: %p Value: %d\n", ptr, *ptr);    
    tmp = *ptr--;
    printf("After : %p Value: %d\n", ptr, *ptr);

    // 6. (*ptr)--
    printf("\n(*ptr)--\n");
    printf("Before: %p Value: %d\n", ptr, *ptr);
    (*ptr)--;
    printf("After : %p Value: %d\n", ptr, *ptr);

    // 7. --*ptr
    printf("\n--*ptr\n");
    printf("Before: %p Value: %d\n", ptr, *ptr);
    --(*ptr);
    printf("After : %p Value: %d\n", ptr, *ptr);

    // 8. --(*ptr)
    printf("\n--(*ptr)\n");
    printf("Before: %p Value: %d\n", ptr, *ptr);
    --(*ptr);
    printf("After : %p Value: %d\n", ptr, *ptr);

    return 0;
}