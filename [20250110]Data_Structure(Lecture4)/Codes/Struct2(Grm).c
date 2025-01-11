#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student
{
	int id;
	double grade;
};
// student 구조체 선언
// 2개의 멤버를 가지고 있음

struct total
{
	double mean;
	struct student std;
};
// 이름없는 구조체 선언
// 2개의 멤버를 가지고 있음
// 멤버 중 하나는 구조체 변수

int main(void)
{
	struct total t1 = { 3.1, {12, 4.5} };
	// {}을 이용하여 초기화
	// {}내부의 구조체도 {}을 통하여 초기화한다.

	printf("%.1lf\n%d\n%.1lf\n", t1.mean, t1.std.id, t1.std.grade);
	// 값 출력

	return 0;
}