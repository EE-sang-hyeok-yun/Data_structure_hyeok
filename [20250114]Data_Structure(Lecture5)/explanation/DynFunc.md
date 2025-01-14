# 동적 메모리 함수

## `malloc` 함수

- `malloc` 함수는 지정된 크기의 메모리를 힙(Heap) 영역에 할당하며, 메모리의 시작 주소를 반환한다.
- 반환된 메모리 주소의 데이터는 초기화되지 않으며, 할당된 크기 내의 값은 불확정 상태다.

### 문법

```c
void* malloc(size_t size);
```

- `size`: 할당받을 메모리의 크기(바이트 단위).
- 반환값은 `void*` 포인터로, 성공하면 메모리의 시작 주소를 반환하고, 실패하면 `NULL`을 반환한다.
- N개의 데이터를 저장하는 공간을 할당하려면 변수의 자료형 크기와 N 을 곱한 만큼 `size` 를 정한다.
- 포인터 변수에 대입하려면 형 변환을 자료형에 맞게 하여 대입한다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int n;
    scanf("%d", &n);

    int* ptr = (int*)malloc(n * sizeof(int)); 
    // 정수 n개 크기의 메모리 할당
    // (void*)형 반환
    // (int*)형으로 형 변환

    for (int i = 0; i < n; i++) 
        ptr[i] = i;
    // 초기화

    for (int i = 0; i < n; i++)
        printf("%d ", ptr[i]);
    // 출력

    free(ptr);
    // 메모리 해제

    return 0;
}
```

```
10
0 1 2 3 4 5 6 7 8 9
```

## `calloc` 함수

- `calloc` 함수는 `malloc`과 비슷하지만, 할당된 메모리를 0으로 초기화한다.
- 요소의 개수와 각 요소의 크기를 입력받아, 메모리를 연속적으로 할당한다.

### 문법

```c
void* calloc(size_t nitems, size_t size);
```

- `nitems`: 할당할 요소의 개수.
- `size`: 각 요소의 크기(바이트 단위).
- `size` 의 크기의(단일)  `nitems` 개의 변수가 들어가는 메모리 공간이 할당된다.
- 반환값은 성공 시 메모리의 시작 주소를 반환하고, 실패 시 `NULL`을 반환한다.
- 포인터 변수에 대입하려면 형 변환을 자료형에 맞게 하여 대입한다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int n;
    scanf("%d", &n);

    int* ptr = (int*)calloc(n, sizeof(int));
    // (void*)형 반환
    // (int*)형으로 형 변환

    for (int i = 0; i < n; i++)
        printf("%d ", ptr[i]);
    // 출력

    free(ptr);
    // 메모리 해제

    return 0;
}
```

```c
10
0 0 0 0 0 0 0 0 0 0
// 0으로 초기화 되었다
```

## `realloc` 함수

- `realloc` 함수는 기존에 할당된 메모리의 크기를 조정하거나, 필요 시 새로운 메모리를 할당한다.
- 기존 데이터를 유지하며 메모리 크기를 늘리거나 줄일 수 있다.

### 문법

```c
void* realloc(void* ptr, size_t size);
```

- `ptr`: 기존에 할당된 메모리 블록의 시작 주소.
- `size`: 새로 할당할 메모리 크기(바이트 단위).
- 반환값은 새로운 메모리 블록의 시작 주소를 반환하고, 실패 시 `NULL` 을 반환한다.
- 줄어든 메모리 크기보다 큰 데이터는 보존되지 않는다.
- 따라서 데이터를 줄이기 전에 필요한 값들을 미리 처리하거나 저장해야 한다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int* ptr = (int*)malloc(3 * sizeof(int)); 
    // 초기 메모리 할당

    if (ptr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }// 예외 처리

    for (int i = 0; i < 3; i++) 
    {
        ptr[i] = i + 1;
    }// 메모리 초기화

    ptr = (int*)realloc(ptr, 5 * sizeof(int)); 
    // 메모리 크기 재조정

    if (ptr == NULL) 
    {
        printf("Memory reallocation failed!\n");
        return 1;
    }// 예외 처리

    for (int i = 3; i < 5; i++) 
    {
        ptr[i] = i + 1; 
    }// 새로운 메모리 공간 초기화

    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", ptr[i]);
    }// 출력

    free(ptr); // 메모리 해제
    return 0;
}
```

```
1 2 3 4 5
```

## `free` 함수

- `free` 함수는 동적으로 할당된 메모리를 해제하여, 시스템에 반환한다.
- 이미 해제된 메모리나 `NULL` 포인터에 대해 호출해도 문제는 발생하지 않는다.

### 문법

```c
void free(void* ptr);
```

- `ptr`: 해제할 메모리 블록의 시작 주소.