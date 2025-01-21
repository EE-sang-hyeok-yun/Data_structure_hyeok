#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct stackNode
{
    element data;
    stackNode *link;
} stackNode;

typedef struct
{
    stackNode *top;

} stackType;

void init(stackType *sp)
{
    sp->top = NULL;
}
bool isEmpty(stackType *sp)
{
    return (sp->top == NULL);
}

void push(stackType *sp, element item)
{
    stackNode *newNode = (stackNode *)malloc(sizeof(stackNode));
    if (newNode == NULL)
    {
        printf("Error: Memory Allocation Error\n");
        exit(EXIT_FAILURE);
    }
    newNode->link = sp->top;
    newNode->data = item;
    sp->top = newNode;
    return;
}
element pop(stackType *sp)
{
    if (!isEmpty(sp))
    {
        element item = sp->top->data;
        stackNode *node = sp->top;
        sp->top = node->link;
        free(node);
        return item;
    }
    else
    {
        printf("Error: Stack is Empty");
        exit(EXIT_FAILURE);
    }
}
element peek(stackType *sp)
{
    if (!isEmpty(sp))
    {
        element item = sp->top->data;
        return item;
    }
    else
    {
        printf("Error: Stack is Empty");
        exit(EXIT_FAILURE);
    }
}
void display(stackType *sp)
{
    stackNode *node = sp->top;
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->link;
    }
    printf("\n");
    return;
}

int main(void)
{
    stackType stack;
    init(&stack);

    printf("Pushing elements onto the stack:\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);

    printf("\nPeeking the top element: %d\n", peek(&stack));

    printf("\nPopping elements from the stack:\n");
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    display(&stack);

    printf("\nPushing more elements onto the stack:\n");
    push(&stack, 40);
    push(&stack, 50);
    display(&stack);

    printf("\nPopping the remaining elements:\n");
    while (!isEmpty(&stack))
    {
        printf("Popped: %d\n", pop(&stack));
    }
    display(&stack);

    return 0;
}