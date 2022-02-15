#include "push_swap.h"

static int node_position(t_list *a, int max, int min)
{
    int i;
    int position;
    
    i = 0;
    position = 0;
    while (a)
    {
        if (a -> index <= max && a -> index >= min)
        {
            position = i + 1;
            break;
        }
        i++;
        a = a -> next;
    }
    if (!position)
        return (0);
    return (position);
}

static int	set_length(int size)
{
    static int k;
    static int x;

    k++;
    if (!x && size < 150)
        x = 12;
    else if (!x)
        x = 20;
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
        while (i >= 2)
        {
            my_push_back(a, my_pop(a));
            my_putstr("ra", 1);
        i--;
        }
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
