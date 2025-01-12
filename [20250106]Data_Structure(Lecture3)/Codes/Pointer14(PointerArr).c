#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	const char* ptrStr[] =
	{
		"Apple",
		"BlueBerry",
		"Orange"
	};

	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", ptrStr[i]);
		printf("%p\n\n", ptrStr[i]);
	}
	return 0;
}