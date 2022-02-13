#include "push_swap.h"

static int node_position(t_list *a, int max, int min)
{
    int i;
    int t[4];
    
    i = 0;
    t[0] = 0;
    while (a)
    {
        if (a -> index <= max && a -> index >= min)
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

static void move_up(t_list **a, int i)
{
    while (i < 0)
    {
        my_push(a, my_pop_last(a));
        my_putstr("rra", 0);
        i++;
    }
    while (i >= 2)
    {
        my_push_back(a, my_pop(a));
        my_putstr("ra", 1);
        i--;
    }
}

static int	set_length(int size)
{
    static int k;
    static int x = 12;
    k++;
	if (size > 150)
		return (k * size / 18);
	return (k * x);
}

void    list_sort(t_list **a, t_list **b, int size)
{
    int i;
    int max; 
    int min;
    int x; 
    
    x = set_length(size); 
    max = size / 2 + x;
    min = size / 2 - x;
    i = node_position(*a, max, min);
    while (i)
    {
        move_up(a, i);
        my_push(b, my_pop(a));
        my_putstr("pb", 0);
        if ((*b) -> index < (size / 2))
        {
            my_push_back(b, my_pop(b));
            my_putstr("rb", 1);
        }
        i = node_position(*a, max, min);
    }
}

void    sort_3(t_list **a, int size)
{
    while (!my_issorted(*a))
    {
        if (size > 2 && (*a) -> data > (*a) -> next -> next -> data)
        {
            my_push_back(a, my_pop(a));
            my_putstr("ra", 1);
        }
        else
        {
            my_swap(a);
            my_putstr("sa", 2);
        }
    }
}
