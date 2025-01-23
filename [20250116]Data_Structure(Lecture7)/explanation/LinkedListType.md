# Linked List Type

## stackNode

### 코드

```c
typedef int element;
typedef struct listNode
{
    element data;
    struct listNode *link;
} listNode;
```

### 설명

- 구조체 정의:
    - `listNode`는 연결 리스트의 하나의 노드를 나타낸다.
- 구성 요소:
    - `element data`: 노드가 저장하는 데이터. 여기서 `typedef int element`로 정의되어 있으므로 정수형 데이터를 저장한다.
    - `struct listNode *link`: 다음 노드를 가리키는 포인터. 연결 리스트의 다음 요소를 연결하는 역할을 한다.
- 연결 리스트:
    - 여러 `listNode`가 `link`를 통해 연결되어 리스트를 형성한다.

## stackType

### 코드

```c
typedef struct
{
    listNode *head;
    int length;
} listType;
```

### 설명

- 구조체 정의:
    - `listType`은 연결 리스트의 전체 구조를 나타낸다.
- 구성 요소:
    - `listNode *head`: 연결 리스트의 첫 번째 노드를 가리키는 포인터.
    - `int length`: 리스트에 포함된 노드의 개수를 나타내는 정수 값.
- 리스트의 동작:
    - `head`를 통해 리스트의 첫 번째 노드에 접근 가능.
    - 삽입 및 삭제 연산은 `head`를 기준으로 수행되며, 노드의 연결 상태를 변경.
    - `length`는 리스트의 노드 개수를 추적하여 리스트의 상태를 관리.
- 유연성:
    - 연결 리스트 기반으로 구현되었으므로 동적 메모리를 사용하여 필요한 만큼 노드를 추가하거나 제거할 수 있음.
    - 노드의 개수에 제한이 없으며, 리스트의 길이를 효율적으로 관리 가능.

## creatNode

### 코드

```c
listNode* creatNode(element data)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	// 새로운 Node의 메모리 할당
	if (newNode == NULL)
	{
		printf("Error: Memory Allocation Error");
		exit(EXIT_FAILURE);
	}
	// 할당 오류 예외처리
	newNode->data = data;
	newNode->link = NULL;
	// data를 입력
	// 주소를 NULL로 초기화
	return newNode;
	// 새로운 Node의 주소를 반환
}
```

- `listNode*`: 함수의 반환형으로 `listNode` 구조체의 포인터를 반환한다.
- `creatNode`: 함수 이름으로 새로운 노드를 생성하는 역할을 수행한다.
- `element data`: 함수의 매개변수로 전달된 데이터를 새 노드에 저장한다.

### 코드의 흐름

- 함수 호출 시 데이터 값을 인수로 전달한다.
- `malloc`을 통해 메모리를 동적으로 할당받는다.
- 메모리 할당에 실패하면 오류 메시지를 출력하고 종료한다.
- 데이터와 링크를 초기화한 뒤, 새 노드의 주소를 반환한다.

## insertNode

### 코드

```c
void insertNode(listNode** preHead, listNode* pre, listNode* newNode)
{
	// preHead: Head 의 주소를 담은 포인터
	// pre: 삽입 위치 이전의 Node의 주소
	// newNode: 새로운  Node의 주소

	if (*preHead == NULL)// 공백 리스트인 경우
	{
		*preHead = newNode;
	}
	else if (pre == NULL)// pre가 NULL이면 첫번째 노드로 삽입
	{
		newNode->link = *preHead;
		*preHead = newNode;
	}
	else// pre 다음에 삽입
	{
		newNode->link = pre->link;
		pre->link = newNode;
	}
	return;
}
```

- `void`: 함수가 값을 반환하지 않음을 의미한다.
- `listNode** preHead`: 리스트의 헤드 노드 주소를 가리키는 이중 포인터로, 리스트의 시작점을 관리한다.
- `listNode* pre`: 새 노드를 삽입할 위치의 이전 노드를 가리키는 포인터이다.
- `listNode* newNode`: 삽입할 새 노드의 주소를 가리키는 포인터이다.

### 코드의 흐름

- 리스트가 공백인지 확인하고, 공백이라면 새 노드를 첫 번째 노드로 설정한다.
- `pre`가 `NULL`이면 새 노드를 첫 번째 위치에 삽입한다.
- 그렇지 않으면 `pre` 다음에 새 노드를 삽입한다.

## removeNode

### 코드

```c
void removeNode(listNode** preHead, listNode* pre, listNode* removeNode)
{
	// preHead: Head 의 주소를 담은 포인터
	// pre: 삭제 위치 이전의 Node의 주소
	// removeNode: 삭제할 Node의 주소

	if (pre == NULL)// pre가 NULL이면 처음 위치 삭제
		*preHead = removeNode->link;// preHead를 통해 Head를 갱신한다
	else// 아니면 NULL pre의 다음 위치 삭제
		pre->link = removeNode->link;
	free(removeNode);
	// 삭제할 Node의 주소 위치의 메모리 해제
	return;
}
```

- `void`: 함수가 값을 반환하지 않음을 의미한다.
- `listNode** preHead`: 리스트의 헤드 노드의 주소를 가리키는 이중 포인터로, 리스트의 시작점을 관리한다.
- `listNode* pre`: 삭제할 노드의 이전 노드를 가리키는 포인터이다.
- `listNode* removeNode`: 삭제할 노드를 가리키는 포인터이다.

### 코드의 흐름

- 삭제할 노드가 리스트의 첫 번째 노드인지 확인한다.
- 첫 번째 노드라면, 헤드를 갱신한다.
- 그렇지 않으면, 이전 노드의 링크를 갱신하여 삭제할 노드를 제외한다.
- 삭제된 노드의 메모리를 해제한다.

## displayNode

### 코드

```c
void displayNode(listNode* head)
{
	// 모든 Node의 Data를 출력하는 함수
	listNode* node = head;
	// Head로 첫번째 Node 참조
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->link;
		// Node를 순회하면서 출력
		// 다음 위치의 Node의 주소를 참조하여 이동한다
	}
	printf("\n");
	return;
}
```

### 코드의 흐름

- `void`: 함수가 값을 반환하지 않음을 의미한다.
- `listNode* head`: 연결 리스트의 첫 번째 노드를 가리키는 포인터이다.
- `node`: 현재 노드를 참조하는 포인터로, 순회를 시작할 리스트의 헤드를 가리킨다.
- `while (node != NULL)`: 현재 노드가 `NULL`이 아닐 때까지 반복하여 모든 노드를 순회한다.
- `node->data`: 현재 노드의 데이터를 출력한다.
- `node = node->link`: 다음 노드로 이동한다.
- 순회를 종료한 뒤 줄을 바꿔 출력 형식을 마무리한다.

## displayRecur

### 코드

```c
void displayRecur(listNode* head)
{
	// 모든 Node의 Data를 출력하는 함수
	if (head != NULL)
	{
		printf("%d ", head->data);
		displayRecur(head->link);
		// 다음 주소 주소를 매개변수로 존달
	}
	// 순환 호출로 head가 NULL일 때 까지 출력한다
	// head가 NULL 이라는 말은 이전 함수가 가리키는 주소가 NULL
	// 마지막 요소라는 뜻
}
```

### 코드의 흐름

- `void`: 함수가 값을 반환하지 않음을 의미한다.
- `listNode* head`: 출력할 연결 리스트의 첫 번째 노드를 가리키는 포인터이다.
- `head != NULL`: 현재 노드가 `NULL`인지 확인하여 리스트의 끝에 도달했는지 확인한다.
- `printf("%d ", head->data)`: 현재 노드의 데이터를 출력한다.
- `displayRecur(head->link)`: 다음 노드의 주소를 매개변수로 하여 함수를 재귀 호출한다.
- 재귀 호출은 리스트의 끝에 도달했을 때 종료되며, 이후 스택에서 재귀 호출이 차례로 반환된다.

## search

### 코드

```c
listNode* search(listNode* head, element x)
{
	listNode* node = head; // 리스트의 첫 번째 노드를 참조
	while (node != NULL) // 리스트의 끝에 도달할 때까지 반복
	{
		if (x == node->data) // 현재 노드의 데이터가 검색 값과 같다면
			return node; // 해당 노드의 주소를 반환
		node = node->link; // 다음 노드로 이동
	}
	return NULL; // 값을 찾지 못한 경우 NULL 반환
}
```

### 코드의 흐름

- `listNode*`: 함수의 반환형으로, 검색한 노드의 주소를 반환한다.
- `listNode* head`: 연결 리스트의 첫 번째 노드를 가리키는 포인터이다.
- `element x`: 검색할 데이터 값이다.
- `node = head`: 리스트 순회를 시작하기 위해 첫 번째 노드를 참조한다.
- `while (node != NULL)`: 리스트의 끝에 도달할 때까지 반복한다.
- `x == node->data`: 현재 노드의 데이터가 검색 값과 같은지 비교한다.
- `return node`: 검색 값이 발견되면 해당 노드의 주소를 반환한다.
- `node = node->link`: 다음 노드로 이동하여 검색을 계속한다.
- 값이 리스트에 존재하지 않으면 `NULL`을 반환하여 검색 실패를 나타낸다.

## concat

### 코드

```c
listNode* concat(listNode* head1, listNode* head2)
{
    // 예외 처리: 한쪽 리스트가 비어 있는 경우
    if (head1 == NULL)
        return head2; // 첫 번째 리스트가 비어 있으면 두 번째 리스트 반환
    else if (head2 == NULL)
        return head1; // 두 번째 리스트가 비어 있으면 첫 번째 리스트 반환

    // 리스트 연결
    listNode* node = head1; // 첫 번째 리스트의 시작점
    while (node->link != NULL) // 리스트의 끝까지 이동
    {
        node = node->link;
    }
    node->link = head2; // 첫 번째 리스트의 끝을 두 번째 리스트의 시작으로 연결
    return head1; // 연결된 리스트의 헤드 반환
}
```

### 코드의 흐름

- `listNode*`: 함수의 반환형으로, 두 리스트를 연결한 결과 리스트의 첫 번째 노드 주소를 반환한다.
- `listNode* head1`: 첫 번째 연결 리스트의 헤드 노드를 가리키는 포인터.
- `listNode* head2`: 두 번째 연결 리스트의 헤드 노드를 가리키는 포인터.
- `head1 == NULL`: 첫 번째 리스트가 비어 있는 경우, 두 번째 리스트를 반환.
- `head2 == NULL`: 두 번째 리스트가 비어 있는 경우, 첫 번째 리스트를 반환.
- `node = head1`: 첫 번째 리스트를 탐색하기 위해 시작점을 설정한다.
- `while (node->link != NULL)`: 리스트의 마지막 노드까지 순회한다.
- `node->link = head2`: 첫 번째 리스트의 마지막 노드의 링크를 두 번째 리스트의 헤드로 연결한다.
- `return head1`: 연결된 리스트의 첫 번째 노드를 반환한다.

## reverse

### 코드

```c
listNode* reverse(listNode* head)
{
	listNode* previous = NULL;
	listNode* current = head;
	listNode* next = NULL;

	while (current != NULL)
	{
		next = current->link; 
		// current는 다음 노드를 가리킨다
		current->link = previous; 
		// next를 가리키던 link를 previous로 변경
		// 역방향이다
		previous = current;
		// 다음 노드로 이동
		current = next;
		// 다음 노드로 이동
	}
	head = previous;
	// 가장 마지막 노드를 head가 가리킨다
	// 리스트가 반전되었다.
	return head;
}
```

### 코드의 흐름

1. 초기화:
    - `previous`: 역방향 리스트를 형성하는 데 필요한 이전 노드를 저장. 초기값은 `NULL`.
    - `current`: 현재 작업 중인 노드를 가리킴. 초기값은 입력된 `head`.
    - `next`: 리스트 순회를 위해 다음 노드를 저장. 초기값은 `NULL`.
2. 루프 구조:
    - 조건: `current`가 `NULL`이 아닐 때까지 반복.
    - `next = current->link`: 현재 노드의 다음 노드를 임시 저장.
    - `current->link = previous`: 현재 노드의 링크를 이전 노드로 변경하여 역방향으로 설정.
    - `previous = current`: `previous`를 현재 노드로 이동.
    - `current = next`: `current`를 다음 노드로 이동.
3. 마무리:
    - 모든 노드의 링크가 반전된 후, `head`는 마지막 노드를 가리키게 된다.
    - 마지막 노드였던 `previous`를 새로운 리스트의 시작 노드로 반환.

## init

### 코드

```c
void init(listType* list)
{
    list->head = NULL; // 리스트의 헤드 노드를 NULL로 초기화
    list->length = 0;  // 리스트의 길이를 0으로 초기화
    return;            // 함수 종료
}
```

### 코드의 흐름

- `list->head = NULL`: 리스트를 초기화하며, 첫 번째 노드가 없음을 나타낸다.
- `list->length = 0`: 리스트의 길이를 0으로 설정한다.
- `return`: 함수 종료.

## isEmpty

### 코드

```c
bool isEmpty(listType* list)
{
    if (list->length == 0) // 리스트의 길이가 0인지 확인
        return true;       // 비어 있으면 true 반환
    else
        return false;      // 비어 있지 않으면 false 반환
}
```

### 코드의 흐름

- `list->length == 0`: 리스트가 비어 있는지 확인한다.
- `return true`: 비어 있으면 `true` 반환.
- `return false`: 비어 있지 않으면 `false` 반환.

## isInList

### 코드

```c
bool isInList(listType* list, element item)
{
    listNode* node = list->head; // 첫 번째 노드를 참조
    while (node != NULL)         // 리스트의 끝까지 반복
    {
        if (node->data == item)  // 노드의 데이터가 검색 값과 일치하면
            return true;         // true 반환
        node = node->link;       // 다음 노드로 이동
    }
    return false; // 값을 찾지 못한 경우 false 반환
}
```

### 코드의 흐름

- `list->head`: 첫 번째 노드를 참조.
- `while (node != NULL)`: 리스트의 끝까지 순회.
- `node->data == item`: 값이 일치하면 `true` 반환.
- `return false`: 값이 없으면 `false` 반환.

## getLength

### 코드

```c
int getLength(listType* list)
{
    return list->length; // 리스트의 길이를 반환
}
```

### 코드의 흐름

- `list->length`: 현재 리스트의 길이를 반환한다.

## getNodeAt

### 코드

```c
listNode* getNodeAt(listType* list, int pos)
{
    listNode* posPtr = list->head; // 첫 번째 노드를 참조
    for (int i = 0; i < pos; i++)  // pos 위치까지 반복
        posPtr = posPtr->link;     // 다음 노드로 이동
    return posPtr;                 // 해당 위치의 노드 반환
}
```

### 코드의 흐름

- `list->head`: 첫 번째 노드를 참조.
- `for` 반복문: `pos` 위치까지 이동.
- `return posPtr`: 해당 위치의 노드 반환.

## add

### 코드

```c
void add(listType* list, int pos, element item)
{
    listNode* newNode = creatNode(item); // 새 노드 생성
    if ((0 <= pos) && (pos <= list->length)) // 유효한 위치 확인
    {
        listNode* pre = NULL;
        pre = getNodeAt(list, pos - 1); // 이전 노드 가져오기
        insertNode(&(list->head), pre, newNode); // 노드 삽입
        list->length++; // 리스트 길이 증가
    }
    else
    {
        printf("Error: List Length Error");
        exit(EXIT_FAILURE); // 유효하지 않은 위치 처리
    }
    return;
}
```

### 코드의 흐름

- `creatNode(item)`: 새 노드를 생성.
- 위치 검사: `pos`가 유효한지 확인.
- `getNodeAt(list, pos - 1)`: 이전 노드 가져오기.
- `insertNode`: 새 노드를 리스트에 삽입.
- `list->length++`: 리스트 길이 갱신.

## del

### 코드

```c
void del(listType* list, int pos)
{
    if (!isEmpty(list)) // 리스트가 비어 있지 않은지 확인
    {
        if ((0 <= pos) && (pos <= list->length)) // 유효한 위치 확인
        {
            listNode* pre = NULL;
            pre = getNodeAt(list, pos - 1); // 이전 노드 가져오기
            removeNode(&(list->head), pre, pre->link); // 노드 삭제
            list->length--; // 리스트 길이 감소
        }
        else
        {
            printf("Error: List Length Error");
            exit(EXIT_FAILURE); // 유효하지 않은 위치 처리
        }
    }
    else
    {
        printf("Error: List Empty");
        exit(EXIT_FAILURE); // 리스트가 비어 있는 경우
    }
}
```

### 코드의 흐름

- `isEmpty`: 리스트가 비어 있는지 확인.
- 위치 검사: `pos`가 유효한지 확인.
- `getNodeAt(list, pos - 1)`: 이전 노드 가져오기.
- `removeNode`: 노드 삭제.
- `list->length--`: 리스트 길이 갱신.

## getEntry

### 코드

```c
element getEntry(listType* list, int pos)
{
    if ((0 <= pos) && (pos <= list->length)) // 유효한 위치 확인
    {
        listNode* ptr = NULL;
        ptr = getNodeAt(list, pos); // 해당 위치의 노드 가져오기
        return ptr->data; // 노드의 데이터 반환
    }
    else
    {
        printf("Error: List Length Error");
        exit(EXIT_FAILURE); // 유효하지 않은 위치 처리
    }
}
```

### 코드의 흐름

- 위치 검사: `pos`가 유효한지 확인.
- `getNodeAt(list, pos)`: 해당 위치의 노드 가져오기.
- `return ptr->data`: 노드 데이터 반환.

## main

### 코드

```c
int main(void) 
{
	// 리스트 초기화
	listType myList;
	init(&myList);

	// 리스트가 비어 있는지 확인
	printf("Is empty: %s\n", isEmpty(&myList) ? "true" : "false");

	// 요소 추가
	printf("Adding elements to the list...\n");
	add(&myList, 0, 10); // 첫 번째 위치에 10 추가
	add(&myList, 1, 20); // 두 번째 위치에 20 추가
	add(&myList, 2, 30); // 세 번째 위치에 30 추가

	// 리스트 출력
	printf("List after additions: ");
	displayNode(myList.head);

	// 길이 확인
	printf("List length: %d\n", getLength(&myList));

	// 특정 요소 검색
	element searchItem = 20;
	printf("Is %d in list: %s\n", searchItem, isInList(&myList, searchItem) ? "true" : "false");

	// 특정 위치의 요소 가져오기
	int pos = 1;
	printf("Element at position %d: %d\n", pos, getEntry(&myList, pos));

	// 요소 삭제
	printf("Deleting element at position 1...\n");
	del(&myList, 1);

	// 리스트 출력
	printf("List after deletion: ");
	displayNode(myList.head);

	// 재귀를 이용한 출력
	printf("List (recursive display): ");
	displayRecur(myList.head);
	printf("\n");

	// 리스트가 비어 있지 않은지 확인
	printf("Is empty: %s\n", isEmpty(&myList) ? "true" : "false");

	return 0;
}
```

### 코드의 흐름

- 리스트 초기화 및 비어 있는지 확인 (`init`, `isEmpty`).
- 요소 추가 (`add`).
- 리스트 출력 (`displayNode`).
- 리스트 길이 확인 (`getLength`).
- 특정 값 검색 (`isInList`).
- 특정 위치 요소 가져오기 (`getEntry`).
- 특정 위치 요소 삭제 (`del`).
- 재귀를 이용한 출력 (`displayRecur`).