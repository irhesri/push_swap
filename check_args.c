#include "push_swap.h"

static  int my_isdigit(int n)
{
    return (n >= '0' && n <= '9');
}

static int int_check(char *str)
{
    int i;

    i = 0;
    while (str[i] || i == 0)
    {
        if (!my_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

static int duplicate_check(t_list *a, t_list *new)
{
    while (a)
    {
        if (a -> data == new -> data)
            return (1);
        a = a -> next;
    }
    return (0);
}

int my_check(int ac, char **av, t_list  **a)
{
    int i;
    int     j;
    t_list  *b;

    i = 1;
    while (i < ac)
    {
        b = initialise(my_atoi(av[i]));
        if (!int_check(av[i]) || duplicate_check(*a, b))
        {
            ft_putstr_fd("Error\n", 1);
            return (0);
        }
        my_push_back(a, b);
        i++;
    }
    return (1);
}