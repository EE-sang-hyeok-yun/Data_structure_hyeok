# **Linked Queue Type**

## Object

### 코드

```c
typedef int element;

typedef struct queueNode
{
	element data;
	queueNode* link;
} queueNode;

typedef struct
{
	queueNode* front;
	queueNode* rear;
	int cnt;
} queueType;
```

### 설명

- `element`: 큐의 데이터 요소를 정의하며 현재는 `int`로 설정되어 있다.
- `queueNode` 구조체:
    - `data`: 노드가 저장하는 데이터 값.
    - `link`: 다음 노드의 주소를 가리키는 포인터.
- `queueType` 구조체:
    - `front`: 큐의 첫 번째 노드를 가리키는 포인터.
    - `rear`: 큐의 마지막 노드를 가리키는 포인터.
    - `cnt`: 큐에 저장된 노드의 개수.

## init

### 코드

```c
void init(queueType* queue)
{
	queue->front = NULL;
	queue->rear = NULL;
	queue->cnt = 0;
	return;
}
```

### 코드의 흐름

- 큐의 초기화를 수행한다.
    - `front`와 `rear`를 `NULL`로 설정하여 큐를 비어 있는 상태로 만든다.
    - `cnt`를 0으로 설정한다.

## isEmpty

### 코드

```c
bool isEmpty(queueType* queue)
{
	return (queue->cnt == 0);
}
```

### 코드의 흐름

- 큐가 비어 있는 상태를 확인한다.
    - `cnt`가 0이면 큐가 비어 있음을 의미하며, `true`를 반환한다.
    - 그렇지 않으면 `false`를 반환한다.

## enqueue

### 코드

```c
void enqueue(queueType* queue, element item)
{
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	if (newNode == NULL)
	{
		printf("Error: Memory Allocation Error\n");
		return;
	}
	newNode->link = NULL;
	newNode->data = item;

	if (isEmpty(queue))
		queue->front = newNode;
	else
		queue->rear->link = newNode;

	queue->rear = newNode;
	queue->cnt++;
	return;
}
```

### 코드의 흐름

- 새로운 노드를 생성하고 데이터를 삽입한다.
    - 메모리 할당 후 `data`에 값을 저장하고, `link`는 `NULL`로 초기화.
    - 큐가 비어 있다면 `front`를 새 노드로 설정한다.
    - 큐에 노드가 존재하면, `rear->link`가 새 노드를 가리키도록 한다.
    - `rear`를 새 노드로 갱신하고, `cnt`를 1 증가시킨다.

## dequeue

### 코드

```c
element dequeue(queueType* queue)
{
	if (isEmpty(queue))
		return 0;
	queueNode* node = queue->front;
	queue->front = node->link;
	element item = node->data;
	free(node);
	queue->cnt--;
	return item;
}
```

### 코드의 흐름

- 큐의 첫 번째 노드를 제거하고 데이터를 반환한다.
    - `isEmpty()`를 호출하여 큐가 비어 있으면 0을 반환.
    - `front` 노드를 `node`에 저장하고, 다음 노드로 `front`를 갱신.
    - 제거된 노드의 데이터를 저장하고, 메모리를 해제.
    - `cnt`를 1 감소시킨 후 데이터를 반환한다.

## peek

### 코드

```c
element peek(queueType* queue)
{
	if (isEmpty(queue))
		return 0;
	queueNode* node = queue->front;
	element item = node->data;
	return item;
}
```

### 코드의 흐름

- 큐의 첫 번째 데이터 값을 반환한다.
    - `isEmpty()`로 큐가 비어 있는지 확인.
    - 비어 있다면 0을 반환, 아니면 `front` 노드의 데이터를 반환.

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