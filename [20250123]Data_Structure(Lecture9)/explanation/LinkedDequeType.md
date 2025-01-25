# Linked Deque Type

## Object

### 코드

```c
typedef int element;

typedef struct queueNode 
{
    element data;
    queueNode* rightLink;
    queueNode* leftLink;
} queueNode;

typedef struct 
{
    queueNode* front;
    queueNode* rear;
    int cnt;
} queueType;
```

### 설명

- `element`: 덱(deque)의 요소 타입(현재 `int`로 정의).
- `queueNode` 구조체:
    - `data`: 노드에 저장된 데이터.
    - `rightLink`: 다음 노드를 가리키는 포인터.
    - `leftLink`: 이전 노드를 가리키는 포인터.
- `queueType` 구조체:
    - `front`: 덱의 첫 번째 노드를 가리키는 포인터.
    - `rear`: 덱의 마지막 노드를 가리키는 포인터.
    - `cnt`: 덱의 현재 요소 개수.

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

### 설명

- 초기화:
    - `front`와 `rear`를 `NULL`로 설정하여 덱을 빈 상태로 초기화한다.
    - `cnt`를 0으로 설정하여 덱의 요소 개수를 초기화한다.

## isEmpty

### 코드

```c
bool isEmpty(queueType* queue) 
{
    return (queue->cnt == 0);
}
```

### 설명

1. 덱이 비어 있는 상태 확인:
    - `cnt`가 0이면 덱이 비어 있음을 의미한다.
2. 결과 반환:
    - 비어 있으면 `true`를 반환한다.

## addFront

### 코드

```c
void addFront(queueType* queue, element item) 
{
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    if (newNode == NULL) 
    {
        printf("Error: Memory Allocation Error\n");
        return;
    }
    newNode->leftLink = NULL;
    newNode->rightLink = queue->front;
    newNode->data = item;

    if (isEmpty(queue))
        queue->rear = newNode;
    else
        queue->front->leftLink = newNode;

    queue->front = newNode;
    queue->cnt++;
    return;
}
```

### 설명

1. 새로운 노드 생성:
    - 새로운 노드를 동적 메모리로 생성하고 데이터를 초기화한다.
2. 연결 업데이트:
    - 새 노드를 `front`에 추가하고 기존 `front`와 연결을 갱신한다.
3. 비어 있는 경우:
    - 덱이 비어 있으면 `rear`도 새 노드를 가리킨다.
4. 요소 개수 증가:
    - `cnt`를 증가시킨다.

## addRear

### 코드

```c
void addRear(queueType* queue, element item) 
{
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    if (newNode == NULL) 
    {
        printf("Error: Memory Allocation Error\n");
        return;
    }
    newNode->rightLink = NULL;
    newNode->leftLink = queue->rear;
    newNode->data = item;

    if (isEmpty(queue))
        queue->front = newNode;
    else
        queue->rear->rightLink = newNode;

    queue->rear = newNode;
    queue->cnt++;
    return;
}
```

### 설명

1. 새로운 노드 생성:
    - 새로운 노드를 동적 메모리로 생성하고 데이터를 초기화한다.
2. 연결 업데이트:
    - 새 노드를 `rear`에 추가하고 기존 `rear`와 연결을 갱신한다.
3. 비어 있는 경우:
    - 덱이 비어 있으면 `front`도 새 노드를 가리킨다.
4. 요소 개수 증가:
    - `cnt`를 증가시킨다.

## delFront

### 코드

```c
element delFront(queueType* queue) 
{
    if (isEmpty(queue))
        return 0;

    queueNode* node = queue->front;
    queue->front = node->rightLink;

    element item = node->data;
    free(node);

    queue->cnt--;

    if (queue->front == NULL)
        queue->rear = NULL;
    else
        queue->front->leftLink = NULL;

    return item;
}
```

### 설명

1. 비어 있는 상태 확인:
    - 덱이 비어 있으면 0을 반환한다.
2. 노드 제거:
    - `front` 노드를 제거하고 다음 노드를 새 `front`로 설정한다.
3. 연결 갱신:
    - `front`가 NULL이면 `rear`도 NULL로 설정한다.
4. 요소 개수 감소:
    - `cnt`를 감소시킨다.

## delRear

### 코드

```c
element delrear(queueType* queue) 
{
    if (isEmpty(queue))
        return 0;

    queueNode* node = queue->rear;
    queue->rear = node->leftLink;

    element item = node->data;
    free(node);

    queue->cnt--;

    if (queue->rear == NULL)
        queue->front = NULL;
    else
        queue->rear->rightLink = NULL;

    return item;
}
```

### 설명

1. 비어 있는 상태 확인:
    - 덱이 비어 있으면 0을 반환한다.
2. 노드 제거:
    - `rear` 노드를 제거하고 이전 노드를 새 `rear`로 설정한다.
3. 연결 갱신:
    - `rear`가 NULL이면 `front`도 NULL로 설정한다.
4. 요소 개수 감소:
    - `cnt`를 감소시킨다.

## 검증 코드

### 코드

```c
int main(void)
{
	queueType queue;
	init(&queue);

	addFront(&queue, 10);
	addRear(&queue, 20);
	addFront(&queue, 5);
	addRear(&queue, 30);

	printf("5 10 20 30\n");

	printf("Deleted from Front: %d\n", delFront(&queue));
	printf("Deleted from Rear: %d\n", delrear(&queue));

	printf("10 20\n");

	printf("Deleted from Front: %d\n", delFront(&queue));
	printf("Deleted from Rear: %d\n", delrear(&queue));

	addFront(&queue, 40);
	addRear(&queue, 50);

	printf("40 50\n");

	while (!isEmpty(&queue))
	{
		printf("Deleted: %d\n", delFront(&queue));
	}

	return 0;
}
```

### 결과

```
5 10 20 30
Deleted from Front: 5
Deleted from Rear: 30
10 20
Deleted from Front: 10
Deleted from Rear: 20
40 50
Deleted: 40
Deleted: 50
```