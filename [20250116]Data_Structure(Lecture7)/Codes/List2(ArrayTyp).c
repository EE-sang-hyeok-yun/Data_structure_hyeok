#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct
{
	element* arrPtr;
	int length;
	int MAX_SIZE;
} ArrayList;

void init(ArrayList* list, int listSize);
bool isEmpty(ArrayList* list);
bool isFull(ArrayList* list);
void append(ArrayList* list, element item);
void insert(ArrayList* list, int pos, element item);
element pop(ArrayList* list);
element del(ArrayList* list, int pos);

void init(ArrayList* list, int listSize)
{
	list->arrPtr = (element*)malloc(listSize * sizeof(element));
	list->MAX_SIZE = listSize;
	list->length = 0;
	return;
}

bool isEmpty(ArrayList* list)
{
	return (list->length == 0);
}

bool isFull(ArrayList* list)
{
	return (list->length == list->MAX_SIZE);
}

void append(ArrayList* list, element item)
{
	if (!isFull(list))
	{
		list->arrPtr[list->length] = item;
		list->length++;
	}
	else
	{
		printf("\nError: 리스트가 가득 참\n");
		exit(EXIT_FAILURE);
	}
	return;
}

void insert(ArrayList* list, int pos, element item)
{
	if (!isFull(list))
	{
		if ((0 <= pos)&&(pos <= list->length))
		{
			for (int i = list->length - 1; i >= pos; i--)
			{
				list->arrPtr[i + 1] = list->arrPtr[i];
			}
			list->arrPtr[pos] = item;
			list->length++;
		}
		else
		{
			printf("\nError: pos 위치 오류\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("\nError: 리스트가 가득 참\n");
		exit(EXIT_FAILURE);
	}
	return;
}

element pop(ArrayList* list)
{
	element item = list->arrPtr[0];
	if (!isEmpty(list))
	{
		for (int i = 0; i < list->length - 1; i++)
		{
			list->arrPtr[i] = list->arrPtr[i + 1];
		}
		list->length--;
		return item;
	}
	else
	{
		printf("\nError: 리스트가 비어있음\n");
		exit(EXIT_FAILURE);
	}
}


element del(ArrayList* list, int pos)
{
	element item = list->arrPtr[pos];

	if (!isEmpty(list))
	{
		if ((0 <= pos) && (pos < list->length))
		{
			for (int i = pos; i < list->length - 1; i++)
			{
				list->arrPtr[i] = list->arrPtr[i + 1];
			}
			list->length--;
			return item;
		}
		else
		{
			printf("\nError: pos 위치 오류\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("\nError: 리스트가 비어있음\n");
		exit(EXIT_FAILURE);
	}
}
void disp(ArrayList* list)
{
	for (int i = 0; i < list->length; i++)
		printf("%d ", list->arrPtr[i]);
	printf("\n");
	return;
}

int main(void)
{
	ArrayList list;
	int MAX;
	scanf("%d", &MAX);
	init(&list, MAX);
	for (int i=0;i<10;i++)
		append(&list, i);
	disp(&list);
	printf("%d<-\n", pop(&list));
	printf("%d<-\n", pop(&list));
	printf("%d<-\n", pop(&list));
	disp(&list);
	printf("->12, 3\n");
	insert(&list, 3, 12);
	printf("->10, 5\n");
	insert(&list, 5, 10);
	disp(&list);
	printf("%d<-\n", del(&list, 2));
	printf("%d<-\n", del(&list, 1));
	disp(&list);
	free(list.arrPtr);
	return 0;
}