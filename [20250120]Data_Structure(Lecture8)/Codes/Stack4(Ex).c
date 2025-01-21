#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char element;
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
        printf("%c ", sp->stack[i]);
    }
    printf("\n");
    return;
}
void freeStack(ArrayStack *sp)
{
    if (sp->stack != NULL)
    {
        free(sp->stack);
    }
    sp->stack = NULL;
    sp->top = -1;
    sp->MAX_SIZE = 0;
}

int parentheses(void)
{
    ArrayStack stack;
    init(&stack, 50);

    char *str = (char *)malloc((51) * sizeof(char));
    if (str == NULL)
        return 1;
    scanf("%s", str);
    size_t len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        switch (str[i])
        {
        case '(':
        case '{':
        case '[':
            push(&stack, str[i]);
            break;
        case ')':
        case '}':
        case ']':
            if (isEmpty(&stack))
            {
                free(str);
                freeStack(&stack);
                return 1;
            }
            else
            {
                element temp = pop(&stack);
                if (((str[i] == ')') && (temp != '(')) || ((str[i] == '}') && (temp != '{')) || ((str[i] == ']') && (temp != '[')))
                {
                    free(str);
                    freeStack(&stack);
                    return 1;
                }
                break;
            }
        }
    }
    if (isEmpty(&stack))
    {
        free(str);
        freeStack(&stack);
        return 0;
    }
    else
    {
        free(str);
        freeStack(&stack);
        return 1;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        if (!parentheses())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}