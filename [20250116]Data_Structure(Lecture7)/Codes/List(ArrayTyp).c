#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;

typedef struct
{
	element arr[MAX_SIZE];
	int length;
} ArrayList;

void init(ArrayList* list)
{
	list->length = 0;
	return;
}

int isEmpty(ArrayList* list)
{
	return (list->length == 0);
}

int isFull(ArrayList* list)
{
	return (list->length == MAX_SIZE);
}

int add(ArrayList* list, int pos, element item)
{
	if (!isFull(list) && (pos >= 0) && (pos <= list->length))
	{
		for (int i = list->length - 1; i >= pos; i--)
		{
			list->arr[i + 1] = list->arr[i];
		}
		list->arr[pos] = item;
		list->length++;
		return 0;
	}
	return 1;
}

element del(ArrayList* list, int pos)
{
	element item = list->arr[pos];
	if (!isEmpty(list) && (pos >= 0) && (pos < list->length))
	{
		for (int i = pos; i < list->length - 1; i++)
		{
			list->arr[i] = list->arr[i + 1];
		}
		list->length--;
		return item;
	}
}

int main(void)
{

	return 0;
}