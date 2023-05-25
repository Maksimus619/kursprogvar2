typedef struct c_stack
{
    c_listnode *top;
    char size;
} c_stack;
c_stack *stack_create_char();
void stack_free_char(c_stack *s);
int stack_size_char(c_stack *s);
int stack_push_char(c_stack *s, char value);
char stack_pop_char(c_stack *s);
