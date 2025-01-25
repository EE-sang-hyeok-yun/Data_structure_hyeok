#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct queueNode
{
    element data;
    queueNode *rightLink;
    queueNode *leftLink;
} queueNode;
typedef struct
{
    queueNode *front;
    queueNode *rear;
    int cnt;
} queueType;

void init(queueType *queue);
bool isEmpty(queueType *queue);
void addFront(queueType *queue, element item);
void addRear(queueType *queue, element item);
element delFront(queueType *queue);
element delrear(queueType *queue);

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
void addFront(queueType *queue, element item)
{
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
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
void addRear(queueType *queue, element item)
{
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
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
element delFront(queueType *queue)
{
    if (isEmpty(queue))
        return 0;
    queueNode *node = queue->front;
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
element delrear(queueType *queue)
{
    if (isEmpty(queue))
        return 0;

    queueNode *node = queue->rear;
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