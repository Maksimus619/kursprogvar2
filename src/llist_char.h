typedef struct c_listnode
{
    char value;
    struct c_listnode *next;
} c_listnode;
c_listnode *c_list_createnode(char value);
c_listnode *c_list_addfront(c_listnode *list, char c_value);
