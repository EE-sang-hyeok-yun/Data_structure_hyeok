#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Student 
{
    int id;
    double grade;
};

int main(void) 
{
    struct Student s[3] = { 0 };
    for (int i = 0; i < 3; i++)
        scanf("%d %lf", &(s[i].id), &(s[i].grade));
    printf("\n");
    for (int i = 0; i < 3; i++)
        printf("%d %.1lf\n", s[i].id, s[i].grade);
    return 0;
}