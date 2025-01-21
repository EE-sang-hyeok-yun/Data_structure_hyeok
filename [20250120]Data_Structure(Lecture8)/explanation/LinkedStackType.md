# Linked Stack Type

## stackNode

### 코드

```c
typedef int element;
typedef struct stackNode
{
	element data;
	stackNode* link;
} stackNode;
```

### 설명

- 구조체 정의:
    - `stackNode`는 연결 리스트 기반 스택의 하나의 노드를 나타낸다.
- 구성 요소:
    - `element data`: 노드가 저장하는 데이터. 여기서는 `typedef int element`로 정의되어 있으므로 정수형 데이터를 저장한다.
    - `stackNode* link`: 다음 노드를 가리키는 포인터. 연결 리스트의 다음 요소를 연결하는 역할을 한다.
- 연결 리스트:
    - 여러 `stackNode`가 `link`를 통해 연결되며, 스택의 각 요소를 구성한다.

## stackType

### 코드

```c
typedef struct
{
    stackNode* top;
} stackType;
```

### 설명

- 구조체 정의:
    - `stackType`은 연결 리스트를 기반으로 한 스택 구조체를 나타낸다.
- 구성 요소:
    - `stackNode* top`: 스택의 꼭대기 노드를 가리키는 포인터.
- 스택의 동작:
    - `top`을 통해 스택의 맨 위 요소를 추적.
    - 삽입(`push`) 시 새로운 노드를 생성하여 `top`에 연결.
    - 삭제(`pop`) 시 `top` 노드를 제거하고 그 다음 노드를 새로운 `top`으로 설정.
- 유연성:
    - 연결 리스트 기반으로 구현되었으므로 스택의 크기에 제한이 없고 동적 메모리를 사용하여 필요한 만큼 확장 가능.

## init

### 코드

```c
void init(stackType* sp)
{
    sp->top = NULL;
}
```

### 코드의 흐름

1. 스택의 `top` 포인터를 `NULL`로 초기화 한다. 이는 스택이 비어 있음을 나타낸다.
2. 함수 종료.

## isEmpty

### 코드

```c
bool isEmpty(stackType* sp)
{
    return (sp->top == NULL);
}
```

### 코드의 흐름

1. 스택의 `top` 포인터를 확인:
    - `top`이 `NULL`이면 스택이 비어 있는 상태.
2. 결과 반환:
    - 스택이 비어 있으면 `true`, 그렇지 않으면 `false`를 반환.

## push

### 코드

```c
void push(stackType* sp, element item)
{
    stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
    if (newNode == NULL)
    {
        printf("Error: Memory Allocation Error\n");
        exit(EXIT_FAILURE);
    }
    newNode->link = sp->top;
    newNode->data = item;
    sp->top = newNode;
    return;
}
```

### 코드의 흐름

1. 새로운 노드를 생성:
    - `malloc`을 사용해 메모리를 할당.
    - 메모리 할당 실패 시 오류 메시지를 출력하고 프로그램 종료.
2. 새 노드 초기화:
    - `newNode->data`에 `item` 값을 저장.
    - `newNode->link`에 기존의 `top` 노드를 연결.
3. `sp->top`을 새 노드로 갱신:
    - 새로운 노드를 스택의 꼭대기로 설정.
4. 함수 종료.

## pop

### 코드

```c
element pop(stackType* sp)
{
    if (!isEmpty(sp))
    {
        element item = sp->top->data;
        stackNode* node = sp->top;
        sp->top = node->link;
        free(node);
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
    - 스택이 비어 있으면 오류 메시지를 출력하고 프로그램 종료.
2. 스택 꼭대기 요소 제거:
    - `item`에 `sp->top->data`를 저장.
    - 현재 `top` 노드의 주소를 임시 노드 포인터 `node`에 저장.
    - `sp->top`을 `node->link`로 변경하여 다음 노드를 꼭대기로 설정.
3. 제거한 노드 메모리 해제:
    - `free(node)`를 호출해 메모리 반환.
4. `item` 반환:
    - 꺼낸 요소를 반환.

## peek

### 코드

```c
element peek(stackType* sp)
{
    if (!isEmpty(sp))
    {
        element item = sp->top->data;
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
    - 스택이 비어 있으면 오류 메시지를 출력하고 프로그램 종료.
2. 스택 꼭대기 값 확인:
    - `sp->top->data`를 반환.
3. 값은 스택에서 제거되지 않고 유지됨.

## display

### 코드

```c
void display(stackType* sp)
{
    stackNode* node = sp->top;
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->link;
    }
    printf("\n");
    return;
}
```

### 코드의 흐름

1. `node`를 스택의 꼭대기(`sp->top`)로 설정.
2. `while` 루프:
    - `node`가 `NULL`이 아닐 때까지 반복.
    - 현재 노드의 데이터를 출력.
    - `node`를 `node->link`로 이동하여 다음 노드로 진행.
3. 모든 노드를 출력한 뒤 줄바꿈.
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
30 20 10

Peeking the top element: 30

Popping elements from the stack:
Popped: 30
Popped: 20
10

Pushing more elements onto the stack:
50 40 10

Popping the remaining elements:
Popped: 50
Popped: 40
Popped: 10
```