#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Mixed1
{
    char a;    // 1 byte
    double b;  // 8 bytes
    int c;     // 4 bytes
};
struct Mixed2
{
    double a;  // 8 bytes
    char b;    // 1 byte
    int c;     // 4 bytes
};

int main(void)
{
    int size1 = sizeof(struct Mixed1);
    int size2 = sizeof(struct Mixed2);

    printf("Size of Mixed1:%d\n", size1);
    printf("Size of Mixed2:%d\n", size2);

    return 0;
}