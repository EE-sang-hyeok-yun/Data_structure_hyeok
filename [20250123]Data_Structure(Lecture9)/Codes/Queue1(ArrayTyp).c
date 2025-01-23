#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;

typedef struct
{
    element arrQ[MAX_SIZE];
    int front;
    int rear;
} queueType;

void init(queueType *queue)
{
    queue->front = queue->rear = 0;
    return;
}
bool isEmpty(queueType *queue)
{
    return (queue->front == queue->rear);
}
bool isFull(queueType *queue)
{
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}
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
element peek(queueType *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return 0;
    }
    return queue->arrQ[queue->front + 1];
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