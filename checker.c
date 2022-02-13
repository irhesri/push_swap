#include "push_swap.h"

void    switch_case(char *str, t_list **a, t_list **b)
{
    if (!my_strcmp(str, "sa\n") || !my_strcmp(str, "sb\n"))
        my_swap(a);
    else if (!my_strcmp(str, "pa\n") || !my_strcmp(str, "pb\n"))
        my_push(a, my_pop(b));
    else if (!my_strcmp(str, "ra\n") || !my_strcmp(str, "rb\n"))
        my_push_back(a, my_pop(a));
    else if (!my_strcmp(str, "rra\n") || !my_strcmp(str, "rrb\n"))
        my_push(a, my_pop_last(a));
    else if (!my_strcmp(str, "ss\n"))
    {
        my_swap(a);
        my_swap(b);
    }
    else if (!my_strcmp(str, "rr\n"))
    {
        my_push_back(a, my_pop(a));
        my_push_back(b, my_pop(b));
    }
    else if (!my_strcmp(str, "rrr\n"))
    {
        my_push(a, my_pop_last(a));
        my_push_back(b, my_pop_last(b));
    }
    else
    {
        ft_putstr_fd("Error\n", 2);
        exit (0);
    }
}

int main(int ac, char **av)
{
    t_list  *a;
    t_list  *b;
    int     size;
    char    *str;

    a = NULL;
    size = 0;
    //check typing errors duplicate number or non-digits 
    a = my_check(ac, av, &size);
    b = NULL;
    str = get_next_line(0);
    while (str)
    {
        if (str[1] == 'a' || str[2] == 'a')
            switch_case(str, &a, &b);
        else
            switch_case(str, &b, &a);
        free(str);
        str = get_next_line(0);
    }
    
    //my_print(a);

    if (my_issorted(a) && !b)
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);
    return (0);
}


