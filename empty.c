#include "push_swap.h"

int max_index(t_list *a, int size)
{
    int i;
    static int b=0;
    int t[4] = {0};

    i = 0;

    t[3] = a -> data;
    t[1] = t[3];
    while (a -> next) /*** put it in another function***/
    {
        a = a -> next;
        i++;
        if (a -> data > t[3])
        {
            t[1] = t[3];
            t[0] = t[2];
            t[3] = a -> data;
            t[2] = i;
        }
        else if (a -> data > t[1])
        {
            t[1] = a -> data;
            t[0] = i;
        }
    }
    i++;
    if (t[2] > (size / 2 + 1))
        t[2] -= i;
    if (t[0] > (size / 2 + 1))
      t[0] -= i;
    if (!b && my_abs(t[0]) < my_abs(t[2]))
    {
        b = 1;
        return (t[0]);
    }
    b = 0;
    return (t[2]);
}

void    empty_b(t_list **a, t_list **b, int *size)
{
    int i;

    
        i = max_index(*b, *size);
       while (i < 0)
        {
            my_push(b, my_pop_last(b));
            my_putstr("rrb", 0);
            i++;
        }
        while (i >= 1)
        {
            my_push_back(b, my_pop(b));
            my_putstr("rb", 1);
            i--;
        }
        /*if (i == 1)
        {
            my_swap(b);
            my_putstr("sb", 2);
        }*/
        if ((*a) && (*a) -> next && (*a) -> data > (*a) -> next -> data)
        {
            my_swap(a);
            my_putstr("sa", 2);
        }
        my_push(a, my_pop(b));
        my_putstr("pa", 0);
        (*size)--;
}
