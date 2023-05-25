#include <stdio.h>
#include <stdlib.h>
#include "llist_num.h"
typedef struct n_stack
{
    n_listnode *top;
    int size;
} n_stack;
n_stack *stack_create_num()
{
    n_stack *s = malloc(sizeof(*s));
    if (s != NULL)
    {
        s->size = 0;
        s->top = NULL;
    }
    return s;
}
double stack_pop_num(n_stack *s)
{
    n_listnode *next;
    double value;
    if (s->top == NULL)
    {
        fprintf(stderr, "Stack underflow");
        return -1;
    }
    next = s->top->next;
    value = s->top->value;
    s->top = next;
    s->size += -1;
    return value;
}
void stack_free_num(n_stack *s)
{
    while (s->size > 0)
    {
        stack_pop_num(s);
    }
    free(s);
}
int stack_size_num(n_stack *s)
{
    return s->size;
}
int stack_push_num(n_stack *s, double value)
{
    s->top = n_list_addfront(s->top, value);
    if (s->top == NULL)
    {
        fprintf(stderr, "Stack overflow\n");
        return -1;
    }
    s->size += 1;
    return 0;
}
