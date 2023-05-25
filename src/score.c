#include "score.h"
#define RESET "\033[0m" /* White */
#define RED "\033[31m"  /* Red */
void priority(n_stack *num, c_stack *ops)
{
    if (ops->size != 0)
    {
        if (ops->top->value == '/' || ops->top->value == '*')
        {
            double tepm_1 = stack_pop_num(num);
            double tepm_2 = stack_pop_num(num);
            stack_pop_char(ops) == '/' ? stack_push_num(num, tepm_2 / tepm_1)
                                       : stack_push_num(num, tepm_2 * tepm_1);
        }
    }
}
void score_stack(n_stack *num, c_stack *ops)
{
    while (ops->size != 0 && num->size != 0)
    {
        double temp_1 = stack_pop_num(num);
        double temp_2 = stack_pop_num(num);
        stack_pop_char(ops);
        stack_push_num(num, temp_2 + temp_1);
    }
}
int add_ops_stack(char s, c_stack *ops, int *signal)
{
    if (s == '-')
    {
        *(signal) *= -1;
        return stack_push_char(ops, '+');
    }
    else
    {
        return stack_push_char(ops, s);
    }
}
int add_stack_sums(char *s, n_stack *num, c_stack *ops)
{
    unsigned int i = 0;
    int signal = 1;
    while (s[i] != '\n' && s[i] != '\0')
    {
        if (isdigit(s[i]))
        {
            if (stack_push_num(num, atof(s + i) * signal) != 0)
            {
                fprintf(stderr, RED "ERROR ADD IN STACK NUM\n" RESET);
                return -1;
            }
            signal = 1;
            priority(num, ops);
            while (isdigit(s[i]) || s[i] == '.')
                i++;
        }
        else if (s[i] == ' ')
        {
            i++;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if (add_ops_stack(s[i], ops, &signal) != 0)
            {
                fprintf(stderr, RED "ERROR ADD IN STACK CHAR\n" RESET);
                return -1;
            }
            i++;
        }
        else if (s[i] == '(')
        {
            if (stack_push_num(num, score(s + i + 1) * signal) != 0)
            {
                fprintf(stderr, "ERROR ADD IN STACK NUM\n");
                return -1;
            }
            signal = 1;
            i++;
            int scobka = 1;
            while (scobka != 0)
            {
                if (s[i] == '(')
                    scobka++;
                else if (s[i] == ')')
                    scobka--;
                i++;
            }
            priority(num, ops);
        }
        else if (s[i] == ')')
        {
            break;
        }
        else
        {
            fprintf(stderr, RED "ERROR!!! EXTRANEOUS SYMBOLS\n" RESET);
            return -1;
        }
    }
    return 0;
}

double score(char *s)
{
    n_stack *num = stack_create_num();
    c_stack *ops = stack_create_char();
    if (s == NULL)
    {
        fprintf(stderr, "ERROR\n");
        return 0;
    }
    if (add_stack_sums(s, num, ops) < 0)
    {
        fprintf(stderr, RED "ERROR IN ADDING STACK!!!\n" RESET);
        return -1;
    }
    double result = 0;
    score_stack(num, ops);
    result = num->top->value;
    stack_free_num(num);
    stack_free_char(ops);
    return result;
}
