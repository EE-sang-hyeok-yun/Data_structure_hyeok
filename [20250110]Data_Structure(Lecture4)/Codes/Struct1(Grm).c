#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student
{
	int id;
	double grade;
};
// student 구조체 선언
// 2개의 멤버를 가지고 있음

struct
{
	double mean;
	double max;
	double min;
} group1, group2;
// 이름없는 구조체 선언
// 3개의 멤버를 가지고 있음
// 2개의 변수 선언
// 이 변수명만 사용 가능하다

int main(void)
{
	struct student s1;
	// student 구조체 변수 s1 선언

	s1.id = 1;
	s1.grade = 4.5;
	// 각 멤버에 값 대입

	struct student s2;
	// student 구조체 변수 s2 선언

	s2.id = 2;
	s2.grade = 4.23;
	// 각 멤버에 값 대입

	printf("%d %.3lf\n", s1.id, s1.grade);
	printf("%d %.3lf\n", s2.id, s2.grade);

	group1.mean = 3.1;
	group1.max = 4.5;
	group1.min = 2.0;
	// group1의 각 멤버에 값 대입
	// 이 구조체에는 이름이 없음

	group2.mean = 3.2;
	group2.max = 4.5;
	group2.min = 2.3;
	// group2의 각 멤버에 값 대입
	// 이 구조체에는 이름이 없음

	printf("%.3lf %.3lf %.3lf\n", group1.mean, group1.max, group1.min);
	printf("%.3lf %.3lf %.3lf\n", group2.mean, group2.max, group2.min);

	return 0;
}