# Array Queue Type

## Object

### 코드

```c
#define MAX_SIZE 100

typedef int element;

typedef struct
{
    element arrQ[MAX_SIZE];
    int front;
    int rear;
} queueType;
```

### 설명

- `MAX_SIZE`: 큐의 최대 크기를 정의한다.
- `element`: 큐의 요소 타입(현재 `int`로 정의).
- `queueType` 구조체:
    - `arrQ[MAX_SIZE]`: 데이터를 저장하는 배열.
    - `front`: 큐의 첫 번째 요소를 가리키는 인덱스.
    - `rear`: 큐의 마지막 요소를 가리키는 인덱스.

## init

### 코드

```c
void init(queueType *queue)
{
    queue->front = queue->rear = 0;
    return;
}
```

### 코드의 흐름

`queue->front`와 `queue->rear` 값을 0으로 초기화하여 큐를 비어 있는 상태로 설정한다.

## isEmpty

### 코드

```c
bool isEmpty(queueType *queue)
{
    return (queue->front == queue->rear);
}
```

### 코드의 흐름

- 큐가 비어 있는 상태 확인:
    - `front`와 `rear`가 같은 경우 큐가 비어 있음을 의미한다.
- 결과 반환:
    - 비어 있으면 `true`를 반환한다.

## isFull

### 코드

```c
bool isFull(queueType *queue)
{
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}
```

### 코드의 흐름

- 큐가 가득 찬 상태 확인:
    - `(rear + 1) % MAX_SIZE`가 `front`와 같으면 큐가 가득 찬 상태이다.
    - 원형 큐 구조를 유지하기 위하여 모듈로 연산을 사용한다
- 결과 반환:
    - 가득 차 있으면 `true`를 반환한다.

## enqueue

### 코드

```c
void enqueue(queueType *queue, element item)
{
    if (isFull(queue))
    {
        printf("Error: Queue is Full");
        exit(EXIT_FAILURE);
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arrQ[queue->rear] = item;
}
```

### 코드의 흐름

- `isFull()` 호출:
    - 큐가 가득 찼는지 확인한다. 가득 차 있으면 오류 메시지를 출력하고 프로그램을 종료한다.
- 데이터 삽입:
    - `rear`를 1 증가시킨 후, 새로운 데이터를 `arrQ[rear]`에 저장한다.
- 원형 구조 유지:
    - `(rear + 1) % MAX_SIZE` 연산을 통해 배열의 경계를 초과하지 않도록 한다.
    - 원형 큐 구조를 유지하기 위하여 모듈로 연산을 사용한다

## dequeue

### 코드

```c
element dequeue(queueType *queue)
{
    if (isEmpty(queue))
    {
        printf("Error: Queue is Empty");
        exit(EXIT_FAILURE);
    }
    queue->front = (queue->front + 1) % MAX_SIZE;
    return queue->arrQ[queue->front];
}
```

### 코드의 흐름

- `isEmpty()` 호출:
    - 큐가 비어 있는지 확인한다. 비어 있으면 오류 메시지를 출력하고 프로그램을 종료한다.
- 데이터 제거:
    - `front`를 1 증가시켜 첫 번째 데이터를 제거한다.
- 제거된 데이터 반환:
    - `arrQ[front]` 값을 반환한다.

## peek

### 코드

```c
element peek(queueType *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty");
        return 0;
    }
    return queue->arrQ[queue->front + 1];
}
```

### 코드의 흐름

- `isEmpty()` 호출:
    - 큐가 비어 있는지 확인한다. 비어 있으면 오류 메시지를 출력하고 0을 반환한다.
- 데이터 참조:
    - `front`의 다음 위치 데이터를 반환한다. 원형 큐 구조를 유지하기 위해 `(front + 1) % MAX_SIZE`로 접근한다.
    - 원형 큐 구조를 유지하기 위하여 모듈로 연산을 사용한다

## 검증 코드

### 코드

```c
int main(void)
{
	queueType queue;
	init(&queue);

	enqueue(&queue, 10);
	printf("enqueue: %d\n", 10);
	enqueue(&queue, 20);
	printf("enqueue: %d\n", 20);
	enqueue(&queue, 30);
	printf("enqueue: %d\n", 30);

	printf("Peek: %d\n", peek(&queue));
	printf("Dequeue: %d\n", dequeue(&queue));
	printf("Dequeue: %d\n", dequeue(&queue));

	enqueue(&queue, 40);
	printf("enqueue: %d\n", 40);
	enqueue(&queue, 50);
	printf("enqueue: %d\n", 50);

	while (!isEmpty(&queue))
	{
		printf("Dequeue: %d\n", dequeue(&queue));
	}

	return 0;
}
```

### 결과

```
enqueue: 10
enqueue: 20
enqueue: 30
Peek: 10
Dequeue: 10
Dequeue: 20
enqueue: 40
enqueue: 50
Dequeue: 30
Dequeue: 40
Dequeue: 50
```