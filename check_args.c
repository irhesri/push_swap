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
    t_list  *b;

    av++;
    if (ac == 2)
        av = ft_split(*av, ' ');
    if (!av)
        exit(0);
    while (*av)
    {
        b = initialise(my_atoi(*av));
        if (!int_check(*av) || duplicate_check(*a, b))
        {
            ft_putstr_fd("Error\n", 2);
            free(b);
            return (0);
        }
        my_push_back(a, b);
        av++;
    }
    return (1);
}