#ifndef STACK_H
#define STACK_H

typedef struct StackNode
{
    double data;
    struct StackNode *next;
} StackNode;

typedef struct
{
    StackNode *top;
    int size;
} Stack;

void initializeStack(Stack *stack);
int isEmpty(const Stack *stack);
void push(Stack *stack, double value);
double pop(Stack *stack);
double top(const Stack *stack);
void freeStack(Stack *stack);

#endif // STACK_H
