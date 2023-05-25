#include <stdio.h>
#include <stdlib.h>
#include "llist_char.h"
typedef struct c_stack
{
    c_listnode *top;
    int size;
} c_stack;
c_stack *stack_create_char()
{
    c_stack *s = malloc(sizeof(*s));
    if (s != NULL)
    {
        s->size = 0;
        s->top = NULL;
    }
    return s;
}
char stack_pop_char(c_stack *s)
{
    c_listnode *next;
    char value;
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
void stack_free_char(c_stack *s)
{
    while (s->size > 0)
    {
        stack_pop_char(s);
    }
    free(s);
}
int stack_size_char(c_stack *s)
{
    return s->size;
}
int stack_push_char(c_stack *s, char value)
{
    s->top = c_list_addfront(s->top, value);
    if (s->top == NULL)
    {
        fprintf(stderr, "Stack overflow\n");
        return -1;
    }
    s->size += 1;
    return 0;
}
