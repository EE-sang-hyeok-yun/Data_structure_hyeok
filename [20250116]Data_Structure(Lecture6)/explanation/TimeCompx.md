# 시간 복잡도

## 개념

- 시간 복잡도란 알고리즘이 실행되는 데 걸리는 시간을 입력 크기(n)의 함수로 표현한 것이다.
- 입력 크기가 증가함에 따라 알고리즘의 실행 시간이 어떻게 변하는지를 분석하는 기준이다.
- 알고리즘의 효율성을 평가하고, 가장 적합한 알고리즘을 선택하기 위하여 사용한다.

## 주요 용어

### 기본 연산(Basic Operation)

- 알고리즘에서 실행되는 가장 중요한 작업을 말한다.
- 보통 루프 내부에 들어있는 중점적인 연산이다.

### 입력 크기(n)

- 알고리즘이 처리해야 할 데이터의 양이다.
- 프로그램에 주어진 입력 데이터의 크기이다.

### 실행 횟수

- 입력 크기(n)에 따라 알고리즘의 기본 연산이 몇 번 수행되는지 나타낸다.
- 입력 크기가 증가할 때, 실행되는 기본 연산의 횟수를 정밀하게 계산하기보다는 증가율을 분석한다.
- 세부적인 상수나 낮은 차수는 무시하고, 입력 크기에 따른 주요 성장 패턴만 고려한다.

## 빅오 표기법(Big-O Notation)

### 정의

- 빅오(Big-O)는 알고리즘의 시간 복잡도를 표현하기 위해 사용되는 수학적 표기법이다.
- 알고리즘의 실행 시간이 입력 크기(n)에 따라 최악의 경우 얼마나 증가하는지 나타낸다.
- 증가율(Growth Rate)에 초점을 맞추며, 알고리즘이 대규모 입력에서 어떻게 동작하는지를 분석한다.

### 상수와 낮은 차수 무시

- 빅오 표기법에서는 가장 빠르게 증가하는 항만 남기고, 상수 계수와 낮은 차수는 무시한다.
입력 크기가 커질수록, 낮은 차수와 상수의 영향은 미미하다.
- e.g.) $5n^2+3n+10=O(n^2)$
- e.g.) $2^n+3n+10=O(2^n)$

### 최악의 경우(Worst Case)

- 빅오 표기법은 주로 알고리즘의 최악의 경우를 분석한다.
- 최악의 경우는 성능 보장을 위해 중요하다.

### 자료의 실제 크기와 독립적와 독립적

- 빅오는 입력 크기 n에 의존적인 증가율만 표현한다.
- 특정 데이터나 실행 환경에 따라 다를 수 있는 절대 실행 시간은 고려하지 않는다.

## 주요 시간 복잡도 함수

| 빅오 표현 | 이름 | 증가율 설명 |
| --- | --- | --- |
| $O(1)$ | 상수 시간 | 입력 크기에 관계없이 일정. |
| $O(log⁡n)$ | 로그 시간 | 입력 크기의 로그에 비례. |
| O(n) | 선형 시간 | 입력 크기에 비례. |
| $O(nlog⁡n)$ | 선형로그 시간 | 선형과 로그의 곱에 비례. |
| $O(n^2)$ | 이차 시간 | 입력 크기의 제곱에 비례. |
| $O(2^n)$ | 지수 시간 | 입력 크기의 지수 함수에 비례. |
| $O(n!)$ | 팩토리얼 시간 | 입력 크기의 팩토리얼에 비례. |

## 시간 복잡도 분석 예시

### 선형 탐색

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int LinSearch(int* arr, int n, int target) 
{
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}// n 번 자료 탐색 -> 시간 복잡도 O(n)

int main(void) 
{
    int arr[] = { 1,2,3,5,7,8,9,10,11,13,14,15,17,18 };
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("%2d ", i);
    printf("\n");

    int target = 13;
    printf("Target: %d\n", target);
    printf("Index: %d\n", LinSearch(arr, n, target));
    return 0;
}
```

```
 1  2  3  5  7  8  9 10 11 13 14 15 17 18
 0  1  2  3  4  5  6  7  8  9 10 11 12 13
Target: 13
Index: 9
```

- 입력 크기(n): 배열의 크기.
- 기본 연산: 조건문을 통한 비교 연산.
- 실행 횟수: `n`회.
- 시간 복잡도: `O(n)`.

### 이진 탐색

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int binarySearch(int* arr, int n, int target) 
{
    int left = 0;
    int right = n - 1;

    while (left <= right) 
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target) 
            left = mid + 1;
        else 
            right = mid - 1;
    } // log2(n) 번 자료 탐색 -> 시간 복잡도 O(log(n))
    return -1;
}

int main(void) 
{
    int arr[] = { 1,2,3,5,7,8,9,10,11,13,14,15,17,18 };
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("%2d ", i);
    printf("\n");

    int target = 13;
    printf("Target: %d\n", target);
    printf("Index: %d\n", binarySearch(arr, n, target));
    return 0;
}
```

```
 1  2  3  5  7  8  9 10 11 13 14 15 17 18
 0  1  2  3  4  5  6  7  8  9 10 11 12 13
Target: 13
Index: 9
```

- 입력 크기(n): 배열의 크기.
- 기본 연산: 조건문을 통한 비교 연산.
- 실행 횟수: `log2(n)` (`binarySearch` 함수의 작동 횟수).
- 시간 복잡도: `O(log n)`.