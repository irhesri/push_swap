#include "push_swap.h"

static void    my_rsort(t_list **b, int *lastb)
{
    int data;

    if (!(*b) || !(*b) -> next)
        return ;
    data = (*b) -> data;
    // top smaller than last node
    if (data < (*lastb))
    {
        my_push_back(b, my_pop(b)); //rotate
        my_putstr("rb", 1);
        (*lastb) = data;
    }
    // top smaller than second node
    else if (data < (*b) -> next -> data)
    {
        my_swap(b);
        my_putstr("sb", 2);
        if (!((*b) -> next -> next))
            (*lastb) = ((*b) -> next -> data);
    }
}

// rev rotate a - make the last node the top 
static void    last_is_min(t_list **a, int *lasta)
{
    int min;

    my_push(a, my_pop_last(*a)); //rrotate
    my_putstr("rra", 0);
    (*lasta) = min_last(*a, &min); // min won't change anyway 
}
// rotate a - make the top the last node 
static void    top_is_bigger(t_list **a, int *lasta)
{
    int data;

    data = (*a) -> next -> data;
    if (data > (*lasta) && data < (*a) -> data  
        && (*a) -> next -> next && (*a) -> next -> next -> next) // size a > 3
    {
        my_swap(a);
        my_putstr("sa", 2);
    }
    (*lasta) = (*a) -> data;
    my_push_back(a, my_pop(a));
    my_putstr("ra", 1);
}
// push in b
static void    no_move(t_list **a, t_list **b, int *lastb, int *min)
{
    if (!(*b))
        (*lastb) = (*a) -> data;
    my_push(b, my_pop(a));
    my_putstr("pb", 0);
    my_rsort(b, lastb);
    min_last(*a, min);
}

void    my_sort(t_list **a, t_list **b, int *lasta, int *lastb)
{
    static int min = 2147483647;

    if (min == 2147483647)
        (*lasta) = min_last(*a, &min);
    // last node has the min & list size > 3
    if (min == (*lasta) && (*a) -> next -> next && (*a) -> next -> next -> next)
        last_is_min(a, lasta);
    // top bigger than last node 
    else if ((*a) -> data > (*lasta))
        top_is_bigger(a, lasta);
    // top bigger than second node  
    else if ((*a) -> data > (*a) -> next -> data)
    {
        my_swap(a);
        my_putstr("sa", 2);
    }
    // no move - couldn't swap or rotate or rev rotate a
    else
        no_move(a, b, lastb, &min);
}