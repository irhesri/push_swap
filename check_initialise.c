#include "push_swap.h"

static	int	duplicate_check(t_list *a, t_list *new)
{
	while (a)
	{
		if (a -> data == new -> data)
			return (1);
		a = a -> next;
	}
	return (0);
}

t_list	*my_check(int ac, char **av, int *size)
{
	t_list  *a;
	t_list  *b;

	av++;
	if (ac == 2)
		av = ft_split(*av, ' ');
	if (!av)
		exit (0);
	a = NULL;
	while (*av)
	{
		b = initialise(my_atoi(*av++));
		if (duplicate_check(a, b))
		{
			ft_putstr_fd("Error\n", 2);
			exit (0);
		}
		my_push_back(&a, b);
		(*size)++;
	}
	if (!a)
		exit(0);
	return (a);
}

void	put_index(t_list *a, int size)
{
	int		i;
	t_list	*min;
	t_list	*check;

	i = 0;
	while (i < size)
	{
		min = a;
		check = a -> next;
		while (check)
		{
			if ((!check -> index && min -> data > check -> data) 
				|| (min -> index))
				min = check;
            check = check -> next;
        }
		min -> index = ++i;
	}
}
