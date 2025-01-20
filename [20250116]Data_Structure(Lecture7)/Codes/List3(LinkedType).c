#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct listNode
{
	element data;
	struct listNode* link;
} listNode;
typedef struct
{
	listNode* head;
	int length;
} listType;

listNode* creatNode(element data);
void insertNode(listNode** preHead, listNode* pre, listNode* newNode);
void removeNode(listNode** preHead, listNode* pre, listNode* removeNode);
void displayNode(listNode* head);
void displayRecur(listNode* head);
listNode* search(listNode* head, element x);
listNode* concat(listNode* head1, listNode* head2);

void init(listType* list);
bool isEmpty(listType* list);
int getLength(listType* list);
bool isInList(listType* list, element item);
listNode* getNodeAt(listType* list, int pos);
void add(listType* list, int pos, element item);
void del(listType* list, int pos);
element getEntry(listType* list, int pos);

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
void insertNode(listNode** preHead, listNode* pre, listNode* newNode)
{
	// preHead: Head 의 주소를 담은 포인터
	// pre: 삽입 위치 이전의 Node의 주소
	// newNode: 새로운 Node의 주소

	if (*preHead == NULL) // 공백 리스트인 경우
	{
		*preHead = newNode;
	}
	else if (pre == NULL) // pre가 NULL이면 첫번째 노드로 삽입
	{
		newNode->link = *preHead;
		*preHead = newNode;
	}
	else // pre 다음에 삽입
	{
		newNode->link = pre->link;
		pre->link = newNode;
	}
	return;
}
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

void init(listType* list)
{
	list->head = NULL; // 리스트의 헤드 노드를 NULL로 초기화
	list->length = 0;  // 리스트의 길이를 0으로 초기화
	return;            // 함수 종료
}
bool isEmpty(listType* list)
{
	if (list->length == 0) // 리스트의 길이가 0인지 확인
		return true;       // 비어 있으면 true 반환
	else
		return false;      // 비어 있지 않으면 false 반환
}
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
int getLength(listType* list)
{
	return list->length; // 리스트의 길이를 반환
}
listNode* getNodeAt(listType* list, int pos)
{
	listNode* posPtr = list->head; // 첫 번째 노드를 참조
	for (int i = 0; i < pos; i++)  // pos 위치까지 반복
		posPtr = posPtr->link;     // 다음 노드로 이동
	return posPtr;                 // 해당 위치의 노드 반환
}
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