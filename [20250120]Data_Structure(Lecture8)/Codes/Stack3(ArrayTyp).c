#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct
{
    element *stack;
    int MAX_SIZE;
    int top;
} ArrayStack;

void init(ArrayStack *sp, int stackSize)
{
    element *stack = (element *)malloc(stackSize * sizeof(element));
    if (stack == NULL)
    {
        printf("Error: Memory Allocation Error\n");
        exit(EXIT_FAILURE);
    }
    sp->stack = stack;
    sp->MAX_SIZE = stackSize;
    sp->top = -1;
    return;
}
bool isEmpty(ArrayStack *sp)
{
    return (sp->top == -1);
}
bool isFull(ArrayStack *sp)
{
    return (sp->top == sp->MAX_SIZE - 1);
}
void push(ArrayStack *sp, element item)
{
    if (!isFull(sp))
    {
        sp->top++;
        sp->stack[sp->top] = item;
        return;
    }
    else
    {
        printf("Error: Stack is Full");
        exit(EXIT_FAILURE);
    }
}
element pop(ArrayStack *sp)
{
    if (!isEmpty(sp))
    {
        element item = sp->stack[sp->top];
        sp->top--;
        return item;
    }
    else
    {
        printf("Error: Stack is Empty");
        exit(EXIT_FAILURE);
    }
}
element peek(ArrayStack *sp)
{
    if (!isEmpty(sp))
    {
        return sp->stack[sp->top];
    }
    else
    {
        printf("Error: Stack is Empty");
        exit(EXIT_FAILURE);
    }
}
void display(ArrayStack *sp)
{
    for (int i = 0; i <= sp->top; i++)
    {
        printf("%d ", sp->stack[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    ArrayStack stack;
    init(&stack, 100);

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