#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

union Value
{
    int stu_id;
    char reg_id[10];
};

struct Student 
{
    union Value id;
    double grade;
};

int main(void)
{
    struct Student s1;
    struct Student s2;

    s1.id.stu_id = 341;
    s1.grade = 4.5;

    strcpy(s2.id.reg_id, "1231");
    s2.grade = 3.2;

    printf("%d %.1lf\n", s1.id.stu_id, s1.grade);
    printf("%s %.1lf\n", s2.id.reg_id, s2.grade);

    return 0;
}