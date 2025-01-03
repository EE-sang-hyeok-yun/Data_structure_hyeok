#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number = -31415;
	short shortNumber = -1234;
	long longNumber = -314159265;
	long long greatNumber = -3141592653589;
	// signed 정수 선언과 초기화
	// 크기는 다음과 같다 
	// int -> 4
	// short -> 2
	// long -> 4
	// long long -> 8

	unsigned u_number = 31415;
	unsigned short u_shortNumber = 1234;
	unsigned long u_longNumber = 314159265;
	unsigned long long u_greatNumber = 3141592653589;
	// unsigned 정수 선언과 초기화
	// 크기는 다음과 같다 
	// unsigned (int) -> 4
	// unsigned short -> 2
	// unsigned long -> 4
	// unsigned long long -> 8

	printf("int %d %llu %llu\n", number, sizeof(int), sizeof(number));
	printf("short %d %llu %llu\n", shortNumber, sizeof(short), sizeof(shortNumber));
	printf("long %ld %llu %llu\n", longNumber, sizeof(long), sizeof(longNumber));
	printf("long long %lld %llu %llu\n\n", greatNumber, sizeof(long long), sizeof(greatNumber));

	printf("unsigned %u %llu %llu\n", u_number, sizeof(unsigned), sizeof(u_number));
	printf("unsigned short %u %llu %llu\n", u_shortNumber, sizeof(unsigned short), sizeof(u_shortNumber));
	printf("unsigned long %lu %llu %llu\n", u_longNumber, sizeof(unsigned long), sizeof(u_longNumber));
	printf("unsigned long long %llu %llu %llu\n", u_greatNumber, sizeof(unsigned long long), sizeof(u_greatNumber));

	return 0;
}