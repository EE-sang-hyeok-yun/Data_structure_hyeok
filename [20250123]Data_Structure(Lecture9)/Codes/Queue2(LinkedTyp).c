#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct queueNode
{
    element data;
    queueNode *link;
} queueNode;
typedef struct
{
    queueNode *front;
    queueNode *rear;
    int cnt;
} queueType;

void init(queueType *queue);
bool isEmpty(queueType *queue);
void enqueue(queueType *queue, element item);
element dequeue(queueType *queue);
element peek(queueType *queue);

void init(queueType *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
    queue->cnt = 0;
    return;
}
bool isEmpty(queueType *queue)
{
    return (queue->cnt == 0);
}
void enqueue(queueType *queue, element item)
{
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
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
element dequeue(queueType *queue)
{
    if (isEmpty(queue))
        return 0;
    queueNode *node = queue->front;
    queue->front = node->link;
    element item = node->data;
    free(node);
    queue->cnt--;
    return item;
}
element peek(queueType *queue)
{
    if (isEmpty(queue))
        return 0;
    queueNode *node = queue->front;
    element item = node->data;
    return item;
}

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