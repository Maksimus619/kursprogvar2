typedef struct n_listnode
{
    double value;
    struct n_listnode *next;
} n_listnode;
n_listnode *n_list_createnode(double value);
n_listnode *n_list_addfront(n_listnode *list, double value);
