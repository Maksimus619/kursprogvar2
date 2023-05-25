#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "llist_char.h"
#include "llist_num.h"
#include "ssll_char.h"
#include "ssll_num.h"
#include "syntax.h"
#define RESET "\033[0m"
#define RED "\033[31m" /* Red */
// double score_1(char* s);
// int add_stack_sums_1(char* s, n_stack* num, c_stack* ops);
void score_stack(n_stack *num, c_stack *ops);
void priority(n_stack *num, c_stack *ops);
int add_ops_stack(char s, c_stack *ops, int *signal);
double score(char *s);
int add_stack_sums(char *s, n_stack *num, c_stack *ops);
