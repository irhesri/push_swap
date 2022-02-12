#include "push_swap.h"

int node_index(t_list *a, int max)
{
    int i;
    int t[4];
    
    i = 0;
    t[0] = 0;
    while (a)
    {
        if (a -> index <= max)
        {
            if (!t[0])
            {
                t[0] = i + 1;
                t[1] = a -> data;
            }
            t[2] = i;
            t[3] = a -> data;
        }
        i++;
        a = a -> next;
    }
    if (!t[0])
        return (0);
    t[2] -= i;
    if ((my_abs(t[0]) - 1) == my_abs(t[2]))
        return ((t[0] * (t[1] <= t[3])) + (t[2] * (t[1] > t[3])));
    i = t[2] * -1;
    i = t[0] * (i >= t[0]) + t[2] * (i < t[0]);
    return (i);
}

static void move_up(t_list **a, int *size, int i)
{
    while (i < 0)
    {
        my_push(a, my_pop_last(a, size), size);
        my_putstr("rra", 0);
        i++;
    }
    while (i > 2)
    {
        my_push_back(a, my_pop(a, size), size);
        my_putstr("ra", 1);
        i--;
    }
    if (i == 2)
    {
        my_swap(a);
        my_putstr("sa", 2);
    }
}

void    list_sort(t_list **a, t_list **b, int *size)
{
    int i;
    int x;

    while (size[0] > 3)
    {
        x = max_value(size);
        i = node_index(*a, x);
        while (i)
        {
            move_up(a, size, i);
            my_push(b, my_pop(a, size), size + 1);
            my_putstr("pb", 0);
            i = node_index(*a, x);
        }
    }
}

void    sort_3(t_list **a, int *size)
{
    while (!my_issorted(*a))
    {
        if (*size > 2 && (*a) -> data > (*a) -> next -> next -> data)
        {
            my_push_back(a, my_pop(a, size), size);
            my_putstr("ra", 1);
        }
        else
        {
            my_swap(a);
            my_putstr("sa", 2);
        }
    }
}