# Array Stack Type

## Object

### 코드

```c
#define MAX_SIZE 100

typedef int element;
typedef struct
{
	element stack[MAX_SIZE];
	int top;
} ArrayStack;
```

### 설명

- `MAX_SIZE`: 스택이 저장할 수 있는 최대 요소의 개수를 정의.
- `element`: 스택의 요소 타입(여기서는 `int`로 정의).
- `ArrayStack` 구조체:
    - `stack[MAX_SIZE]`: 데이터를 저장하는 배열.
    - `top`: 현재 스택의 가장 마지막 위치.

## init

### 코드

```c
void init(ArrayStack* sp)
{
    sp->top = -1;
    return;
}
```

### 코드의 흐름

1. `sp->top`을 `-1`로 설정:
    - 스택의 초기 상태를 설정하며, 스택이 비어 있음을 나타낸다.
2. `return`:
    - 함수가 정상적으로 종료됨을 명시한다.

## isEmpty

### 코드

```c
bool isEmpty(ArrayStack* sp)
{
    return (sp->top == -1);
}
```

### 코드의 흐름

1. 스택의 `top` 값을 확인: `top`이 `1`이면 스택이 비어 있음을 의미.
2. 결과 반환: 스택이 비어 있으면 `true`, 그렇지 않으면 `false`를 반환.

## isFull

### 코드

```c
bool isFull(ArrayStack* sp)
{
    return (sp->top == MAX_SIZE - 1);
}
```

### 코드의 흐름

1. 스택의 `top` 값을 확인: `top`이 `MAX_SIZE - 1`이면 스택이 가득 찬 상태.
2. 결과 반환: 스택이 가득 차 있으면 `true`, 그렇지 않으면 `false`를 반환.

## push

### 코드

```c
void push(ArrayStack* sp, element item)
{
    if (!isFull(sp))
    {
        sp->top++;
        sp->stack[sp->top] = item;
        return;
    }
    else
    {
        printf("Error: Stack is Full");
        exit(EXIT_FAILURE);
    }
}
```

### 코드의 흐름

1. `isFull(sp)`를 호출하여 스택 상태를 확인:
    - 가득 차 있지 않으면 다음 단계 진행.
    - 가득 차 있으면 오류 메시지를 출력하고 프로그램 종료.
2. `sp->top++`:
    - 스택의 `top` 값을 1 증가하여 삽입 위치를 결정.
3. `sp->stack[sp->top] = item`:
    - 스택의 꼭대기에 `item`을 삽입.
4. 함수 종료.

## pop

### 코드

```c
element pop(ArrayStack* sp)
{
    if (!isEmpty(sp))
    {
        element item = sp->stack[sp->top];
        sp->top--;
        return item;
    }
    else
    {
        printf("Error: Stack is Empty");
        exit(EXIT_FAILURE);
    }
}
```

### 코드의 흐름

1. `isEmpty(sp)`를 호출하여 스택 상태를 확인:
    - 비어 있지 않으면 다음 단계 진행.
    - 비어 있으면 오류 메시지를 출력하고 프로그램 종료.
2. `element item = sp->stack[sp->top]`:
    - 스택의 꼭대기 값을 임시 변수 `item`에 저장.
3. `sp->top--`:
    - 스택의 `top` 값을 1 감소하여 꼭대기 요소를 제거.
4. `item` 반환:
    - 꺼낸 요소를 호출자에게 반환.

## peek

### 코드

```c
element peek(ArrayStack* sp)
{
    if (!isEmpty(sp))
    {
        return sp->stack[sp->top];
    }
    else
    {
        printf("Error: Stack is Empty");
        exit(EXIT_FAILURE);
    }
}
```

### 코드의 흐름

1. `isEmpty(sp)`를 호출하여 스택 상태를 확인:
    - 비어 있지 않으면 다음 단계 진행.
    - 비어 있으면 오류 메시지를 출력하고 프로그램 종료.
2. `sp->stack[sp->top]`:
    - 스택의 꼭대기 값을 반환.
3. 반환된 값은 스택에서 제거되지 않음.

## display

### 코드

```c
void display(ArrayStack* sp)
{
    for (int i = 0; i <= sp->top; i++)
    {
        printf("%d ", sp->stack[i]);
    }
    printf("\n");
    return;
}
```

### 코드의 흐름

1. `for` 루프를 사용하여 `sp->stack`의 요소를 출력:
    - `i = 0`부터 `sp->top`까지 순차적으로 출력.
2. 각 요소를 공백으로 구분하여 출력.
3. `printf("\n")`:
    - 요소 출력 후 줄바꿈.
4. 함수 종료.

## 검증 코드

```c
int main(void) 
{
	ArrayStack stack;
	init(&stack);

	printf("Pushing elements onto the stack:\n");
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	display(&stack);

	printf("\nPeeking the top element: %d\n", peek(&stack));

	printf("\nPopping elements from the stack:\n");
	printf("Popped: %d\n", pop(&stack));
	printf("Popped: %d\n", pop(&stack));
	display(&stack);

	printf("\nPushing more elements onto the stack:\n");
	push(&stack, 40);
	push(&stack, 50);
	display(&stack);

	printf("\nPopping the remaining elements:\n");
	while (!isEmpty(&stack)) 
	{
		printf("Popped: %d\n", pop(&stack));
	}
	display(&stack);

	return 0;
}
```

```
Pushing elements onto the stack:
10 20 30

Peeking the top element: 30

Popping elements from the stack:
Popped: 30
Popped: 20
10

Pushing more elements onto the stack:
10 40 50

Popping the remaining elements:
Popped: 50
Popped: 40
Popped: 10
```