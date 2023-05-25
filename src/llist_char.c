#include <stdio.h>
#include <stdlib.h>
typedef struct c_listnode
{
    char c_value;
    struct c_listnode *next;
} c_listnode;

c_listnode *c_list_createnode(char value) // Singly_listnode
{
    c_listnode *p;
    p = malloc(sizeof(c_listnode));
    if (p != NULL)
    {
        p->c_value = value;
        p->next = NULL;
    }
    return p;
}

c_listnode *c_list_addfront(c_listnode *list, char c_value)
{
    c_listnode *newnode;
    newnode = c_list_createnode(c_value);
    if (newnode != NULL)
    {
        newnode->next = list;
        return newnode;
    }
    return list;
}
