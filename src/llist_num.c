#include <stdio.h>
#include <stdlib.h>
typedef struct n_listnode
{
    double n_value;
    struct n_listnode *next;
} n_listnode;
n_listnode *n_list_createnode(double value)
{
    n_listnode *p;
    p = malloc(sizeof(n_listnode));
    if (p != NULL)
    {
        p->n_value = value;
        p->next = NULL;
    }
    return p;
}
n_listnode *n_list_addfront(n_listnode *list, double n_value)
{
    n_listnode *newnode;
    newnode = n_list_createnode(n_value);
    if (newnode != NULL)
    {
        newnode->next = list;
        return newnode;
    }
    return list;
}
