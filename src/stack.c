#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initializeStack(Stack *stack)
{
    stack->top = NULL;
    stack->size = 0;
}

int isEmpty(const Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, double value)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL)
    {
        printf("Ошибка: Не удалось выделить память для нового элемента стека\n");
        return;
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

double pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Ошибка: Стек пуст\n");
        return 0;
    }

    StackNode *topNode = stack->top;
    double value = topNode->data;
    stack->top = topNode->next;
    free(topNode);
    stack->size--;

    return value;
}

double top(const Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Ошибка: Стек пуст\n");
        return 0;
    }

    return stack->top->data;
}

void freeStack(Stack *stack)
{
    while (!isEmpty(stack))
    {
        pop(stack);
    }
}
