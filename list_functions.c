#include "push_swap.h"

//initialise a node
t_list  *initialise(int data)
{
    t_list *lst;
    lst = malloc(sizeof(t_list));
    if (!lst)
        return (NULL);
    (lst -> data) = data;
    lst -> next = NULL; 
    return (lst);
}

void    my_push(t_list **list, t_list *new)
{
    if (!new)
        return ;
    new -> next = *list;
    *list = new;
}

void    my_push_back(t_list **list, t_list *new)
{
    t_list *lst;

    if (!new)
        return ;
    if (!*list)
    {
        *list = new;
        return ;
    }
    lst = *list;
    while (lst -> next)
        lst = lst -> next;
    lst -> next = new;
}
//remove and return front 
t_list  *my_pop(t_list **list) 
{
    t_list *lst;

    lst = *list;
    if (!lst)
        return (NULL);
    *list = (*list) -> next;
    lst -> next = NULL;
    return (lst);
}
//swap 2 top elements
// void    my_swap(t_list **list)
// {
//     t_list  *pop1;
//     t_list  *pop2;

//     pop1 = my_pop(list);
//     pop2 = my_pop(list);
//     my_push(list, pop1);
//     my_push(list, pop2);
// }
void    my_swap(t_list **list)
{
    t_list *lst;

    lst = *list;
    if (!lst || !lst -> next)
        return ;
    *list = (*list) -> next;
    lst -> next = (*list) -> next;
    (*list) -> next = lst;
}

// void    my_rotate(t_list **list)
// {
//     my_push_back(list, my_pop(list));
// }

//rotate a list  rra
void    my_rrotate(t_list **list)
{
    t_list *lst;
    t_list  *pop;

    lst = *list;
    if (!lst || !(lst -> next))
        return ;    
    while(lst -> next -> next)
        lst = lst -> next;
    pop = lst -> next;
    lst -> next = NULL;
    my_push(list, pop);
}
//check if list is sorted
int my_issorted(t_list *lst)
{
    while (lst -> next)
    {
        if (lst -> data > lst -> next -> data)
            return (0);
        lst = lst -> next;
    }
    return (1);
}

int min_last(t_list *list, int *min)
{
    int i ;
    int last;
    
    i = list -> data;
    last = i;
    while (list -> next)
    {
        list = list -> next;
        i = ((i * (i < list -> data)) + (list -> data * (i > list -> data))); //min of i & last->data
        last = list -> data;
    }
    (*min) = i;
    return (last);
}