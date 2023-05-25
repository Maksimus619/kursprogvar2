typedef struct n_stack
{
    n_listnode *top;
    int size;
} n_stack;
n_stack *stack_create_num();
void stack_free_num(n_stack *s);
int stack_size_num(n_stack *s);
int stack_push_num(n_stack *s, double value);
double stack_pop_num(n_stack *s);
